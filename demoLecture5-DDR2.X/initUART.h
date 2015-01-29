/* 
 * File:   initUART.h
 * Author: user
 *
 * Created on January 29, 2015, 9:16 AM
 */

#ifndef INITUART_H
#define	INITUART_H


#define XTFREQ          7372800         	  // On-board Crystal frequency
#define PLLMODE         4               	  // On-chip PLL setting (Fosc)
#define FCY             (XTFREQ*PLLMODE)/2    // Instruction Cycle Frequency (Fosc/2)

#define BAUDRATE         115200
#define BRGVAL          ((FCY/BAUDRATE)/16)-1

void initUART();

#endif	/* INITUART_H */

