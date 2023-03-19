#ifndef _PWM_H_
#define _PWM_H_

#include <fstream>
#include <string>

#define PWM_PATH "/sys/class/pwm/pwm-"

#define PWM_0 "0:0"
#define PWM_1 "1:0"
#define PWM_2 "1:1"
#define PWM_3 "3:0"
#define PWM_4 "4:0"
#define PWM_5 "4:1"
#define PWM_6 "6:0"
#define PWM_7 "7:0"
#define PWM_8 "7:1"

#define PIN_0 "P9.42"
#define PIN_1 "P9.22"
#define PIN_2 "P9.21"
#define PIN_3 // unknown: maybe it is not available for use on the board itself
#define PIN_4 "P9.14"
#define PIN_5 "P9.16"
#define PIN_6 "P9.28" // before using this pin as pwm user must have to disable the HDMI :(
#define PIN_7 "P8.19"
#define PIN_8 "P8.13"

class PWM
{
	unsigned char pwm_number;
	public:
		PWM(std::string pin_number);
		virtual void initPwm(std::string pwm_number, int period, int duty_cycle, std::string polarity = "normal");
		virtual void startPwm(std::string pwm_number);
		virtual void stopPwm(std::string pwm_number);
		~PWM();
	
};

#endif