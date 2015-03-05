// ******************************************************************************************* //
// File:         demoLecture9-UARTchat.c
// Date:         2-12-2014
// Authors:      Garrett Vanhoy
//
// Description: Demonstrating a UART chat application. Another PIC with this same code must be used.
// ******************************************************************************************* //

#include "p24fj64ga002.h"
#include "uartComm.h"
#include "timer.h"
#include <stdio.h>

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & BKBUG_ON & COE_OFF & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )

volatile char receiveChar;

int main(void)
{

    initUART1();
    initUART2();
    char transmitCharacter = 'c';
    
    while(1)
    {
        U2TXREG = transmitCharacter;
    }

    return 0;
}

/* This is only called if something is sent.
 */
void _ISR _U2RXInterrupt(void){
    IFS1bits.U2RXIF = 0;

    receiveChar = U2RXREG;
    printf("%c", receiveChar);
}