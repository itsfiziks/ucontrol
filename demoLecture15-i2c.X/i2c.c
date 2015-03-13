/*
 * File:   i2c.c
 * Author: gvanhoy
 *
 * Created on March 10, 2015, 9:08 AM
 */
#include "p24FJ64GA002.h"

#define WRITE 0
#define READ 1

void initI2C(){
//    Map the pins properly
    TRISBbits.TRISB2 = 0;
    TRISBbits.TRISB3 = 0; // probbably not necessary
    AD1PCFGbits.PCFG4 = 1;
    AD1PCFGbits.PCFG5 = 1;
    
    I2C2CONbits.I2CEN = 1;
    IFS3bits.MI2C2IF = 0;
    I2C2BRG = 10000;
}

void sendI2C(char data, char address){
    //Start bit
    I2C2CONbits.SEN = 1;
    //wait
    while(IFS3bits.MI2C2IF == 0);
    IFS3bits.MI2C2IF = 0;
    //Address
    I2C2TRN = address << 1 | WRITE;
    //wait
    while(I2C2STATbits.TRSTAT == 1);
    //Check for Ack
    if(I2C2STATbits.ACKSTAT == 1);
    //Data
    I2C2TRN = data;
    //wait
    while(I2C2STATbits.TRSTAT == 1);
    //Check for Ack
    if(I2C2STATbits.ACKSTAT == 1);
    //Stop
    I2C2CONbits.PEN = 1;
    //wait
    while(IFS3bits.MI2C2IF == 0);
    IFS3bits.MI2C2IF = 0;
}

char receiveI2C(char address){
    char c;
    //Start bit
    I2C2CONbits.SEN = 1;
    //wait
    while(IFS3bits.MI2C2IF == 0);
    IFS3bits.MI2C2IF = 0;
    //Address
    I2C2TRN = address << 1 | READ;
    //wait
    while(I2C2STATbits.TRSTAT == 1);
    //Check for Ack
    if(I2C2STATbits.ACKSTAT == 1);
    //wait
    while(I2C2STATbits.RBF == 0);
    //Check for Ack
    c = I2C2RCV;
    //Acknowledgement
    I2C2CONbits.ACKDT = 1; //ACK or NACK
    I2C2CONbits.ACKEN = 1; //enable acknowledge
    while(IFS3bits.MI2C2IF == 0);
    IFS3bits.MI2C2IF = 0;
    //Stop
    I2C2CONbits.PEN = 1;
    //wait
    while(IFS3bits.MI2C2IF == 0);
    IFS3bits.MI2C2IF = 0;
    return c;
}