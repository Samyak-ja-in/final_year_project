#include "pwm.h"

PWM::PWM(std::string pin_number)
{
	system(("config-pin " + std::string(pin_number) + " pwm").c_str());
}

void PWM::initPwm(std::string pwm_number, int period, int duty_cycle, std::string polarity)
{
	std::fstream file;
	file.open((std::string(PWM_PATH) + std::string(pwm_number) + "/period").c_str(), std::fstream::out);
    	file << period;
    	file.close();
    	file.open((std::string(PWM_PATH) + std::string(pwm_number) + "/duty_cycle").c_str(), std::fstream::out);
    	file << duty_cycle;
    	file.close();
}

void PWM::startPwm(std::string pwm_number)
{
	std::fstream file;
    	file.open((std::string(PWM_PATH) + std::string(pwm_number) + "/enable").c_str(), std::fstream::out);
    	file << 1;
    	file.close();
}

void PWM::stopPwm(std::string pwm_number)
{
	std::fstream file;
    	file.open((std::string(PWM_PATH) + std::string(pwm_number) + "/enable").c_str(), std::fstream::out);
    	file << 0;
    	file.close();
}

PWM::~PWM()
{
	// uncomment if want to reset every pin to default value.
	// changes can be made according to user requirement.
	// std::fstream file;
    	// file.open((std::string(PWM_PATH) + std::string(pwm_number) + "/enable").c_str(), std::fstream::out);
    	// file << 0;
    	// file.close();
	// system(("config-pin " + std::string(pin_number) + " default").c_str()); // reset pin to default 
}
