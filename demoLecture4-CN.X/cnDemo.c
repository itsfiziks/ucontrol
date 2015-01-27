// ******************************************************************************************* //
//
// File:         cnDemo
// Date:         12-29-2014
// Authors:      Garrett Vanhoy
//
// Description:  Pin 26 and pin 23 must be connected for this demo to work.
// In this demontration, one pin is configured as an input and another as an output.
// Then, the two pins are connected to each other. In this case, you can control the input
// on one pin using another pin. A change notification interrupt is use to capture
// the change on the pin.
// ******************************************************************************************* //

#include "p24fj64ga002.h"
#include <stdio.h>

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & BKBUG_ON & COE_ON & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )

int main(void)
{
    //These two are connected.
    TRISBbits.TRISB12 = 0;
    TRISBbits.TRISB15 = 1;

    //This will be used to toggle an LED.
    TRISBbits.TRISB13 = 0;

    //Now instead let's use CN interrupts
    IFS1bits.CNIF = 0; // Put the overall CN flag down (set it to 0)
    CNEN1bits.CN11IE = 1; // Enable the CN Interrupt on pin 23 (CN11)
    CNPU1bits.CN11PUE = 1; // Enable the internal pull-up resistor because one is not already there
    IEC1bits.CNIE = 1; // Enable the overall CN Interrupt
    
    while(1)
    {
        LATBbits.LATB12 = 1;
        LATBbits.LATB12 = 0;
    }
    return 0;
}

void _ISR _CNInterrupt(void){
    IFS1bits.CNIF = 0;
    LATBbits.LATB13 = 0; // If the CN interrupt is correctly enabled, the LED connected to RB13 should light up.
}