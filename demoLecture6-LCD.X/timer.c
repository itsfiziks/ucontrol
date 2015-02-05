/*
 * File:   initTimer.c
 * Author: gvanhoy
 *
 * Created on December 30, 2014, 8:07 PM
 */

#include "p24fj64ga002.h"
#include "timer.h"

#define MAX_INT 65535
#define FCY 14745600
#define PRESCALAR_T1_T3 256
#define ONE_SECOND FCY/PRESCALAR_T1_T3 - 1

//Uses timer 1
void initTimer1(){
    // Clear Timer value (i.e. current timer value) to 0
    TMR1 = 0;
    PR1 = ONE_SECOND;
    IFS0bits.T1IF = 0;
    IEC0bits.T1IE = 1;
    T1CONbits.TCKPS = 3;
    T1CONbits.TON = 1;
}

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