#include "p24FJ64GA002.h"
#include "timer.h"

#define TIME_DELAY 5
#define F_CY 14745600
#define PRESCALAR 64

/* Using a 32-bit timer
 */
void init32BitTimer(){
    long int prVal;
    prVal = (F_CY*TIME_DELAY)/PRESCALAR - 1;
    PR3 = (prVal >> 16);
    PR2 = (prVal << 16) >> 16;
    T2CONbits.T32 = 1;
    T2CONbits.TCKPS = 0b10;
    IEC0bits.T3IE = 1;
    IFS0bits.T3IF = 0;
    T2CONbits.TON = 1;
}

