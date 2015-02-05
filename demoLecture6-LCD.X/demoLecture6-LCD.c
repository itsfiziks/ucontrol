// ******************************************************************************************* //
//
// File:         demoLecture6-LCD.c
// Date:         12-30-2014
// Authors:      Garrett Vanhoy
//
// Description: This implements the read and write functionality of the LCD display.
// First, the demonstration should be used to show how to create a delay using a timer.
// Then using the LCD timing diagram, write the writeFourBitsLCD();
// Then also make printCharLCD(char c);
//
//
// IMPORTANT NOTE:
// initLCD is not included in this code because it is part of Lab 1. This code will not work
// with the LCD on its own.
// ******************************************************************************************* //

#include "p24fj64ga002.h"
#include <stdio.h>
#include "lcd.h"

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & BKBUG_ON & COE_OFF & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )


// ******************************************************************************************* //

int main(void)
{
//        initLCD();
//        printCharLCD('c');
	while(1)
	{
//                printCharLCD((char) 0b10100101);
	}
	return 0;
}
