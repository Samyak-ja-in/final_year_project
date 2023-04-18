#include <iostream>
#include <string>
#include <fstream>

using namespace std;
 
int main(void)
{
	system("i2cdetect -l");
	system("i2cdetect -a -y -r 2");
	system("i2cset -y 2 0x68 0x6B 0x00");
	system("i2cset -y 2 0x68 0x1B 0xE7");
        system("i2cset -y 2 0x68 0x1C 0xF7");
        system("i2cget -y 2 0x68 0x3B");
        system("i2cget -y 2 0x68 0x3F");
        system("i2cget -y 2 0x68 0x3D");
	system("i2cget -y 2 0x68 0x3E");
        system("i2cget -y 2 0x68 0x3F");
        system("i2cget -y 2 0x68 0x40");
        system("i2cget -y 2 0x68 0x41");
        system("i2cget -y 2 0x68 0x42");
        system("i2cget -y 2 0x68 0x43");
        system("i2cget -y 2 0x68 0x44");
        system("i2cget -y 2 0x68 0x45");
	system("i2cget -y 2 0x68 0x46");
	system("i2cget -y 2 0x68 0x47");
	system("i2cget -y 2 0x68 0x48");
	system("i2cset -y 2 0x68 0x1B 0x07");
	system("i2cget -a -y 2 0x68 0x1C 0x17");
	return 0;
}
