import rclpy
from pymycobot.mycobot import MyCobot
from pymycobot.genre import Coord
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

        # [-214.4, -44.2, 72.2, 89.51, -39.59, -160.09] # coordenada de reconocimiento
        # [-222.0, 44.3, 44.5, 88.43, -41.36, -176.45] # coordenada de recolección

        # Encontrar a que tipo de mensaje se publica en coordenadas Vector3?
        self.publisher = self.create_publisher(
            JointState, "joint_states", 10)
        self.publisher

        timer_period = 1
        self.timer = self.create_timer(
            timer_period, self.listener_callback)
        self.get_logger().info("Origen node has been started.")

    def listener_callback(self):
        angle_datas = self.mc.get_coords()
        print(angle_datas)
        time.sleep(0.5)

        """
        Nota:

        los limites de trabajo de las rotaciones son:

        coords: The coordinate value of [x, y, z, rx, ry, rz] 
        has a length of 6, x, y, z ranging from - 280 to 280, 
        and rx, ry, yz ranging from - 314 to 314
        """
        #coords = list([45.5, -63.6, 412.3, -90.35, -0.26, -90.26])  # coordenadas origen
        #coords = list([0, 0, 0, 0, 0, 0])  # coordenadas origen, no funciona
        #self.mc.send_coords([-13.7, -107.5, 223.9, 165.52, -75.41, -73.52], 80, 1), si funciona
        #self.mc.send_coords([187.8, 42.1, 183.3, -159.6], 80, 0), si funciona
        #self.mc.send_coords(coords, 50, 1)

        self.mc.send_coords([-214.4, -44.2, 72.2, 89.51, -39.59, -160.09], 20, 0)
        # Detección objeto:
        # coordenadas: X = 16.2, Y = -4.3, Z = 71.6. Id = 3  , distance = 23.26
        # wait for 2 seconds
        time.sleep(5)

        # Coordenada objetivo:
        self.mc.send_coords([-222.0, 44.3, 44.5, 88.43, -41.36, -176.45], 10, 0)
        # wait for 2 seconds
        time.sleep(2)

        self.mc.send_coords([-230.0, ])
        
        """
        #Plan the route at random, let the head reach the coordinates of [57.0, -107.4, 316.3] in an non-linear manner at the speed is 80mm/s
        self.mc.send_coords([187.8, 42.1, 183.3, -159.6], 40, 0)
        # wait for 2 seconds
        time.sleep(2)

        # Plan the route at random, let the head reach the coordinates of [207.9, 47, 49.3,-159.69] in an non-linear manner at the speed is 80mm/s
        self.mc.send_coords([207.9, 47, 49.3,-159.69], 40, 0)
        # wait for 2 seconds
        time.sleep(2)

        #To change only the x-coordinate of the head, set the x-coordinate of the head to 20. Let it plan the route at random and move the head to the changed position at a speed of 70mm/s
        self.mc.send_coord(Coord.X.value, 20, 40)
        """

        time.sleep(1.5)
        print(f"mycobot esta pausado = {self.mc.is_paused()}")

        """
        for valor, limite_inferior, limite_superior in zip(angle_datas, self.lim_inf, self.lim_sup):
            if (limite_inferior <= valor <= limite_superior):
                raise SystemExit
        """    

def main(args=None):
    rclpy.init(args=args)
    pos_origen = Pos_origen()
    
    try:
        rclpy.spin(pos_origen)
    except SystemExit:                 # <--- process the exception 
        rclpy.logging.get_logger("Quitting").info('Done')

    pos_origen.destroy_node()
    rclpy.shutdown()


"""
def get_coord_input(self):
        # 获取 coord 输入的数据，发送给机械臂
        c_value = []
        for i in self.all_c:
            c_value.append(float(i.get()))
        self.speed = (
            int(float(self.get_speed.get())) if self.get_speed.get() else self.speed
        )
        
        try:
            self.mc.send_coords(c_value,self.speed, self.model)
        except Exception as e:
            pass
        self.show_j_date(c_value, "coord")

        

    def get_joint_input(self):
        # 获取joint输入的数据，发送给机械臂
        j_value = []
        for i in self.all_j:
            j_value.append(float(i.get()))
            
        self.speed = (
            int(float(self.get_speed.get())) if self.get_speed.get() else self.speed
        )
        
        res = [j_value, self.speed]

        try:
            self.mc.send_angles(*res)
        except Exception as e:
            pass
        self.show_j_date(j_value)
        # return j_value,c_value,speed

        

    def get_date(self):
        # 拿机械臂的数据，用于展示
        t = time.time()
        while time.time() - t < 2:
            self.res = self.mc.get_coords()
            if self.res != []:
                break
            time.sleep(0.1)

        t = time.time()
        while time.time() - t < 2:
            self.angles = self.mc.get_angles()
            if self.angles != []:
                break
            time.sleep(0.1)
        
        self.record_coords[0] = self.res
        self.res_angles[0] = self.angles

        

    # def send_input(self,dates):
    def show_j_date(self, date, way=""):
        # 展示数据
        if way == "coord":
            for i, j in zip(date, self.coord_all):
                j.set(str(i))
        else:
            for i, j in zip(date, self.cont_all):
                j.set(str(i) + "°")


                 
    def run(self):
        while True:
            try:
                self.win.update()
                time.sleep(0.001)
            except tk.TclError as e:
                if "application has been destroyed" in str(e):
                    break
                else:
                    raise

 
"""