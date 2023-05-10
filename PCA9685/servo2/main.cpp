#include "servo.h"

int main(void)
{
	rotateServo(0, 24, 50);
	rotateServo(4, 24, 50);
	rotateServo(8, 50, 90);
	rotateServo(12, 100, 10);
	return 0;
}
