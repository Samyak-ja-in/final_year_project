import rospy
from custom.msg import *

rospy.init_node('adder',anonymous=True)
rate=rospy.Rate(10)

pub=rospy.Publisher("/numbers",two_nums,queue_size=10)

var=two_nums()
while not rospy.is_shutdown():
    a,b=input().split()

    var.a=int(a)
    var.b=int(b)
    pub.publish(var)
    rate.sleep()

