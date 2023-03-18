Documentation

This repo contains code for analog to digital converter readings.
It has two functions readADCRaw() and readADCVoltage().
The readADCRaw() gives a long int as output which is a raw reading of ADC. range of output [0, 4095].
The readADCVolatage function gives the voltage reading at the adc pin. Range of output [0, 1.8] volts.
Both function takes integer as their input i.e pin_number of adc pin.