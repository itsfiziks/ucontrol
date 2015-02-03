// ******************************************************************************************* //
//
// File:         demoLecture5-timedLED.c
// Date:         1-29-2015
// Authors:      Garrett Vanhoy
//
// Description: Blink and LED using a timer interrupt.
// ******************************************************************************************* //


#include "p24fj64ga002.h"
#include "timer.h"
#include <stdio.h>

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & BKBUG_ON & COE_ON & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )

int main(void)
{
    TRISBbits.TRISB15 = 0;
    LATBbits.LATB15 = 1;
    initTimer1();
    while(1){
        
    }
}

/* This will be called when the timer 1 interrupt flag is raised. Toggle the LED at that time.
 */
void _ISR _T1Interrupt(){
    IFS0bits.T1IF = 0;
    LATBbits.LATB15 = !LATBbits.LATB15;
}