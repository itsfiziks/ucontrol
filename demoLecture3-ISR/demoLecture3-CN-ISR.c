// ******************************************************************************************* //
//
// File:         demoLecture3-CN-ISR.c
// Date:         1-22-2015
// Authors:      Garrett Vanhoy
//
// Description:  Using change notifications and an ISR to control LED
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
    IEC1bits.CNIE = 1; //Enable the overall CN Interrupt to use the ISR
    IFS1bits.CNIF = 0;
    CNEN2bits.CN27IE = 1; //Enable CN for pin 14, switch 1, CN27

    while(1){

    }

}

/*
 * This is called whenever a change is detected on any of the pins
 * that have CN interrupts enabled. Or, whenever the CNIF flag is raised. This
 * flag should not be raised in software, it is raised in hardware.
 */
void _ISR _CNInterrupt(void){
    //Put the interrupt flag down first, always.
    IFS1bits.CNIF = 0;
    if(PORTBbits.RB5 == PRESSED) LATBbits.LATB15 = !LATBbits.LATB15;
}