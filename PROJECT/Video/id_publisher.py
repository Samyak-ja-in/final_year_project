#To publish the ids of aruco marker over a topic /id 
from sensor_msgs.msg import *
from cv_bridge import CvBridge
import cv2 as cv
import cv2.aruco as aruco
import rospy
import roslib
from std_msgs.msg import *


rospy.init_node("video_reader",anonymous=True)
rate=rospy.Rate(100)
bridge=CvBridge()

pub=rospy.Publisher('/id',Int32,queue_size=10)

def detect_ArUco(img):
    img_gray=cv.cvtColor(img, cv.COLOR_BGR2GRAY)
    arucodict=aruco.Dictionary_get(aruco.DICT_5X5_250)
    arucoparam=aruco.DetectorParameters_create()
    dim,ids,rejected=aruco.detectMarkers(img_gray,arucodict,parameters=arucoparam)
    if ids:                 #BECAUSE WHEN NO ARUCO IS THERE THEN NONETYPE
        id=int(ids)
        detected_ids=Int32()
        detected_ids.data=id
        pub.publish(detected_ids)
        rate.sleep()

def callback(data):
    image=bridge.imgmsg_to_cv2(data,"bgr8")
    detect_ArUco(image)
sub=rospy.Subscriber('/video',Image,callback)

rospy.spin()