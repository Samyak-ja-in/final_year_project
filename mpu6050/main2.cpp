#include <iostream>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include<sys/ioctl.h>
#include<linux/i2c.h>
#include<linux/i2c-dev.h>
#include <stdint.h>
//#include <bits/stdc++.h>
#include <math.h>
#include <chrono>

using namespace std;

double accelX, accelY, accelZ, temperature, gyroX, gyroY, gyroZ, gyro_x_cal, gyro_y_cal, gyro_z_cal; //These will be the raw data from the MPU6050.
long long timer; //it's a timer, saved as a big-ass unsigned int.  We use it to save times from the "micros()" command and subtract the present time in microseconds from the time stored in timer to calculate the time for each loop.
double roll, pitch ,yaw; //These are the angles in the complementary filter
float rollangle,pitchangle;
int cal_int;
int file, write_data[1] = {0x75}, write_data2[16] = {0x6B, 0x00, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48};
int32_t data[15];


void initMPU6050(void);
void getRawData(void);
void calibration(void);

int main(void)
{
        initMPU6050();
        cout << "---------------------------------" << endl;
        //getRawData(data);
        //calibration();
        cal_int = 0;
        while (cal_int > 0)
        {
                getRawData();
                gyro_x_cal += gyroX;
                gyro_y_cal  += gyroY;
                gyro_z_cal += gyroZ;
                cal_int++;
        }
        gyro_x_cal /= 2000;
        gyro_y_cal /= 2000;
        gyro_z_cal /= 2000;

        auto start = chrono::high_resolution_clock::now();
        while (1)
        {

                getRawData();
                gyroX = gyroX / 65.5;
                gyroY = gyroY / 65.5;
                gyroZ = gyroZ / 65.5;

                accelX = accelX / 4096.0;
                accelY = accelY / 4096.0;
                accelZ = accelZ / 4096.0;
                auto elapsed = chrono::high_resolution_clock::now() - start;
                long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
                //start = elapsed;
                start = chrono::high_resolution_clock::now();
                double dt = (double)(microseconds - timer) / 1000000;

                //the next two lines calculate the orientation of the accelerometer relative to the earth and convert the output of atan2 from radians to degrees
                //We will use this data to correct any cumulative errors in the orientation that the gyroscope develops.
                rollangle = atan2(accelY, accelZ)*180/3.14; // FORMULA FOUND ON INTERNET
                pitchangle = atan2(accelX, sqrt(accelY*accelY + accelZ*accelZ))*180/3.14; //FORMULA FOUND ON INTERNET

                //THE COMPLEMENTARY FILTER
                //This filter calculates the angle based MOSTLY on integrating the angular velocity to an angular displacement.
                //dt, recall, is the time between gathering data from the MPU6050.  We'll pretend that the
                //angular velocity has remained constant over the time dt, and multiply angular velocity by
                //time to get displacement.
                //The filter then adds a small correcting factor from the accelerometer ("roll" or "pitch"), so the gyroscope knows which way is down.
                roll = 0.99 * (roll+ gyroX * dt) + 0.01 * rollangle; // Calculate the angle using a Complimentary filter
                pitch = 0.99 * (pitch + gyroY * dt) + 0.01 * pitchangle;
                yaw = gyroZ;

                cout << "roll : " << roll << endl;
                cout << "pitch : " << pitch << endl;
                cout << "yaw : " << yaw << endl;
        }
        /*// printing all output register's data
        for (int count = 1; count < 15; count++)
        {
                data[count] = (0xFF & data[count]);
                cout << "Tushar hex>>> " << hex <<  data[count] << endl;
        }
        // ignore garbage data & make all data as 8-bits
        for (int i = 1; i < 14; i+=2)
        {
                data[i] =  ((data[i] << 8) | data[i+1]);
                cout << "Tushar combined >> " << hex << ( data[i]) << endl;
        }
        // converting into 2's compliment
        for (int count = 1; count <= 14; count+=2)
        {
                if ((data[count] & (1 << 15)))
                {
                        for(int x = 0; x < 16; x++)
                        {
                                data[count] ^= (1 << x);
                        }
                        data[count] += 1;
                        cout << "Tushar 2's>>> -" << dec << (0x0FFFF &  data[count]) << endl;
                }
                else
                {
                        cout << "Tushar dec>>> " << dec <<  (0x0FFFF & data[count]) << endl;
                }
        }*/
        return 0;
}

void initMPU6050(void)
{
        file = open("/dev/i2c-2", O_RDWR);
        ioctl(file, I2C_SLAVE, 0x68);
        write(file, write_data, 1);
        read(file, data, 1);
        close(file);

        if ((0x0000FF & data[0]) == 0x68)
        {
                cout << "MPU6050 says OK :) " << endl;
                cout << "MPU6050 responded with id : " << (0x0000FF & data[0]) << endl;
        }
        else
        {
                cout << "MPU6050 says ERROR :(" << endl;
        }

        file = open("/dev/i2c-2", O_RDWR);
        ioctl(file, I2C_SLAVE, 0x68);
}

void calibration(int32_t * data)
{
        cal_int = 0;
        while (cal_int > 0)
        {
                getRawData();
                gyro_x_cal += gyroX;
                gyro_y_cal  += gyroY;
                gyro_z_cal += gyroZ;
                cal_int++;
        }
        gyro_x_cal /= 2000;
        gyro_y_cal /= 2000;
        gyro_z_cal /= 2000;

        //start a timer
        //timer = micros();
        auto start = chrono::high_resolution_clock::now();
}

void getRawData(void)
{
        write(file, write_data2, 1);
        write(file, &write_data2[1], 1);
        for (int i = 0; i < 14; i++)
        {
                write(file, &write_data2[2 + i], 1);
                read(file, &data[i+1], 1);
        }
        // ignore garbage data & make all data as 8-bits
        for (int i = 1; i < 14; i+=2)
        {
                data[i] =  ((data[i] << 8) | data[i+1]);
                // cout << "Tushar combined >> " << hex << ( data[i]) << endl;
        }
        accelX = data[1]; //Store first two bytes into accelX
        accelY = data[3]; //Store middle two bytes into accelY
        accelZ = data[5]; //Store last two bytes into accelZ
        temperature = data[7];
        gyroX = data[9]; //Store first two bytes into accelX
        gyroY = data[11]; //Store middle two bytes into accelY
        gyroZ = data[13]; //Store last two bytes into accelZ

        if(cal_int == 2000)
        {
                gyroX -= gyro_x_cal;
                gyroY -= gyro_y_cal;
                gyroZ -= gyro_z_cal;
        }
}
