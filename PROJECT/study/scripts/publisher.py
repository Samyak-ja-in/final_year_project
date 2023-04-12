import rospy
from std_msgs.msg import String


rospy.init_node('publisher',anonymous=True)
rate=rospy.Rate(1)
pub=rospy.Publisher('/chatter', String,queue_size=10)


string="Hello World!"
value=String()
value.data=string

while rospy.is_shutdown():
    pub.publish(value)
    rate.sleep()

rospy.spin()