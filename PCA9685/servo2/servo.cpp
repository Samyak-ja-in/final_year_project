#include "servo.h"

void rotateServo(int motor_no, int frequency, int duty_cycle)
{
	// 25000000/4096 = 6103
	int value = round(6013/frequency) - 1;
	int value2 = (6 + (motor_no*4));
	int value3 = round((duty_cycle * 4096)/100);
	int8_t valueL = (0xFF & value3);
	int8_t valueH = ((value3 >> 8) & 0xFF);
	system("i2cget -y 2 0x40 0x00");
	system("i2cset -y 2 0x40 0x00 0x11");
	//system(string("i2cset -y 2 0x40 " + std::to_string(value2) + " 0x00").c_str());
	system(("i2cset -y 2 0x40 " + std::to_string(value2) + " 0x00").c_str());
	system(std::string("i2cset -y 2 0x40 " + std::to_string(value2 + 1) + " 0x00").c_str());
	system(std::string("i2cset -y 2 0x40 " + std::to_string(value2 + 2) + " " + std::to_string(valueL)).c_str());
	system(std::string("i2cset -y 2 0x40 " + std::to_string(value2 + 3) + " " + std::to_string(valueH)).c_str());
	//system("i2cset -y 2 0x40 0xFE " + std::to_string(value));
        system(("i2cset -y 2 0x40 0xFE " + std::to_string(value)).c_str());
	system("i2cset -y 2 0x40 0x00 0x80");
	system("i2cget -y 2 0x40 0x00");
			   
}
