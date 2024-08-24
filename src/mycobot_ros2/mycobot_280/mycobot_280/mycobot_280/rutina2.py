#!/usr/bin/env python3

import time
import rclpy
from rclpy.node import Node
from pymycobot.mycobot import MyCobot
from mycobot_interfaces.msg import MyArucoCoords



class Rutina_3(Node):
    def __init__(self):
        super().__init__("rutina")
        self.mc = MyCobot('/dev/ttyACM0', '115200')
        self.get_logger().info("port:%s, baud:%d" % ('ttyACM0',115200))
        time.sleep(0.05)

        # Inicializar variables y banderas
        self.flag_uno = True                            # habilita inicio de barrido
        self.flag_barrido = False                       # habilita rutina de barrido
        self.flag_pick_place = False                    # habilita rutina pick and place
        self.flag_cierre_pinza = False                  # habilita cierre pinza

        self.flag_pose_origen = True                    # lleva el brazo a posición origen
        self.flag_pose_barrido = False                  # lleva el brazo a posición barrido

        self.flag_pose_objetivo = False                 # habilita la rutina pick
        self.flag_place = False                         # habilita la rutina place
        self.flag_pose_pick = False                     # lleva al brazo a la posición pick
        self.flag_pose_place = False                    # lleva el brazo a la posición place   
        self.flag_pose_intermedia = False               # lleva el brazo a posición de pick a place      

        
        self.pos_origen  = [0, 0, 0, 0, 0, 0]

        # barrido con pinza
        self.pos_init_barrido = [50, 58, 60, 55, -28, -44]
        self.pos_fin_barrido =  [-70, 58, 60, 55, -28, -44]
  
        # posición pick and place
        self.pose_pick  = [-7.99, 105.2, 19.59, -74.0, 123.75, -91.66]      # ajustar pick
        self.pose_intermedia = [25.13, 61.25, 20.74, 1.49, 96.41, -50.53]
        self.pose_place = [36.47, 89.03, 20.65, 75.58, 3.25, 47.28]         # ajustar place

        # subscripción de topicos aruco_marker
        self.subscription = self.create_subscription(
            MyArucoCoords, 'marker_data', self.callback_aruco, 10)
        
        # velocidad ciclo principal
        self.rutina_ = self.create_timer(0.1, self.callback_rutina)
        self.get_logger().info("rutina3 has been started.")
    
 
    def callback_aruco(self, msg):
        self.aruco = msg


    def callback_rutina(self): 

    # rutina pick_place                                          *************************************************************************************

        if self.flag_pick_place == True:
            # while not pose origen ¿?
            time.sleep(0.5)
            self.apertura = self.mc.get_gripper_value()
            print(self.apertura)
            
            # rutina pick
            if self.flag_pose_objetivo == True:    
                while not self.apertura >= 70:                  # validar apertura pinza
                    self.mc.set_gripper_value(80, 40)   
                    time.sleep(0.5)         
                    self.apertura = self.mc.get_gripper_value()
                    print(f'{self.apertura} 2')

                self.flag_pose_objetivo = False
                self.flag_pose_pick = True


            if self.flag_cierre_pinza == True:
                    while not 46 <= self.apertura <= 50:            # Validar cierre  
                        self.mc.set_gripper_value(48, 80)          
                        time.sleep(0.5)      
                        self.apertura = self.mc.get_gripper_value()

                    if self.apertura <= 48:  
                        self.flag_pose_pick = False                 # invalida posición pick
                        self.flag_cierre_pinza = False              # finaliza cierre de pinza
                        self.flag_pose_objetivo = False             # cierra ciclo pick  
                        self.flag_pose_intermedia = True            # habilita posición media
                        print(f'{self.apertura} 3')
            
            # rutina place
            
            if self.flag_place == True:
                while not self.apertura >= 70:                      # validar apertura pinza
                    self.mc.set_gripper_value(80, 60)   
                    time.sleep(1)         
                    self.apertura = self.mc.get_gripper_value()
                    print(f'{self.apertura} 4')
            
                time.sleep(1.5)
                if self.apertura >= 70:
                    print('Ok')
                    self.flag_place = False                         # cierra rutina place
                    self.flag_pick_place = False                    # cierra rutina pick and place
                    self.flag_pose_origen = True                  # vuelve al origen


    # rutina de barrido                                    *************************************************************************************

    # ¿se cumplio la posición inicial de barrido?
        if self.flag_barrido == True:
            # ¿es el primer barrido?
            if self.flag_uno == True:
                self.angulo = 50

        # incremento del barrido
            self.flag_uno = False
            self.mc.send_angle(1, self.angulo, 5)
            time.sleep(0.5)
            angulos = self.mc.get_angles()
            self.get_logger().info("angulo seteado: %s" % (angulos))

            # evaluar posicion
            while not (round(angulos[0])-1 <= self.angulo <= round(angulos[0])+1):
                self.get_logger().info("angulo seteado %s, angulo operacional %s" %(self.angulo, angulos))
                
                # Actualizar lectura del aruco
                self.get_logger().info("%s" % (self.aruco.flag))
                
                if self.aruco and self.aruco.flag == True:
                    self.coords_brazo = self.mc.get_coords()    # guarda coordenadas del brazo
                    self.pose_aruco = self.aruco                # guarda posición leida de la marca
                    self.flag_barrido = False                   # finaliza el barrido
                    self.flag_pose_origen = True                # inicia en posición de origen
                    self.flag_pick_place = True                 # inicia rutina pick
                    self.flag_pose_objetivo = True              # lleva a la posición pick

                    angulos = self.mc.get_angles()              # cierra ciclo while
                else:
                    angulos = self.mc.get_angles()              # cierra ciclo while
            
            self.angulo -= 5

            # reiniciar barrido                             
            if self.mc.is_in_position(self.pos_fin_barrido, 0) == True:
                self.flag_uno = True                # inicia primer posición barrido
                self.flag_barrido = False           # finaliza el barrido
                self.flag_pose_barrido = True       # vuelve a la posición de origen




    # Posicion inicial barrido                              *************************************************************************************
        if self.flag_pose_barrido == True:
            print('barrido')
            while not self.mc.is_in_position(self.pos_init_barrido, 0):
                self.mc.send_angles(self.pos_init_barrido, 20)
            
            self.flag_pose_barrido = False
            if self.flag_pick_place == False:
                self.flag_barrido = True


    # Posicion origen                                       *************************************************************************************
        if self.flag_pose_origen == True:
            print('origen')
            while not self.mc.is_in_position(self.pos_origen, 0):
                self.mc.send_angles(self.pos_origen, 50)
            
            self.flag_pose_origen = False
            if self.flag_pick_place == False:
                self.flag_pose_barrido = True


    # Posición pick                                         *************************************************************************************
        if self.flag_pose_pick == True:
            print('pick')
            while not self.mc.is_in_position(self.pose_pick, 0):
                self.mc.send_angles(self.pose_pick, 20)
            
            self.flag_pose_pick = False
            self.flag_cierre_pinza = True
            time.sleep(1)


    # Posición place                                        *************************************************************************************
        if self.flag_pose_place == True:
            print('place')
            while not self.mc.is_in_position(self.pose_place, 0):
                self.mc.send_angles(self.pose_place, 20)

            self.flag_pose_place = False
            self.flag_place = True
            time.sleep(1)


    # Posición intermedia                                   *************************************************************************************
        if self.flag_pose_intermedia == True:
            print('intermedio')
            while not self.mc.is_in_position(self.pose_intermedia, 0):
                self.mc.send_angles(self.pose_intermedia, 30)

            self.flag_pose_intermedia = False
            self.flag_pose_place = True



