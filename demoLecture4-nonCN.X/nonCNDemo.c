// ******************************************************************************************* //
//
// File:         nonCNDemo.c
// Date:         12-29-2014
// Authors:      Garrett Vanhoy
//
// Description:  YOU MUST CONNECT RB12 and RB15 in this to get this demo to work properly.
// ******************************************************************************************* //

#include "p24fj64ga002.h"
#include <stdio.h>


_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & BKBUG_ON & COE_ON & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )

int main(void)
{
    TRISBbits.TRISB12 = 0;
    TRISBbits.TRISB13 = 0;
    TRISBbits.TRISB15 = 1;
    LATBbits.LATB13 = 1;
    
    while(1)
    {
        //Start at 1
        LATBbits.LATB12 = 1;
        //Go back to zero
        LATBbits.LATB12 = 0;
        //Go back to one
        LATBbits.LATB12 = 1;
        //This if statement should definitely work...
        if(PORTBbits.RB15 == 1){
            //Turn on the LED if it does.
            LATBbits.LATB13 = 0;
            //But it doesn't...
        }
    }
    return 0;
}