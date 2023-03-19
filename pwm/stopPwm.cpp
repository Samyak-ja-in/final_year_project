#include "pwm.h"

int main(void)
{
	PWM my_pwm(PIN_1);
	my_pwm.stopPwm(PWM_1);
	return 0;
}