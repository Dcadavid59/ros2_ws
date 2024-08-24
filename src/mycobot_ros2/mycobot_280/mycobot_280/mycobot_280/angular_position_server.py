#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from pymycobot.mycobot import MyCobot

from mycobot_interfaces.srv import SetAngles


class AngularPositionServerNode(Node):
    def __init__(self):
        super().__init__("angular_position_server")
        self.mc = MyCobot('/dev/ttyACM0', '115200')
        self.get_logger().info("port:%s, baud:%d" %('ttyACM0',115200))
        
        self.server_ = self.create_service(
            SetAngles, "Default_angular__position", self.callback_position)
        self.get_logger().info("Default angular position server has been started.")

    def callback_position(self, request, response):
        rotation = [request.joint_1, request.joint_2, request.joint_3, request.joint_4, request.joint_5, request.joint_6]
        self.get_logger().info("%s" % (rotation))
        
        while not (self.mc.is_in_position(rotation, 0)):
            self.mc.send_angles(rotation, request.speed)
            response.flag = True

        self.get_logger().info("%s" %(self.mc.get_angles))
        
        return(response)


def main(args=None):
    rclpy.init(args=args)
    node = AngularPositionServerNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()