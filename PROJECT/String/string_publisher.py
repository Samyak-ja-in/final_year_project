import rospy
from std_msgs.msg import String

rospy.init_node('string_publisher',anonymous=True)
rate=rospy.Rate(1)

pub=rospy.Publisher('/string',String,queue_size=10)

count=0

while not rospy.is_shutdown():
    bare_string="Samyak is a good boy "+str(count)
    ros_string=String()
    ros_string.data=bare_string
    pub.publish(ros_string)
    print("published string",count)
    count=count+1
    rate.sleep()







