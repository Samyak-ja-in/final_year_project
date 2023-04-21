#include "uart.h"

int main(void)
{
	UART esp01(UART_1);
	while (1)
	{
		esp01.receive();
		esp01.printReceive();
		esp01.executeReceivedCmd();
	}
	return 0;
}
