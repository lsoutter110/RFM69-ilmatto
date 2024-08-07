# RFM69-ilmatto #
Original library is written for arduino by [LowPowerLab](https://github.com/LowPowerLab/RFM69). This is a C ported version for the Il Matto development board, and includes some utilies you may find useful (UART communication)

</br>

## I/O pin connections: ##

You should be using the breakout board supplied as part of the lab

| RF Module | Microcontroller |
| --------- | --------------- |
|MOSI |	MOSI |
| MISO | MISO |
| SCK | SCK |
| SS | SS |
| DIO0 | Any interrupt enabled pin |

</br>

## Function Description: ##

1.	**rfm69_init(*uint16_t freqBand, uint8_t nodeID, uint8_t networkID*):** Initializes rfm69 module. This function is called at the beginning of the program. Initializes IDs, modes etc. It takes three parameters. First one freqBand. You have to choose among 315, 433, 868 and 915. These specifies frequency in MHz. nodeID is analogues to device ID. Each RF module will have unique nodeID. Value must be within 0 to 255. Then comes notworkID. Say, a system has 5 rf modules to communicate with each other. All the modules must be in same networkID . networkID value range 0~255.
2.	**setAddress(*uint8_t addr*):** Sets nodeID.
3.	**setNetwork(*uint8_t networkID*):** Sets networkID.
4.	**send(*uint8_t toAddress, const void\* buffer, uint8_t bufferSize):** Transmits data to another node. First argument is toAddress that is address off receiver node/gateway. In buffer you can put any kind of buffer like string or array etc.
5.	**receiveDone():**  Returns 1 if any data is present in receive buffer.
6.	**getFrequency():** Gets frequency Band.
7.	**setFrequency(*uint32_t freqHz*):** Sets frequency band. You can set frequency other than 315, 433, 868, 915 MHz through this function. Unit is Hz i.e 433000000. 
8.	**encrypt(*const char\* key*):** All device need same encryption key. And length must be 16. If you need no encryption just put 0 in argument. 
9.	**readRSSI(*uint8_t forceTrigger=0*):** You want to know received signal strength? :D
10.	**setPowerLevel(*uint8_t level*):** Sets transmit power. Range 0~31.
11.	**rcCalibration():** Calibrate the internal RC oscillator for use in wide temperature variations - see datasheet section 4.3.5. RC Timer Accuracy. Not tested yet.
12.	**promiscuous(*uint8_t onOff*):** 1 or 0. If on, module receives data indiscriminately. In another word, it receives all data in network when set to 1.

</br>

## Basic Operation: ##
#### Transmit data: ####

```
rfm69_init(freq, nodeID, networkID)
setPowerLevel(0~31)
send(toNodeID, buffer, bufferLen, 0 or 1 )
```

#### Receive data: ####

```
rfm69_init(freq, nodeID, networkID)
setPowerLevel(0~31)
mainloop
    if receiveDone() then
        extract received data from DATA buffer
```

## Utilities

If you wish to use the UART pins on PD0 (RX) and PD1 (TX) for debugging and communication purposes, include "uart.h" in `main.c` and be sure to call `init_debug_uart0();` at the start of your program. After that you can use [printf](https://www.geeksforgeeks.org/printf-in-c/) and [scanf](https://www.geeksforgeeks.org/scanf-in-c/) to handle input and output.

If you wish to get the system uptime in milliseconds, include "millis.h" in `main.c`. The millisecond counter is already initialised by the RFM69 subsystem, so no additional initialisation steps are needed. The system uptime can be returned from `millis();` as an unsigned long (uint32_t).


## Note
The millisecond timer occupies Timer 1 on the Il matto and thus it is unavailable for your program.