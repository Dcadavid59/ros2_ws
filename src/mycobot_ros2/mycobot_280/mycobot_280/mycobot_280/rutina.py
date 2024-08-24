#!/usr/bin/env python3

import time
import rclpy
from functools import partial
from rclpy.node import Node
from pymycobot.mycobot import MyCobot

from mycobot_interfaces.srv import SetAngles


class Rutina_1(Node):
    def __init__(self):
        super().__init__("rutina_1")
        self.mc = MyCobot('/dev/ttyACM0', '115200')
        self.get_logger().info("port:%s, baud:%d" % ('ttyACM0',115200))
        time.sleep(0.05)

        self.rutina_ = self.create_timer(0.01, self.callback_rutina)


  # posicionamiento del brazo
    def call_angular_position_server(self, joint_1, joint_2, joint_3, joint_4, joint_5, joint_6, speed):
        client = self.create_client(SetAngles, "Default_angular__position")
        while not client.wait_for_service(1.0):
            self.get_logger().warn("Waiting for Server...")

        request = SetAngles.Request()
        request.joint_1 = joint_1
        request.joint_2 = joint_2
        request.joint_3 = joint_3
        request.joint_4 = joint_4
        request.joint_5 = joint_5
        request.joint_6 = joint_6
        request.speed = speed

        future = client.call_async(request)
        future.add_done_callback(
            partial(self.callback_angular_position, joint_1=joint_1, joint_2=joint_2, joint_3=joint_3, joint_4=joint_4, joint_5=joint_5, joint_6=joint_6, speed=speed))

    def callback_angular_position(self, future, joint_1, joint_2, joint_3, joint_4, joint_5, joint_6, speed):
        try:
            response = future.response()
            self.get_logger().info("%s" %(response))
        
        except Exception as e:
            self.get_logger().error("Service call failed %r" % (e,))
        

  # rutina de barrido:
    def callback_rutina(self):
        while not self.call_angular_position_server(90.0, 87.0, 0.0, 94.0, 84.0, 44.0, 40) == True:
            print("todo melo")

            # no sale del ciclo
            # siempre es verdadero sin esperar a que termine el movimiento, llama a la siguiente acción: ¿como detenerlo?

        # iniciar barrido
        self.mc.send_angle(1, -80, 5)

        # detener barrido
        flag = False
        if flag == True:
            self.mc.pause()
            self.get_logger().info("Aqui PARAR")
            raise SystemExit
        

def main(args=None):
    rclpy.init(args=args)
    node = Rutina_1()
    
    try:
        rclpy.spin(node)
    except SystemExit:                 # <--- process the exception 
        rclpy.logging.get_logger("Quitting").info('Done')

    node.destroy_node()
    rclpy.shutdown()