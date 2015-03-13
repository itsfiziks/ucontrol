/* 
 * File:   i2c.h
 * Author: user
 *
 * Created on March 10, 2015, 9:08 AM
 */

#ifndef I2C_H
#define	I2C_H

void initI2C();
void sendI2C(char data, char address);
char receiveI2C(char address);

#endif	/* I2C_H */

