#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from mycobot_interfaces.msg import MyArucoCoords


class SmartphoneNode(Node):
    def __init__(self):
        super().__init__("prueba")
        self.subscriber_ = self.create_subscription(
            MyArucoCoords, "marker_data", self.callback_robot_news, 10)
        self.get_logger().info("prueba subscrition has been started.")

        self.timer_ = self.create_timer(0.1, self.mainloop)    # nueva

    def callback_robot_news(self, msg):
        print(f'Mensaje callback: {msg}')
        self.mensaje = msg

    def mainloop(self):
        #print(f'Mensaje ciclo principal: {self.mensaje}')
        print(self.mensaje.flag)

def main(args=None):
    rclpy.init(args=args)
    node = SmartphoneNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
