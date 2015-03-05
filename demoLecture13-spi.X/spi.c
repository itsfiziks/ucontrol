#include "p24FJ64GA002.h"
#include "spi.h"

#define SPI_DATA_OUT1 7
#define SPI_CLOCK_OUT1 8

void initSPI(){
    RPOR6bits.RP12R = SPI_DATA_OUT1; // pin 23
    RPINR20bits.SDI1R = 13; // pin 24
    RPOR7bits.RP14R = SPI_CLOCK_OUT1; // pin 25

    //Initialize the interrupts
    IFS0bits.SPI1IF = 0;
    IEC0bits.SPI1IE = 1;
    SPI1CON1bits.MSTEN = 1; // enable master mode
    SPI1CON2bits.SPIBEN = 1; // enhanced buffer mode
    SPI1STATbits.SPIROV = 0; // clear the buffer overflow bit
    SPI1STATbits.SPIEN = 1; //enable the SPI Module
}

/* Keep in mind that these are not the best way to implement an SPI
 * module. Check the code of the next lecture.
 */
void sendByte(char data){
    SPI1BUF = data;
}

char getByte(){
    return SPI1BUF;
}