#include"mpu6050.h"

IMU_MPU6050::IMU_MPU6050(unsigned char address)
{
	int file;
	file = open("/dev/i2c-2", O_RDWR);
	ioctl(file, I2C_SLAVE, 0x68);
        write(file, &imu_id_REG, 1);
        read(file, &imu_response, 1);
        close(file);
	if ((0x0000FF & imu_response) == 0x68)
	{
		std::cout << "IMU_MPU6050 says OK :) " << std::endl;
                std::cout << "IMU_MPU6050 responded with id : " << (0x0000FF & imu_response) << std::endl;
		std::cout << "waking up the IMU_MPU6050" << std::endl;
		file = open("/dev/i2c-2", O_RDWR);
		ioctl(file, I2C_SLAVE, 0x68);
        	write(file, &imu_wakeup_REG, 1);
        	write(file, &imu_wakeup_cmd, 1);
        	close(file);
	}
	else
        {
                std::cout << "IMU_MPU6050 says ERROR :(" << std::endl;
	}  
}

void IMU_MPU6050::getRawData(void)
{
	int file;
	file = open("/dev/i2c-2", O_RDWR);
	ioctl(file, I2C_SLAVE, 0x68);
        for (int i = 0; i < 14; i++)
	{
		write(file, &imu_data_reg[i], 1);
                read(file, &imu_raw_data[i], 1);
	}
	// ignore garbage data & make all data as 8-bits just for safty
	for (int i = 0; i < 14; i+=2)
	{
		imu_raw_data[i] =  (((0x000000FF & imu_raw_data[i]) << 8) | ((0x000000FF & imu_raw_data[i+1])));
	}
	// debug code
	/*int k = 0;
	for (int i = 0; i < 14; i+=2)
	{	
		std::cout << k << std::endl;
	 	std::cout << imu_raw_data[i] << std::endl;
		k++;
	}*/

}

void IMU_MPU6050::calculateOffSets(void)
{
	long int max = 1000;
	// take average of all offsets
	for (int i = 0; i < max; i++)
	{
		getRawData();
		ax_offset = ax_offset + imu_raw_data[0];	
		ay_offset = ay_offset + imu_raw_data[2];	
		az_offset = az_offset + imu_raw_data[4];	
		gx_offset = gx_offset + imu_raw_data[8];	
		gy_offset = gy_offset + imu_raw_data[10];
		gz_offset = gz_offset + imu_raw_data[12];
	}
	ax_offset = ax_offset/max; 
	ay_offset = ay_offset/max;	
	az_offset = az_offset/max;	
	gx_offset = gx_offset/max;	
	gy_offset = gy_offset/max;	
	gz_offset = gz_offset/max;

	// remove 1g from az_off to compensate for gravity
	az_offset = az_offset - 4096;
	// print the average values
	// debug code
	/*	
	std::cout << "ax_offset : " << ax_offset << std::endl;
	std::cout << "ay_offset : " << ay_offset << std::endl;
	std::cout << "az_offset : " << az_offset << std::endl;
	std::cout << "gx_offset : " << gx_offset << std::endl;
	std::cout << "gy_offset : " << gy_offset << std::endl;
	std::cout << "gz_offset : " << gz_offset << std::endl;*/
}

void IMU_MPU6050::calculateIMUData()
{
	getRawData();
	imu_data[0] = round(((imu_raw_data[0] - ax_offset) * 1000.0) / 4096.0) / 1000.0; 
	imu_data[1] = round(((imu_raw_data[2] - ay_offset) * 1000.0) / 4096.0) / 1000.0;
	imu_data[2] = round(((imu_raw_data[4] - az_offset) * 1000.0) / 4096.0) / 1000.0;	
	imu_data[3] = round(((imu_raw_data[8] - gx_offset) * 1000.0) / 65.5) / 1000.0;	
	imu_data[4] = round(((imu_raw_data[10] - gy_offset) * 1000.0) / 65.5) / 1000.0;	
	imu_data[5] = round(((imu_raw_data[12] - gz_offset) * 1000.0) / 65.5) / 1000.0;
	// debug code
	/*
	for (int i = 0; i < 6; i++)
	{
		std::cout << "imu_data[" << i << "] = " << imu_data[i] << std::endl;
	}*/
	std::cout << "ax = " << imu_data[0] << std::endl;
	std::cout << "ay = " << imu_data[1] << std::endl;
	std::cout << "az = " << imu_data[2] << std::endl;
}

void IMU_MPU6050::calculateAcclAngle(void)
{
	calculateIMUData();
	imu_accl_angle[0] = (atan2(imu_data[2], imu_data[1]) * 180/3.14) - 90.0;
	imu_accl_angle[1] = (atan2(imu_data[2], imu_data[0]) * 180/3.14) - 90.0;
	imu_accl_angle[2] = (atan2(imu_data[2], imu_data[1]) * 180/3.14) - 90.0;
	std::cout << "accl roll = " << imu_accl_angle[0] << std::endl;
	std::cout << "accl pitch = " << imu_accl_angle[1] << std::endl;
	std::cout << "accl yaw = " << imu_accl_angle[2] << std::endl;
}

