// ******************************************************************************************* //
//
// File:         floatingPin.c
// Date:         12-30-2014
// Authors:      
//
// Description:  Measure the pin voltage while it is not connected to anything.
// it shouldn't be zero even though nothing is connected. It's state is not defined.
// It helps to have a jumper cable for this to be attached to RB12 (Pin 23). It adds noise.
// ******************************************************************************************* //

#include "p24fj64ga002.h"
#include <stdio.h>


_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & BKBUG_ON & COE_ON & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )

int main(void){
    
    //Set RB12 (pin 23) to be an input and measure the voltage on the pin.
    TRISBbits.TRISB12 = 1;

    while(1)
    {

    }
    
    return 0;
}