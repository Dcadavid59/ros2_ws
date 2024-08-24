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
        self.flag_pick = False                          # habilita rutina pick

        self.flag_uno = True                            # habilita inicio de barrido
        self.flag_barrido = False                       # habilita rutina de barrido

        self.flag_pose_origen = True                    # lleva el brazo a posición origen
        self.flag_pose_barrido = True                   # lleva el brazo a posición barrido

        self.pos_origen  = [0, 0, 0, 0, 0, 0]

        # barrido sin pinza
    #    self.pos_init_barrido = [90.0, 87.0, 0.0, 94.0, 84.0, 44.0]
    #    self.pos_fin_barrido = [-80.0, 87.0, 0.0, 94.0, 84.0, 44.0]

        # barrido con pinza
        self.pos_init_barrido = [60.0, 82.0, 10.0, 84.0, -25.0, -50.0]
        self.pos_fin_barrido = [-60.0, 82.0, 10.0, 84.0, -25.0, -50.0]

        # subscripción de topicos aruco_marker
        self.subscription = self.create_subscription(
            MyArucoCoords, 'marker_data', self.callback_aruco, 10)
        
        # velocidad ciclo principal
        self.rutina_ = self.create_timer(0.1, self.callback_rutina)
        self.get_logger().info("rutina3 has been started.")
    
 
    def callback_aruco(self, msg):
        self.aruco = msg


    def callback_rutina(self): 

    # rutina pick                                          *************************************************************************************
        if self.flag_pick == True:
            self.get_logger().info("%s" % (self.pose_aruco))
            self.get_logger().info("%s" % (self.pose_brazo))
            self.get_logger().info("%s" % (self.coords_brazo))

        """
        Coordenadas detección_brazo: [-258.7, -44.4, 63.3, 87.25, 50.45, -75.31]
        Angulos detección_brazo: [-8.43, 83.49, 10.54, 84.02, -25.04, -49.65]

        Coordenada objetivo_brazo: [-279.7, 11.8, 38.0, -176.0, -1.57, -41.01]
        Angulos objetivo_brazo: [-281.5, 9.4, 40.0, -179.58, -2.24, -41.06]

        Coordenadas de lectura marca_aruco: [22.9, 13.2, 133.0, distance 42.9]
        
        """

    # rutina de barrido                                    *************************************************************************************

    # ¿se cumplio la posición inicial de barrido?
        if self.flag_barrido == True:
            # ¿es el primer barrido?
            if self.flag_uno == True:
               # self.angulo = 80    # angulo sin pinza
                self.angulo =60

        # incremento del barrido
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
                    self.pose_brazo = self.mc.get_angles()  # ¿necesario?
                    self.coords_brazo = self.mc.get_coords()
                    self.pose_aruco = self.aruco
                    self.flag_barrido = False               # finaliza el barrido
                    self.flag_pick = True                   # inicia rutina pick
                    self.angulo = self.pose_brazo[0]
                else:
                    angulos = self.mc.get_angles()
            
            self.flag_uno = False
            self.angulo -= 5

            # reiniciar barrido
            if self.mc.is_in_position(self.pos_fin_barrido, 0) == True:
                self.flag_uno = True                # inicia primer posición barrido
                self.flag_barrido = False           # finaliza el barrido
                self.flag_pose_barrido = True       # vuelve a la posición de origen


    # Posicion origen
        if self.flag_pose_origen == True:
            while not self.mc.is_in_position(self.pos_origen, 0):
                self.mc.send_angles(self.pos_origen, 40)
            
            self.flag_pose_origen = False


    # Posicion inicial barrido
        if self.flag_pose_barrido == True:
            while not self.mc.is_in_position(self.pos_init_barrido, 0):
                self.mc.send_angles(self.pos_init_barrido, 40)
            
            self.flag_barrido = True
            self.flag_pose_barrido = False




def main(args=None):
    rclpy.init(args=args)
    node = Rutina_3()
    
    try:
        rclpy.spin(node)
    except SystemExit:                 # <--- process the exception 
        rclpy.logging.get_logger("Quitting").info('Done')

    node.destroy_node()
    rclpy.shutdown()