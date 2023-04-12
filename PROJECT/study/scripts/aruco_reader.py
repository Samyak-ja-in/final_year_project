import rospy
import cv2 as cv
from std_msgs.msg import *


rospy.init_node("id_publisher",anonymous=True)
rate=rospy.Rate(10)
pub=rospy.Publisher("/id",Int32,queue_size=10)

def detect_ArUco(img):
    print("in detect")
    img_gray=cv.cvtColor(img, cv.COLOR_BGR2GRAY)
    arucodict=aruco.Dictionary_get(aruco.DICT_5X5_250)
    arucoparam=aruco.DetectorParameters_create()
    dim,ids,rejected=aruco.detectMarkers(img_gray,arucodict,parameters=arucoparam)
    if ids:                 #BECAUSE WHEN NO ARUCO IS THERE THEN NONETYPE
        id=int(ids)
        detected_ids=Int32()
        detected_ids.data=id
        pub.publish(detected_ids)
        rospy.loginfo("publishing ids")
        rate.sleep()

vid=cv.VideoCapture("videomain.mp4")

success=True
while success:
    # print("here")
    image=vid.read()
    try:
        success,image=cv.resize(image,(270,480))
        print(success)
        detect_ArUco(image)
        rate.sleep()
    except:
        pass

