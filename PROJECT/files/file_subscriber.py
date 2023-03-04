import rospy
from std_msgs.msg import *

rospy.init_node('file_subscriber',anonymous=True)
rate=rospy.Rate(1)


def cb(data):
    print("Data Recieved is ",data.data)
sub=rospy.Subscriber('/ir_sensor',Int32,cb)
rospy.spin()