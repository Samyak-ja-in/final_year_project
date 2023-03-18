#ifndef _ADC_H_
#define _ADC_H_

#include <fstream>
#include <string>

#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"

long int readADCRaw(int pin_number);
float readADCVoltage(int pin_number);

#endif