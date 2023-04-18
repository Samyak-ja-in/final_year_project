#ifndef _UART_H_
#define _UART_H_

#include <iostream>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <cstring>
#include <string>

enum com_module
{
	UART_1 = 1,
	UART_2 = 2,
	// UART3 is not present for user use in BBB revC
	UART_4 = 4,
	UART_5 = 5
};

class UART
{
	private:
		int file;	
		struct termios uart_config;
	public:
		unsigned char receive_buffer[100] = {'0'};
		
		UART(int uart_no);
		virtual void transmitMsg(const char *data);
		virtual void transmitChar(char data);
		virtual void receive(void);
		~UART(void);
};

#endif
