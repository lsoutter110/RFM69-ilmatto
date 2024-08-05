//Written by Jonathan Goh Yeh Wei to initialise, transmit and receive UART through the Il Matto Board (Atmega 644p microcontroller)
#include "UART.h"

void uart_init(void) {
    UBRR0H = (F_CPU/(BAUD_RATE*16L)-1) >> 8; //Set baud rate
	UBRR0L = (F_CPU/(BAUD_RATE*16L)-1);
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);
	UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);
}

void uart_Transmit(unsigned char data) {
    while (!(UCSR0A & (1 << UDRE0)));// Wait for empty transmit buffer
    UDR0 = data; // Put data into buffer and send
}

unsigned char uart_Receive(void) {
    while (!(UCSR0A & (1 << RXC0))); // Wait for data to be received
    return UDR0; // Get and return received data from buffer
}

void uart_Transmit_string (char *str){ //function to print a string of characters on the UART terminal
	int i;
	for (i=0; str[i]; i++) {
		uart_Transmit(str[i]);
	}
}