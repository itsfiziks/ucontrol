#include "p24fj64ga002.h"
#include "initLEDs.h"

/* Set the pins connected to the LEDs to be outputs. Turn them off by default.
 */
void initLEDs(){
    TRISB &= 0x0FFF;
    LATB |= 0xF000;
}

/* This is a nice helper function which turns on a particular LED
 */
void turnOnLED(int led){
    LATB |= 0xF000;
    LATB ^= (0x1 << (19 - led));
}
