import cv2 as cv
from cv2 import aruco
import numpy as np
import rclpy
from rclpy.node import Node
from mycobot_interfaces.msg import MyArucoCoords

                
class ArucoMarkers(Node):
    def __init__(self):
        super().__init__("aruco")
        self.distance = 0
        self.Pub = self.create_publisher(
            MyArucoCoords, 'marker_data',10)
        self.Pub    
        
        timer_period = 0.5
        self.timer = self.create_timer(timer_period, self.lectura_clbk)
        self.i = 0

    def lectura_clbk(self):
        self.msg = MyArucoCoords()
        calib_data_path = "/home/david/code/MultiMatrix.npz"
        calib_data = np.load(calib_data_path)

        cam_mat = calib_data["camMatrix"]
        dist_coef = calib_data["distCoef"]
        r_vectors = calib_data["rVector"]
        t_vectors = calib_data["tVector"]

        MARKER_SIZE = 10    # centimeters

        marker_dict = aruco.getPredefinedDictionary(aruco.DICT_4X4_1000)
        param_markers = aruco.DetectorParameters()
        cap = cv.VideoCapture(2)

        while True:
            ret, frame = cap.read()
            if not ret:
              break

            gray_frame = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
            marker_corners, marker_IDs, reject = aruco.detectMarkers(
                gray_frame, marker_dict, parameters=param_markers
            )
            if marker_corners:
                rVec, tVec, _ = aruco.estimatePoseSingleMarkers(
                    marker_corners, MARKER_SIZE, cam_mat, dist_coef
                )
                total_markers = range(0, marker_IDs.size)
                for ids, corners, i in zip(marker_IDs, marker_corners, total_markers):
                    cv.polylines(
                        frame, 
                        [corners.astype(np.int32)], 
                        True, 
                        (0, 255, 255), 
                        4, 
                        cv.LINE_AA
                    )
                    corners = corners.reshape(4, 2)
                    corners = corners.astype(int)
                    top_right = corners[0].ravel()
                    top_left = corners[1].ravel()
                    bottom_right = corners[2].ravel()
                    bottom_left = corners[3].ravel()

                    # Since there was mistake in calculating the distance approach point-outed in the Video Tutorial's comment
                    # so I have rectified that mistake, I have test that out it increase the accuracy overall.
                    # Calculating the distance
                    self.distance = np.sqrt(
                        (tVec[i][0][2] ** 2 + tVec[i][0][0] ** 2 + tVec[i][0][1] ** 2)/MARKER_SIZE
                    )

                    # Draw the pose of the marker
                    point = cv.drawFrameAxes(frame, cam_mat, dist_coef, rVec[i], tVec[i], 4, 4)
                    cv.putText(
                        frame,
                        f"id: {ids[0]} Dist: {round(self.distance, 2)}",
                        #f"id: {ids[0]} Dist: {round(distance, 2)}  angz: {round(theta_z, 2)}",
                        top_right,
                        cv.FONT_HERSHEY_PLAIN,
                        1.3,
                        (0, 0, 255),
                        2,
                        cv.LINE_AA,
                    )
                    cv.putText(
                        frame,
                        f"x:{round(tVec[i][0][0],1)} y: {round(tVec[i][0][1],1)} z: {round(tVec[i][0][2],1)} ",
                        bottom_right,
                        cv.FONT_HERSHEY_PLAIN,
                        1.0,
                        (0, 0, 255),
                        2,
                        cv.LINE_AA,
                    )
                    
                    if (1 <= round(self.distance) <= 50):
                        if (int(ids[0]) <= 10):
                            self.msg.x = round(tVec[i][0][0],1)
                            self.msg.y = round(tVec[i][0][1],1)
                            self.msg.z = round(tVec[i][0][2],1)
                            self.msg.id = int(ids[0])
                            self.msg.distance = self.distance  
                            self.msg.flag = True
                            
                            print(self.msg)
                            self.Pub.publish(self.msg)        

            else:      
                # parametros por defecto
                self.msg.x = 0.0
                self.msg.y = 0.0
                self.msg.z = 0.0
                self.msg.id = 0
                self.msg.distance = 0.0  
                self.msg.flag = False

                print(self.msg)
                self.Pub.publish(self.msg)

            cv.imshow("frame", frame)
            key = cv.waitKey(1)
            if key == ord("q"):
                break
        cap.release()
        cv.destroyAllWindows()
                
                
def main(args=None):
    rclpy.init(args=args)
    MyNode = ArucoMarkers()
    rclpy.spin(MyNode)
    MyNode.destroy_node()
    rclpy.shutdown()