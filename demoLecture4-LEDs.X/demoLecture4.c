// ******************************************************************************************* //
//
// File:         demoLecture4.c
// Date:         12-30-2015
// Authors:      Garrett Vanhoy
//
// Description:  Using CN interrupts to change LEDs
// ******************************************************************************************* //

#include "p24fj64ga002.h"
#include "initLEDs.h"
#include "initCN.h"
#include <stdio.h>

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & BKBUG_ON & COE_ON & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )

typedef enum stateTypeEnum{
    led4,
    led5,
    led6,
    led7
} stateType;

volatile stateType curState;

int main(void)
{
    initLEDs();
    initCNForSW1();
    curState = led4;

    while(1)
    {
        switch(curState){
            case led4:
                turnOnLED(4);
                break;
            case led5:
                turnOnLED(5);
                break;
            case led6:
                turnOnLED(6);
                break;
            case led7:
                turnOnLED(7);
                break;
        }
    }

    return 0;
}

void _ISR _CNInterrupt(void){
    IFS1bits.CNIF = 0;
    if(PORTBbits.RB5 == RELEASED){
        if(curState == led4) curState = led5;
        else if(curState == led5) curState = led6;
        else if(curState == led6) curState = led7;
        else if(curState == led7) curState = led4;
    }
}