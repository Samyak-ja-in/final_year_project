#include <iostream>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include<sys/ioctl.h>
#include<linux/i2c.h>
#include<linux/i2c-dev.h>
#include <stdio.h>
#include <stdint.h>
//#include <bits/stdc++.h>

using namespace std;

int main(void)
{
        double gyro_x, gyro_y, gyro_z, temp, acc_x, acc_y, acc_z;
        int file, write_data[1] = {0x75}, write_data2[16] = {0x6B, 0x00, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48};
        int data[15];
        file = open("/dev/i2c-2", O_RDWR);
        ioctl(file, I2C_SLAVE, 0x68);
        write(file, write_data, 1);
        read(file, data, 1);
        close(file);
        cout << "Tushar : " << (0x0000FF & data[0]) << endl;
        file = open("/dev/i2c-2", O_RDWR);
        ioctl(file, I2C_SLAVE, 0x68);
        write(file, write_data2, 1);
        write(file, &write_data2[1], 1);
        cout << "---------------------------------" << endl;
        for (int i = 0; i < 14; i++)
        {
                write(file, &write_data2[2 + i], 1);
                read(file, &data[i+1], 1);
        }
        for (int count = 0; count < 15; count++)
        {
                cout << "Tushar hex>>> " << hex <<  (0x0FF & data[count]) << endl;
                if ((data[count] & (1 << 7)))
                {
                        for(int x = 0; x < 8; x++)
                        {
                                data[count] ^= (1 << x);
                        }
                        data[count] += 1;
                        cout << "Tushar 2's>>> -" << dec << (0x0FF &  data[count]) << endl;
                }
                else
                {
                         cout << "Tushar dec>>> " << dec <<  (0x0FF & data[count]) << endl;
                }
        }
        for (int i = 1; i < 14; i+=2)
        {
                data[i] =  (data[i] << 8) | data[i+1];
                cout << "Tushar combined >> " << dec << (0x0FFFF & data[i]) << endl;
        }
        return 0;
}