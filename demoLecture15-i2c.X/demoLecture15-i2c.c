// ******************************************************************************************* //
//
// File:         demoLecture15-i2c.c
// Date:         3-10-2015
// Authors:      Garrett Vanhoy
// Description:  Initializing the I2C module
// ******************************************************************************************* //
#include "p24FJ64GA002.h"
#include "i2c.h"
#include "timer.h"
#include <stdio.h>

_CONFIG1( JTAGEN_OFF &  GCP_OFF & GWRP_OFF & BKBUG_ON & COE_ON & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )

typedef enum stateTypeEnum{
    start, data, stop, ack, wait
} stateType;

volatile stateType state = start;

int main(void)
{
    TRISBbits.TRISB15 = 0;
    LATBbits.LATB15 = 1;
    
    initI2C();
    char c;
    while(1)
    {
        sendI2C(0x1D, 0b11110000);
        delayUs(1000);
    }

    return 0;
}

void _ISR _MI2C2Interrupt(void){
    IFS3bits.MI2C2IF = 0;
}