#image is first converted to ros readable image from open-cv type
#image is published on /image topic


from sensor_msgs.msg import *
from cv_bridge import CvBridge
import cv2 as cv
import rospy
import roslib
from std_msgs.msg import *



rospy.init_node("image_publisher",anonymous=True)
rate=rospy.Rate(1)

image=cv.imread("/home/samyak01/Desktop/FINAL YEAR PROJECT /PROJECT/Image/lambo.png")



bridge=CvBridge()
image_message=bridge.cv2_to_imgmsg(image,"bgr8")


pub=rospy.Publisher("/image",Image,queue_size=10)
while not rospy.is_shutdown():
    pub.publish(image_message)
    rospy.loginfo('publishing image')
    rate.sleep()
rospy.spin()