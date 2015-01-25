// ******************************************************************************************* //
//
// File:         demoLecture3-polling.c
// Date:         1-22-2015
// Authors:      Garrett Vanhoy
//
// Description:  Using change notifications to control and LED and a switch
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
//    IEC1bits.CNIE = 1; // With 'polling' you MUST not enable this.
    IFS1bits.CNIF = 0;
    CNEN2bits.CN27IE = 1; //Enable CN for pin 14, switch 1, CN27

    while(1){
        //Toggle the LED every time the switch is pressed or released.
        if(IFS1bits.CNIF == 1) LATBbits.LATB15 = !LATBbits.LATB15;
        //Toggle the LED every time the switch is pressed only.
//        if(IFS1bits.CNIF == 1 && PORTBbits.RB5 == 0) LATBbits.LATB15 = !LATBbits.LATB15;
    }

}