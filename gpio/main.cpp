#include "gpio.h"
using namespace ECC_gpio;

int main(void)
{
	GPIO g(66);
	g.gpioPinInit(66, OUTPUT);
	g.gpioWritePin(66, LOW);	
	return 0;
}