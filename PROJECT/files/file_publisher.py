import rospy
from std_msgs.msg import *

rospy.init_node('file_publisher',anonymous=True)
rate=rospy.Rate(1)

pub=rospy.Publisher('/ir_sensor',Int32,queue_size=10)

sensor_data=Int32()
with open ("sensor.txt") as f:
    for line in f:
        data=line
        sensor_data.data=int(data)
        pub.publish(sensor_data)
        print("Published data")
        rate.sleep()

