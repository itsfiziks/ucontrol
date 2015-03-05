#include "p24FJ64GA002.h"
#include "spi.h"
#include <stdio.h>

#define SPI_DATA_OUT1 7
#define SPI_CLOCK_OUT1 8
#define SPI_SS LATBbits.LATB15
#define SPI_TRIS_SS TRISBbits.TRISB15

void initSPI(){
    RPOR6bits.RP12R = SPI_DATA_OUT1; // pin 23
    RPINR20bits.SDI1R = 13; // pin 24
    RPOR7bits.RP14R = SPI_CLOCK_OUT1; // pin 25

    IFS0bits.SPI1IF = 0; // We don't need to use the interrupt, but the flag should be down.
    
    SPI1CON1bits.SMP = 0; // PIC24F datasheet says to clear this
    SPI1CON1bits.CKP = 1; // Clock polarity (in accelerometer datasheet)
    SPI1CON1bits.CKE = 0; // Clock phase or edge (in accelerometer datasheet)
    SPI1CON1bits.MODE16 = 1; // Eanble 16-bit mode
    SPI1CON1bits.SMP = 1; // PIC24F datasheet says to clear this
    
    SPI1CON1bits.MSTEN = 1; // enable master mode
    SPI1STATbits.SPIROV = 0; // clear the buffer overflow bit
    SPI1STATbits.SPIEN = 1; // Enable the SPI module

    SPI_TRIS_SS = 0; // pin 26 is the Slave Select. Configure as output
    SPI_SS = 1; // Assert high
    
}

int spiWrite(int data){
    SPI_SS = 0; // Slave select must be low
    SPI1BUF = data;
    while(SPI1STATbits.SPIRBF == 0); // This waits until the transmission is finished.
    SPI_SS = 1;
    return SPI1BUF;
}