import rclpy
from pymycobot.mycobot import MyCobot
from rclpy.node import Node
from sensor_msgs.msg import JointState
import time


class Pos_origen(Node):
    def __init__(self):
        super().__init__("origen")
        self.mc = MyCobot('/dev/ttyACM0', '115200')
        self.get_logger().info("port:%s, baud:%d" % ('ttyACM0',115200))
        time.sleep(0.05)

        self.lim_inf = [-0.5, -0.5, -0.5, -0.5, -0.5, -0.5]
        self.lim_sup = [0.5, 0.5, 0.5, 0.5, 0.5, 0.5]

        timer_period = 1
        self.timer = self.create_timer(
            timer_period, self.listener_callback)
        self.get_logger().info("Origen node has been started.")

    def listener_callback(self):
        angle_datas = self.mc.get_angles()
        print(angle_datas)
        time.sleep(0.5)
        self.mc.send_angles([0, 0, 0, 0, 0, 0], 40)
        print(f"mycobot esta pausado = {self.mc.is_paused()}")
        time.sleep(1.5)
        for valor, limite_inferior, limite_superior in zip(angle_datas, self.lim_inf, self.lim_sup):
            if (limite_inferior <= valor <= limite_superior):
                raise SystemExit
            

def main(args=None):
    rclpy.init(args=args)
    pos_origen = Pos_origen()
    
    try:
        rclpy.spin(pos_origen)
    except SystemExit:                 # <--- process the exception 
        rclpy.logging.get_logger("Quitting").info('Done')

    pos_origen.destroy_node()
    rclpy.shutdown()