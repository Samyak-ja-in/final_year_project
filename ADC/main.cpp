#include <iostream>
#include "adc.h"

int main(void)
{
	std::cout << readADCRaw(0) << std::endl;
	std::cout << readADCVoltage(0) << std::endl;
	// std::cout << readADCRaw(1) << std::endl;
	// std::cout << readADCRaw(2) << std::endl;
	// std::cout << readADCRaw(3) << std::endl;
	// std::cout << readADCRaw(4) << std::endl;
	// std::cout << readADCRaw(5) << std::endl;
	// std::cout << readADCRaw(6) << std::endl;
	// std::cout << readADCRaw(7) << std::endl;
	return 0;
}