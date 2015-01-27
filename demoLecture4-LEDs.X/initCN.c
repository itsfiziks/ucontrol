#include "p24fj64ga002.h"
#include "initCN.h"

void initCNForSW1(){
    /* Initialize the pin on the development board to be an input. According to
     * the datasheet, this is RB5 or pin 14
     */
    TRISBbits.TRISB5 = 1;

    //Put the overall CN Interrupt flag down (set it to 0)
    IFS1bits.CNIF = 0;

    //Enable the overall change notification interrupt
    IEC1bits.CNIE = 1;

    /* Enable the change notification interrupt for the switch 1 connected to
     * the development board. This corresponds to CN27 according to the PIC24F
     * datasheet. The internal pull-up should not be used for the switch
     * on the development board because one is already there.
     */
    CNEN2bits.CN27IE = 1;
}