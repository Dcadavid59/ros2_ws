import time
import rclpy
from rclpy.node import Node
from pymycobot.mycobot import MyCobot
from sensor_msgs.msg import JointState
from geometry_msgs.msg import Vector3
from example_interfaces.msg import Int16, Float32, Bool


class Pos_origen(Node):
    def __init__(self):
        super().__init__("origen")
        self.mc = MyCobot('/dev/ttyACM0', '115200')
        self.get_logger().info("port:%s, baud:%d" % ('ttyACM0',115200))
        time.sleep(0.05)

        # posición  inicial de reconocimiento = [69.6, 63.54, 108.98, 2.37, -36.29, -128.32]
        self.lim_inf = [89, 86, -1, 93, 83, 43]
        self.lim_sup = [91, 88, 1, 95, 85, 45]

        # Creación nodo publicador
        self.publisher = self.create_publisher(
            JointState, "joint_states", 10)
        self.publisher

        # subscripción de topicos aruco_marker
        self.Sub = self.create_subscription(
            Vector3, 'Pose_marker', self.listener_pose, 10)
        self.Sub    

        self.Sub2 = self.create_subscription(
            Int16, 'iD', self.listener_callback, 10)
        self.Sub2    

        self.Sub3 = self.create_subscription(
            Float32, 'Reach_distance', self.listener_callback, 10)
        self.Sub3   

        self.Sub4 = self.create_subscription(
            Bool, 'Marker_state', self.listener_callback, 10)
        self.Sub4 

        self.counter = 0    # contador ciclos
        timer_period = 3    # llamado a la funcion del nodo
        self.timer = self.create_timer(
            timer_period, self.move_callback)
        self.get_logger().info("Rutina node has been started.")

    def move_callback(self):
        # Posición de reconocimiento:
        angle_datas = self.mc.get_angles()
        print(f"ciclo = {self.counter}, Position angles= {angle_datas}")
        time.sleep(1.5)
        for valor, limite_inferior, limite_superior in zip(angle_datas, self.lim_inf, self.lim_sup):
            if not (limite_inferior == valor <= limite_superior):
                self.mc.send_angles([90, 87, 0, 94, 84, 44], 40)
                time.sleep(0.5)
                angle_datas = self.mc.get_angles()
                print(angle_datas)

        # Posicion de barrido:
        self.mc.send_angle(1, -80, 5)
        time.sleep(20)
        print(f"mycobot esta pausado = {self.mc.is_paused()}")
        angle_datas = self.mc.get_angles()
        print(f"ciclo = {self.counter}, Position angles 2 = {angle_datas}")
        time.sleep(0.5)
        self.counter += 1
        if self.counter == 3:
            raise SystemExit
        
        # Acción de reconocimiento y detección:
    def listener_callback(self, msg):
        pass

    def listener_pose(self, msg):
        print(msg)
        print(f"coordenadas detección = {self.mc.get_angles_coords()}")
        print(f"angulos detección = {self.mc.get_angles()}")
        
def main(args=None):
    rclpy.init(args=args)
    pos_origen = Pos_origen()
    
    try:
        rclpy.spin(pos_origen)
    except SystemExit:                 # <--- process the exception 
        rclpy.logging.get_logger("Quitting").info('Done')

    pos_origen.destroy_node()
    rclpy.shutdown()