#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>

//#include the library for the RFM69 module and the UART
#include "RFM69.h"
#include "RFM69registers.h"
#include "uart.h"
#include "millis.h"

#define NETWORKID 10 
#define NODEID     4 //Modify this value, 0-255


int main(void)
{
	init_debug_uart0();
	rfm69_init(433, NODEID, NETWORKID);    //init the RFM69 
	setPowerLevel(31); //set to maximum transmit power
	encrypt(NULL);
	promiscuous(1); //Receive from anyone on the network
	
	while(1)
   { 

   }
}
