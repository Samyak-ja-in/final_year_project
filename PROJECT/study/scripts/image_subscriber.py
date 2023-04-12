import rospy
from sensor_msgs.msg import Image

rospy.init_node("image_subscriber",anonymous=True)


def cb(data):
    print("image height is ",data.height,"image width is ",data.width)
    

rospy.Subscriber('/image', Image,cb)
rospy.spin()