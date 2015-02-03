// ******************************************************************************************* //
//
// File:         demoLecture5-oneButtonDDR.c
// Date:         1-29-2015
// Authors:      Garrett Vanhoy
// ******************************************************************************************* //

#include "p24fj64ga002.h"
#include "timer.h"
#include "initUART.h"
#include "initSW1.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & BKBUG_ON & COE_OFF & ICS_PGx1 &
          FWDTEN_OFF & WINDIS_OFF & FWPSA_PR128 & WDTPS_PS32768 )

_CONFIG2( IESO_OFF & SOSCSEL_SOSC & WUTSEL_LEG & FNOSC_PRIPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
          IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_XT )

#define ONE_SECOND 57599
#define MIN_WAIT ONE_SECOND
#define RAND_WAIT ONE_SECOND


typedef enum stateTypeEnum{
    printWait, printRandWait, printButtonPress, printSuccess, printFailure, printReset,
            wait, randWait, buttonPress, success, failure, reset
} stateType;

volatile stateType state = wait;
volatile unsigned int score;

int main(void){

    initUART();
    initTimer1();
    initSW1();

    srand(time(NULL));

    score = -1;
    
    while(1){
        switch(state){
            case printWait:
                printf("wait for it..\n");
                state = wait;
                break;
            case wait:
                PR1 = ONE_SECOND;
                break;
            case printRandWait:
                printf("Here it comes...\n");
                state = randWait;
                break;
            case randWait:
                score = score + 1;
                rand();
                PR1 = rand();
                if(PR1 < RAND_WAIT) PR1 = RAND_WAIT;
                break;
            case printButtonPress:
                printf("Press the button!\n");
                state = buttonPress;
                break;
            case buttonPress:
                PR1 = MIN_WAIT;
                break;
            case printSuccess:
                printf("Good job!\n");
                state = success;
            case success:
                break;
            case printFailure:
                printf("Failed! Score: %d\n", score);
                state = failure;
            case failure:
                break;
            case printReset:
                printf("Press once more to reset.\n");
                state = reset;
                break;
            case reset:
                PR1 = ONE_SECOND;
                break;
        }
    }

	return 0;
}

void __attribute__((interrupt,auto_psv)) _T1Interrupt(void){
    // Clear Timer 1 interrupt flag to allow another Timer 1 interrupt to occur.
    IFS0bits.T1IF = 0;
    if(state == wait) state = printRandWait;
    else if(state == randWait)state = printButtonPress;
    else if(state == buttonPress) state = printFailure;
    else if(state == success) state = printWait;
    else if(state == reset) state = printFailure;
}

void __attribute__((interrupt,auto_psv)) _CNInterrupt(void){
    // Clear CN interrupt flag to allow another CN interrupt to occur.
    IFS1bits.CNIF = 0;
    if(state == buttonPress && PORTBbits.RB5 == 1)state = printSuccess;
    else if(state == failure && PORTBbits.RB5 == 1) state = printReset;
    else if(state == reset && PORTBbits.RB5 == 1){
        state = printWait;
        score = -1;
    }
}

// ******************************************************************************************* //
