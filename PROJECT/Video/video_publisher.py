#to get the video published frame by frame over a topic /video
from sensor_msgs.msg import *
from cv_bridge import CvBridge
import cv2 as cv
import rospy
import roslib
from std_msgs.msg import *

rospy.init_node("image_publisher",anonymous=True)
rate=rospy.Rate(100)

vid=cv.VideoCapture("videomain.mp4")

success=True

pub=rospy.Publisher("/video",Image,queue_size=10)

while success:
    success,image=vid.read()
    try:
        image=cv.resize(image,(270,480))
        bridge=CvBridge()
        image_message=bridge.cv2_to_imgmsg(image,"bgr8")
        pub.publish(image_message)
        rate.sleep()
    except:
        pass
    
rospy.spin()

