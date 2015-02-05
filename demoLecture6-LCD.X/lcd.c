/*
 * File:   lcd.c
 * Author: gvanhoy
 *
 * Created on December 31, 2014, 1:39 PM
 */

#include "p24fj64ga002.h"
#include "lcd.h"
#include "timer.h"

#define LCD_DATA   LATB
#define LCD_RS  LATBbits.LATB7
#define LCD_E   LATBbits.LATB6

#define TRIS_D7  TRISBbits.TRISB15
#define TRIS_D6  TRISBbits.TRISB14
#define TRIS_D5  TRISBbits.TRISB13
#define TRIS_D4  TRISBbits.TRISB12
#define TRIS_RS  TRISBbits.TRISB7
#define TRIS_E   TRISBbits.TRISB6

#define LCD_WRITE_DATA    1
#define LCD_WRITE_CONTROL 0

#define LOWER 1
#define UPPER 0

void writeFourBits(unsigned char word, unsigned int commandType, unsigned int delayAfter, unsigned int lower){
    if(lower){
        LATBbits.LATB15 = word<3>;
        LATBbits.LATB14 = word<2>;
        LATBbits.LATB13 = word<1>;
        LATBbits.LATB12 = word<0>;
    }
    else{
        LATBbits.LATB15 = word<7>;
        LATBbits.LATB14 = word<6>;
        LATBbits.LATB13 = word<5>;
        LATBbits.LATB12 = word<4>;
    }
    LCD_RS = commandType; delayUs(1);
    LCD_E = 1;  delayUs(1); //minimum 230 ns
    LCD_E = 0;  delayUs(1);
    delayUs(delayAfter);
}


void writeLCD(unsigned char word, unsigned int commandType, unsigned int delayAfter){
    writeFourBits(word, commandType, delayAfter, UPPER);
    writeFourBits(word, commandType, delayAfter, LOWER);
}

void printCharLCD(char c) {
        writeLCD(c, LCD_WRITE_DATA, 46);
}