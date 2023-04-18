#ifndef _MPU6050_H_
#define _MPU6050_H_

#include <iostream>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <stdint.h>
#include <math.h>

class IMU_MPU6050
{
	private:
		// imu_response will record the data from id-register
		unsigned char imu_response = 0;

		// imu id-register address
		unsigned char imu_id_REG = 0x75;

		// imu wakeup register address
		unsigned char imu_wakeup_REG = 0x6B;

		// imu wakeup command // however this is not perfect
		unsigned char imu_wakeup_cmd = 0x00;

		// stores the raw data from mpu data registers
		int32_t imu_raw_data[14];

		// address of mpu data registers
		int imu_data_reg[14] = {0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48};
		
		// initiates offsets to 0
		float ax_offset = 0;
		float ay_offset = 0;
		float az_offset = 0;
		float gx_offset = 0;
		float gy_offset = 0;
		float gz_offset = 0;
		
		// this function gives the raw data from imu
		virtual void getRawData(void);
	public:
		// mpu6050 processed data
		float  imu_data[6];

		// mpu6050 accleration angles
		float  imu_accl_angle[3];

		// mpu6050 gyroscope angles
		float  imu_gyro_angle[3];

		// contructor initializes the MPU6050
		IMU_MPU6050(unsigned char address);

		// this function calculate the offsets and update the respective variables
		virtual void calculateOffSets(void);

		// this function gives the processed results and update therequired variables
		virtual void calculateIMUData(void);

		// this function gives the required angles
		// according to current requirement of project it is calculating only the accl angles
		// if requirement comes will only then add gyro angles
		virtual void calculateAcclAngle(void);
};

#endif
