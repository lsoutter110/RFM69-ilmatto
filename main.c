#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>

//#include the library for the RFM69 module and the UART
#include "RFM69.h"
#include "RFM69registers.h"
#include "UART.h"

#define NETWORKID 10 
#define NODEID     4 //Modify this value, 0-255


int main(void)
{
	uart_init();    //init uart	
	rfm69_init(433, NODEID, NETWORKID);    //init the RFM69 
	setPowerLevel(31); //set to maximum transmit power
	encrypt(NULL);
	promiscuous(1); //Receive from anyone on the network
	while(1)
   { 
         uart_Transmit_string("write here your code \n\r");
   }
}
