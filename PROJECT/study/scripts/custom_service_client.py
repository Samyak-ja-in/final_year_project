import rospy
from custom.msg import *
from custom.srv import *
from std_msgs.msg import *

rospy.init_node('adder_client',anonymous=True)
rate=rospy.Rate(1)
# rospy.wait_for_service('add')
jodo=rospy.ServiceProxy('add', add_two_floats)
pub=rospy.Publisher('sum', Float64,queue_size=10)
def cb(data):
    p=float(data.a)
    q=float(data.b)
    
    ans=jodo(p,q)
    pub.publish(ans.sum)
    rate.sleep()

    

sub=rospy.Subscriber('/numbers', two_nums,cb)
rospy.spin()