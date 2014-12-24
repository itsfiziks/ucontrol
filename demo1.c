// ******************************************************************************************* //
//
// File:         demo1.c
// Date:         12-23-2014
// Authors:      Garrett Vanhoy
//
// Description:  A simple demo using a state machine implementation to toggle between
//               the LEDs with a press of the on-board switch
//
// ******************************************************************************************* //

#include "p24fj64ga002.h"
#include <stdio.h>


_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF &
          BKBUG_ON & COE_ON & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )

typedef enum stateTypeEnum{
    led7,
    led6,
    led5,
    led4,
    waiting
} stateType;

//Easier to read and to change
#define LED4 LATBbits.LATB15
#define LED5 LATBbits.LATB14
#define LED6 LATBbits.LATB13
#define LED7 LATBbits.LATB12
#define SW1 PORTBbits.RB5

//Easier to remember and to read
#define ON 0
#define OFF 1
#define PUSHED 0
#define RELEASED 1

int main(void)
{
    //Create states to identify beh
    stateType state = led4;
    stateType nextState = led4;

    //First configure inputs and outputs
    TRISBbits.TRISB15 = 0;
    TRISBbits.TRISB14 = 0;
    TRISBbits.TRISB13 = 0;
    TRISBbits.TRISB12 = 0;
    TRISBbits.TRISB5 = 1;

    //Initialize the LED to be off
    LED4 = ON;
    LED5 = OFF;
    LED6 = OFF;
    LED7 = OFF;

    while(1)
    {
        if(SW1 == PUSHED){
            switch(state){
                case led4:
                    LED4 = OFF;
                    LED5 = ON;
                    state = waiting;
                    nextState = led5;
                    break;
                case led5:
                    LED5 = OFF;
                    LED6 = ON;
                    nextState = led6;
                    state = waiting;
                    break;
                case led6:
                    LED6 = OFF;
                    LED7 = ON;
                    nextState = led7;
                    state = waiting;
                    break;
                case led7:
                    LED7 = OFF;
                    LED4 = ON;
                    state = waiting;
                    nextState = led4;
                    break;
                case waiting:
                    if(SW1 == RELEASED) state = nextState;
                    break;
            }
        }
    }

    return 0;
}

// ******************************************************************************************* //
