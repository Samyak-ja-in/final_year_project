#include "adc.h"

long int readADCRaw(int pin_number)
{
	std::fstream file;
	file.open((std::string(ADC_PATH) + std::to_string(pin_number) + "_raw").c_str(), std::fstream::in);
	std::string adc_raw_data;
	getline(file, adc_raw_data);
    file.close();
    return std::stol(adc_raw_data);
}

float readADCVoltage(int pin_number)
{
	std::fstream file;
	file.open((std::string(ADC_PATH) + std::to_string(pin_number) + "_raw").c_str(), std::fstream::in);
	std::string adc_raw_data;
	getline(file, adc_raw_data);
    file.close();
    return ((std::stol(adc_raw_data)*1.8)/4096.00);
}