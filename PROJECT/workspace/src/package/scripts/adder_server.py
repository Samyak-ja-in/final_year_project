import rospy
from package.srv import *


rospy.init_node('adding_server')

def cb(data):
    print("Returning [%s + %s = %s]"%(data.a, data.b, (data.a + data.b)))
    rospy.loginfo('sumation of %s + %s is %s'%(data.a,data.b,data.a + data.b))
    return(data.a+data.b)

add_server=rospy.Service('/add', addint, cb)

rospy.spin()

