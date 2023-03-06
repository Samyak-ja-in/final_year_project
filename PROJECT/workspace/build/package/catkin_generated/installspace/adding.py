import rospy
from package.msg import integer
from package.srv import addint


rospy.init_node('adding_ints')

pub=rospy.Publisher('sum', integer,queue_size=10)
def fun(a,b):
    return(a+b)

serv=rospy.Service('add', addint, fun)

while not rospy.is_shutdown():
    a,b=int(input("Enter two numbers "))
    addi=rospy.ServiceProxy('add', addint)
    sumation=addi(a,b)
    data=integer()
    data.sum=sumation
    pub.publish(data)
    