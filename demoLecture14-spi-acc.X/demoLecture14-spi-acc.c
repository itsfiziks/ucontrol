// ******************************************************************************************* //
//
// File:         demoLecture14-spi-acc.c
// Date:         3-3-2015
// Authors:      Garrett Vanhoy
// Description: This is meant to communicate with the ADXL345 accelerometer. However,
// this code is incomplete.
// ******************************************************************************************* //
#include "p24FJ64GA002.h"
#include "uart.h"
#include "spi.h"
#include "timer.h"
#include "accelerometer.h"
#include <stdio.h>

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & BKBUG_ON & COE_ON & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )

volatile int data = 'c';
volatile int print = 0;

int main(void)
{
    initSPI();
    initUART();
    initACC();
    
    while(1)
    {
        data = getX();
        printf("%4x\n", data);
        delayUs(1000);
    }

    return 0;
}

void _ISR _SPI1Interrupt(void){
    IFS0bits.SPI1IF = 0;
}