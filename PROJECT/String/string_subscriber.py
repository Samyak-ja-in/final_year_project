import rospy
from std_msgs.msg import String


rospy.init_node('string_subscriber',anonymous=True)
def callback(data):
    print(data)
rospy.Subscriber('/string',String,callback)

rospy.spin()