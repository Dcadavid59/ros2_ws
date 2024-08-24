#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from functools import partial
from pymycobot.mycobot import MyCobot

from mycobot_interfaces.srv import SetAngles

class BarridoClientNode(Node):
    def __init__(self):
        super().__init__("barrido_client")
        self.mc = MyCobot('/dev/ttyACM0', '115200')
        self.get_logger().info("port:%s, baud:%d" %('ttyACM0',115200))

        self.call_angular_position_server[90.0, 87.0, 0.0, 94.0, 84.0, 44.0, 40]

    # Aquí se puede agregar el subscritor al mensaje:

    def call_angular_position_server(self, joint_1, joint_2, joint_3, joint_4, joint_5, joint_6, speed):
        client = self.create_client(SetAngles, "Default_angular__position")
        while not client.wait_for_service(1.0):
            self.get_logger().warn("Waiting for angular_position_service...")

        request = SetAngles.Request()
        request.joint_1 = joint_1
        request.joint_2 = joint_2
        request.joint_3 = joint_3
        request.joint_4 = joint_4
        request.joint_5 = joint_5
        request.joint_6 = joint_6
        request.speed   = speed

        future = client.call_async(request)
        future.add_done_callback(
            partial(self.callback_call_angular_position, joint_1=joint_1, joint_2=joint_2,
                    joint_3=joint_3, joint_4=joint_4, joint_5=joint_5, joint_6=joint_6, speed=speed))
        
    def callback_call_angular_position(self, future, joint_1, joint_2, joint_3, joint_4, joint_5, joint_6, speed):
        try:
            response = future.result()
            self.get_logger().info("%s, %s, %s, %s, %s, %s" % (joint_1, joint_2, joint_3, joint_4, joint_5, joint_6, speed))

            # Activar rutina de barrido

            
            
        except Exception as e:
            self.get_logger().error("Service call failed %r" % (e,))


def main(args=None):
    rclpy.init(args=args)
    node = BarridoClientNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()