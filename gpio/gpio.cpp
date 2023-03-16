#include "gpio.h"

gpio::GPIO(int pin_number)
{
	std::cout << "exporting the pin" + string(pin_number) << std::endl;
	system(string("echo" + string(pin_number) + " > " + string(path) + "export").cstr());
}

gpio::gpioInit(int pin_number, string pin_direction, string pin_mode = "none")
{
	fstream file;
    file.open((string(path) + "/gpio" + string(pin_number) + "/direction").c_str(), fstream::out);
    file << pin_direction;
    file.close();
}

gpio::gpioWritePin(int pin_number, int pin_status)
{
	fstream file;
    file.open((string(path) + "/gpio" + string(pin_number) + "/value").c_str(), fstream::out);
    file << pin_status;
    file.close();
}

ECC_gpio::gpio::gpioReadPin(int pin_number)
{

}

ECC_gpio::gpio::~GPIO(int pin_number)
{

}