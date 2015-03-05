/*
 * File:   timer.c
 * Author: gvanhoy
 *
 * Created on December 30, 2014, 8:07 PM
 */

#include "p24FJ64GA002.h"
#include "timer.h"

#define F_CY 14745600.0
#define PRESCALAR 256.0

//Uses timer 2
void delayUs(unsigned int delay){
    TMR2 = 0;
    PR2 = 14*delay;
    IFS0bits.T2IF = 0;
    T2CONbits.TCKPS = 0;
    T2CONbits.TON = 1;
    while(IFS0bits.T2IF == 0);
    T2CONbits.TON = 0;
}

void delayS(float delay){
    TMR4 = 0;
    TMR5 = 0;
    unsigned long int prVal;
    prVal = (unsigned long int) (F_CY*delay)/PRESCALAR - 1;
    PR5 = (prVal >> 16);
    PR4 = (prVal << 16) >> 16;
    IFS1bits.T5IF = 0;
    T4CONbits.T32 = 1;
    T4CONbits.TCKPS = 0b11;
    T4CONbits.TON = 1;
    while(IFS1bits.T5IF == 0);
    T4CONbits.TON = 0;
}