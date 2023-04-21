#include "uart.h"

UART::UART(int uart_no)
{
	system("config-pin P9_24 uart");
	system("config-pin P9_26 uart");
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
	if ((bytes_read = read(file, &receive_buffer, 100)) < 0)
	{
		perror("unable to receive data");
	}
}

void UART::printReceive(void)
{
	for (int i = 0; i < bytes_read; i++)
	{
		std::cout << receive_buffer[i];
	}
	std::cout << std::endl;
}

void UART::executeReceivedCmd(void)
{
	std::string cmd;
	//unsigned char cmd[100] = {0};
	for (int i = 0; i < bytes_read; i++)
	{
		//cmd = cmd + receive_buffer[i];
		//std::cout << cmd[i] << std::endl;
		//strcat(cmd, receive_buffer[i]);
		cmd.append(std::to_string(char(receive_buffer[i])));
		//cmd = reinterpret_cast<const char*>(receive_buffer[i]);

		//std::cout << 
	}
	//std::cout << static_cast<char>(stoi(cmd)) << std::endl;
	//system(cmd);
	//std::cout << cmd << std::endl;
	//std::cout << cmd.length() << std::endl;
}

UART::~UART(void)
{
	close(file);
}
