#include "p24FJ64GA002.h"
#include "spi.h"
#include "accelerometer.h"

#define DATA_FORMAT_REG 0x31
#define SELF_TEST 0x80
#define SPI 0x40
#define RES_2g 0x00
#define RES_4g 0x01
#define RES_8g 0x02
#define RES_16g 0x03

#define DATA_READ 0x80
#define DATA_WRITE 0x00

#define DATAX0 0x32
#define DATAX1 0x33
#define DATAY0 0x34
#define DATAY1 0x35
#define DATAZ0 0x36
#define DATAZ1 0x37

void initACC(){
    spiWrite(((DATA_WRITE | DATA_FORMAT_REG) << 8) | SELF_TEST | RES_2g);
}

int getDeviceID(){
    int devid = spiWrite(DATA_READ | 0x00);
    return devid;
}

int getX(){
    int x = 0;
    x = spiWrite((DATA_READ | DATAX1) << 8);
    x = x << 8;
    x |= spiWrite((DATA_READ | DATAX0) << 8);
    return x;
}

int getY(){
    int y = 0;
    y = spiWrite((DATA_READ | DATAY1) << 8);
    y = y << 8;
    y |= spiWrite((DATA_READ | DATAY0) << 8);
    return y;
}

int getZ(){
    int z = 0;
    z = spiWrite((DATA_READ | DATAZ1) << 8);
    z = z << 8;
    z |= spiWrite((DATA_READ | DATAZ0) << 8);
    return z;
}