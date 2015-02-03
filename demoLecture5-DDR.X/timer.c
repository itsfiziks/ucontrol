#include "p24fj64ga002.h"
#include "timer.h"

void initTimer1(){
    T1CONbits.TCKPS = 0b11; //prescalar 256
    IEC0bits.T1IE = 1; // Enable the interrupt
    IFS0bits.T1IF = 0; // Put the interrupt flag down
    T1CONbits.TON = 1; // Turn the timer 1 on
}