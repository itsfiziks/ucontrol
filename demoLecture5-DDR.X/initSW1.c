#include "p24fj64ga002.h"
#include "initSW1.h"

/*Initialize SW1 to be a change notification interrupt
 */
void initSW1(){
    TRISBbits.TRISB5 = 1;
    CNEN2bits.CN27IE = 1;
    IFS1bits.CNIF = 0;
    IEC1bits.CNIE = 1;
}
