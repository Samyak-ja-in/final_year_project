#include "uart.h"

UART::UART(int uart_no)
{
	if ((file = open((std::string("/dev/ttyO") + std::to_string(uart_no)).c_str(), O_RDWR | O_NOCTTY)) < 0)
	{
		perror("unable to open /dev/ttyO" + uart_no);
	}

	// uncomment the following for no wait for receive data
	/*
	 	if ((file = open((std::string("/dev/ttyO") + to_std::string(uart_no)).c_str(), O_RDWR | O_NOCTTY | O_NDELAY)) < 0)
		{
			perror("unable to open /dev/ttyO" + uart_no);
		}

	 */
	else
	{
		// Set up the communications uart_config : 9600 baud, 8-bit, enable receiver, no modem control lines
		tcgetattr(file, &uart_config);
		uart_config.c_cflag = B9600 | CS8 | CREAD | CLOCAL;
		uart_config.c_iflag = IGNPAR | ICRNL; // ignore partity errors, CR -> newline 
		tcflush(file, TCIFLUSH); // discard file information not transmitted
		tcsetattr(file, TCSANOW, &uart_config); // changes occur immmediately
	}
}

void UART::transmitMsg(const char *data)
{
	if (write(file, data, strlen(data)) < 0)
	{
		perror("unable to transmit msg data");
	}
}

void UART::transmitChar(char data)
{
	if (write(file, &data, 1) < 0)
	{
		perror("unable to transmit char data");
	}
}

void UART::receive(void)
{
	if (read(file, &receive_buffer, 100) < 0)
	{
		perror("unable to receive data");
	}
}

UART::~UART(void)
{
	close(file);
}
