import rospy
from custom.srv import *

rospy.init_node('adder_server',anonymous=True)

def handle(num):
    print("returning sum")
    return num.a+num.b

s=rospy.Service('add',add_two_floats,handle)
rospy.spin()