import rospy
import cv2 as cv
from cv_bridge import CvBridge
from sensor_msgs.msg import Image

rospy.init_node('image_publisher',anonymous=True)
rate=rospy.Rate(10)
pub=rospy.Publisher('/image', Image,queue_size=10)

bridge=CvBridge()
img=cv.imread('/home/samyak01/Desktop/work/src/study/scripts/img.png')
ros_image=bridge.cv2_to_imgmsg(img,"bgr8")

while not rospy.is_shutdown():
    pub.publish(ros_image)
    rospy.loginfo('Image is Publishing')
    rate.sleep()