def main(args=None):
    rclpy.init(args=args)
    node = Rutina_3()
    
    try:
        rclpy.spin(node)
    except SystemExit:                 # <--- process the exception 
        rclpy.logging.get_logger("Quitting").info('Done')

    node.destroy_node()
    rclpy.shutdown()


"""
Coordenadas detección_brazo: [-258.7, -44.4, 63.3, 87.25, 50.45, -75.31]
Angulos detección_brazo: [-8.43, 83.49, 10.54, 84.02, -25.04, -49.65]

Coordenada objetivo_brazo: [-279.7, 11.8, 38.0, -176.0, -1.57, -41.01]
Angulos objetivo_brazo: [-281.5, 9.4, 40.0, -179.58, -2.24, -41.06]

Coordenadas de lectura marca_aruco: [22.9, 13.2, 133.0, distance 42.9]

valor de sujeción del griper en el cuello de la botella: 41
"""

"""
# [-49.3, 98.96, 0.61, 39.72, -82.26, -21.09] Izq
# [-42.53, 100.1, 0.52, -2.19, 179.38, -26.98]
# [-15.11, 104.32, 0.52, -15.46, 179.29, 28.21] Der (no trabaja)
self.pose_pick = [-15.0, 97.2, 10.28, -15.29, -179.4, 116.0]
self.pose_place = [29.44, 100.01, 0.17, -7.03, 177.36, -41.01]
"""

""" Posiciones de barrido configuración anterior
self.pos_init_barrido = [60.0, 82.0, 10.0, 84.0, -25.0, -50.0]
self.pos_fin_barrido = [-60.0, 82.0, 10.0, 84.0, -25.0, -50.0]
"""


# barrido sin pinza
#self.pos_init_barrido = [90.0, 87.0, 0.0, 94.0, 84.0, 44.0]
#self.pos_fin_barrido = [-80.0, 87.0, 0.0, 94.0, 84.0, 44.0]

# self.angulo = 80    # angulo sin pinza