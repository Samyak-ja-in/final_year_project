#To get the width and height of the published image

from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2 as cv
import rospy
from std_msgs.msg import *


rospy.init_node("video_reader",anonymous=True)

bridge=CvBridge()

def callback(data):
    image=bridge.imgmsg_to_cv2(data,"bgr8")
    print("height=",image.shape[0],"width=",image.shape[1])
sub=rospy.Subscriber('/video',Image,callback)

rospy.spin()