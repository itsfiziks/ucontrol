/*
* File:   uartComm.h
* Author: garrettvanhoy
*
* Created on December 27, 2014, 12:13 PM
*/

// ******************************************************************************************* //
// Defines to simply UART's baud rate generator (BRG) regiser
// given the osicllator freqeuncy and PLLMODE.

#define XTFREQ          7372800         	  // On-board Crystal frequency
#define PLLMODE         4               	  // On-chip PLL setting (Fosc)
#define FCY             (XTFREQ*PLLMODE)/2        // Instruction Cycle Frequency (Fosc/2)

#define BAUDRATE         115200
#define BRGVAL          ((FCY/BAUDRATE)/16)-1
// ******************************************************************************************* //

#include "p24fj64ga002.h"
#include "uartComm.h"
#include <stdio.h>

void initUART1(){

    //Peripheral Pin Mapping
    RPINR18bits.U1RXR = 9; //pin 18 UART Receive
    RPOR4bits.RP8R = 3; //pin 17 UART Transmit

    //Configuring the UART
    U1BRG  = BRGVAL;
    U1MODE = 0x8000;
    U1MODEbits.PDSEL = 2;
    U1STA  = 0x0440;

    //Putting the UART interrupt flag down.
    IFS0bits.U1RXIF = 0;
}

void initUART2(){
    //Peripheral Pin Mapping
    RPINR19bits.U2RXR = 14; //pin 25 UART 2 Receive
    RPOR6bits.RP13R = 5; //pin 24 UART 2 Transmit

    //Configuring the UART
    U2BRG  = BRGVAL;
    U2MODEbits.UARTEN = 1;
    U2MODEbits.UEN = 0;
    U2STA  = 0x0440;

    //Putting the UART interrupt flag down.
    IFS1bits.U2RXIF = 0;
}