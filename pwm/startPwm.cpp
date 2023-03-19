#include "pwm.h"

int main(void)
{
	PWM my_pwm(PIN_1); // please note here input is pin 1

	// below function takes time in nano seconds
	my_pwm.initPwm(PWM_1, 1000000000, 500000000); // please note here input is pwm 1
	
	// start pwm
	my_pwm.startPwm(PWM_1);

	return 0;
}