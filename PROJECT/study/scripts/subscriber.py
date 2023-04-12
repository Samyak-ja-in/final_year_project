import rospy
from std_msgs.msg import String


rospy.init_node('subscriber',anonymous=True)


def cb(data):
    print("Recieved string is ",data.data)

rospy.Subscriber('/chatter', String,cb)
rospy.spin()