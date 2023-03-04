#image is converted back from ros type to opencv type data of height and width is extracted 
#same topic /image is subscribed
#we can see the extracted image in image_raw

from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2 as cv
import rospy
from std_msgs.msg import *
import roslib

rospy.init_node("image_reader",anonymous=True)

bridge=CvBridge()

def callback(data):
    image=bridge.imgmsg_to_cv2(data,"bgr8")
    print("height=",image.shape[0],"width=",image.shape[1])
sub=rospy.Subscriber('/image',Image,callback)

rospy.spin()
