#include "gpio.h"

ECC_gpio::GPIO::GPIO(int pin_number)
{
        std::cout << "exporting the pin" + std::to_string(pin_number) << std::endl;
        system(string("echo " + std::to_string(pin_number) + " > " + string(path) + "export").c_str());
        std::cout <<  "echo " + std::to_string(pin_number) + " > " + string(path) + "export" << std ::endl;
}

void ECC_gpio::GPIO::gpioPinInit(int pin_number, string pin_direction, string pin_mode)
{
        std::fstream file;
        file.open((string(path) + "gpio" + std::to_string(pin_number) + "/direction").c_str(), std::fstream::out);
        file << pin_direction.c_str();
        file.close();
}

void ECC_gpio::GPIO::gpioWritePin(int pin_number, int pin_status)
{
        std::fstream file;
        file.open((string(path) + "gpio" + std::to_string(pin_number) + "/value").c_str(), std::fstream::out);
        file << pin_status;
        file.close();
}

int ECC_gpio::GPIO::gpioReadPin(int pin_number)
{
        return 0;
}

ECC_gpio::GPIO::~GPIO()
{

}