// ******************************************************************************************* //
//
// File:         demoLecture2.c
// Date:         1-20-2015
// Authors:      Garrett Vanhoy
//
// Description:  Using TRISTATE, PORT, and LATCH to control and LED and a switch
// ******************************************************************************************* //


#include "p24fj64ga002.h"
#include <stdio.h>


_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & BKBUG_ON & COE_ON & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )

#define PRESSED 0
#define RELEASED 1
int main(void)
{
    TRISBbits.TRISB5 = 0; // pin 14, switch 1, output
    TRISBbits.TRISB15 = 1; // pin 26, led 4, input

    while(1){
        // Turn off the LED if the switch is pressed. Turn it on otherwise.
        if(PORTBbits.RB5 == PRESSED) LATBbits.LATB15 = 1;
        else if(PORTBbits.RB5 == RELEASED) LATBbits.LATB15 = 0;
    }

}