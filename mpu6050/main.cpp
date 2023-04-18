#include"mpu6050.h"

int main(void)
{
	//cout << "calibrating the first MPU6050" << endl;
	IMU_MPU6050 imu_1(0x68);
	// getRawData();
	// cout << endl;
	imu_1.calculateOffSets();
	// calculateIMUData();
	while (1)
	{
	//	getRawData();
		imu_1.calculateAcclAngle();
		sleep(1);
	}
	return 0;
}
