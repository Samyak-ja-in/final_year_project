import rospy
from package.msg import integer
from package.srv import addint


rospy.init_node('adding_client')

pub=rospy.Publisher('sum', integer,queue_size=10)

while not rospy.is_shutdown():
    a,b= map(int, input("Enter two numbers ").split())
    addi=rospy.ServiceProxy('/add', addint)
    sumation=addi(a,b)
    data=integer()
    data=sumation
    pub.publish(data)
    