from sensor_msgs.msg import *
from cv_bridge import CvBridge
import cv2 as cv
import rospy
import roslib
from std_msgs.msg import *

rospy.init_node("webcam_publisher",anonymous=True)
rate=rospy.Rate(100)

vid=cv.VideoCapture(0)
vid.set(3,640)      #width
vid.set(4,480)      #height
vid.set(10,200)       #brightness
success=True
while success:
    success,img1=vid.read()
    cv.imshow("SAMYAK PROJECT",img1)
    if cv.waitKey(1) & 0xFF ==ord('q'):
        break

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