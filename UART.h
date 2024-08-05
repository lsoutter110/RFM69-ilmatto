//Written by Jonathan Goh Yeh Wei to initialise, transmit and receive UART through the Il Matto Board (Atmega 644p microcontroller)
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>
#define BAUD_RATE 9600

void uart_init(void);
void uart_Transmit(unsigned char data);
unsigned char uart_Receive(void);
void uart_Transmit_string (char *str);

