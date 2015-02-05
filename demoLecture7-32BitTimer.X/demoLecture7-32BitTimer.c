// ******************************************************************************************* //
//
// File:         demoLecture7-32bitTimer.c
// Date:         2-5-2015
// Authors:      Garrett Vanhoy
//
// Description:  This uses bit-masking and shift operations to make a 32-bit timer
// that controls the blinking of and LED
// ******************************************************************************************* //


#include "p24fj64ga002.h"
#include "timer.h"
#include <stdio.h>


_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & BKBUG_ON & COE_ON & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )

#define PRESSED 0
#define RELEASED 1

int main(void)
{
    init32BitTimer();
    TRISBbits.TRISB15 = 0;
    
    while(1){
    }

}

void _ISR _T3Interrupt(void){
    IFS0bits.T3IF = 0;
    LATBbits.LATB15 = !LATBbits.LATB15;
}