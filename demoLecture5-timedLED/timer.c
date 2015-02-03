/*
 * File:   timer.h
 * Author: Garrett Vanhoy
 *
 * Created on January 29, 2015, 10:13 AM
 */

#include "p24fj64ga002.h"
#include "timer.h"

#define FCY 14745600.0
#define ONE_MILLISECOND 57
#define TIME_DELAY .025

/* Create 25 millisecond timer
 */
void initTimer1(){
    // This is so that we do not have to calculate PR by hand.
    unsigned int prVal = (FCY*TIME_DELAY)/256.0 - 1;
    PR1 = prVal;
    T1CONbits.TCKPS = 0b11; //prescalar 256
    IEC0bits.T1IE = 1; // Enable the interrupt
    IFS0bits.T1IF = 0; // Put the interrupt flag down
    T1CONbits.TON = 1; // Turn the timer 1 on
}