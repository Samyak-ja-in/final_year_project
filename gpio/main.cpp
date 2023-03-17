#include "gpio.h"
#include <iostream>

using namespace ECC_gpio;

int main(void)
{
        GPIO g(66);
        g.gpioPinInit(66, OUTPUT);
        g.gpioWritePin(66, LOW);
        std::cout << "pin value : " << g.gpioReadPin(66) << std::endl;
        return 0;
}