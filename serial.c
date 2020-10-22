#include <avr/io.h>
#include <util/delay.h>

#include "serial.h"

void uart_init(unsigned int ubrr)
{
	/*Set baud rate */
	UBRR0H = (unsigned char)(ubrr >> 8); 
	UBRR0L = (unsigned char)ubrr;			
	/*Enable receiverand transmitter*/
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	/* Set frame format: 8data, 1 stop bit.*/
	UCSR0C = ((0 << USBS0) | (1 << UCSZ01) | (1 << UCSZ00));
}
void uart_putchar(unsigned char data)
{
	if (data == '\n')
	{
		while ((UCSR0A & (1 << UDRE0)) == 0);
		UDR0 = '\r';
	}
	while ((UCSR0A & (1 << UDRE0)) == 0);  /* Wait for empty transmit buffer */
	UDR0 = data;   /* Put data into buffer, sends the data */
}
void uart_putstr(const char* str) {
	/* sends the characters from the string one at a time to the USART */
		while (*str != 0)
		{
			uart_putchar(*str);
			str++;
		}
}
char uart_getchar(void)
{
	/* Wait for data to be received */
	while (!(UCSR0A & (1 << RXC0)));
	/* Get and return received data from buffer */
	return UDR0;
}

void uart_echo(void)
{ /*Receive and echo back char*/
	char n;
	while (1) {
		n = uart_getchar();
		uart_putchar(n);
	}
}