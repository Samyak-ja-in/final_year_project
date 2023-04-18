#include "uart.h"

int main(void)
{
	UART hc05(UART_4);
	hc05.transmitChar('K');
	hc05.transmitChar(9 + '0');
	hc05.transmitMsg("Hi there !\n");
	hc05.transmitMsg("This is Tushar Gupta");
	while (1)
	{
		hc05.receive();
		// hc05.printReceiveData();
		std::cout << hc05.receive_buffer[0] << std::endl;	
	}
	return 0;
}
