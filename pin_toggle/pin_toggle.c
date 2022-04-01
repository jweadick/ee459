/*************************************************************
*       at328-0.c - Demonstrate simple I/O functions of ATmega328
*
*       Program loops turning PC0 on and off as fast as possible.
*
* The program should generate code in the loop consisting of
*   LOOP:   SBI  PORTC,0        (2 cycles)
*           CBI  PORTC,0        (2 cycles)
*           RJMP LOOP           (2 cycles)
*
* PC0 will be low for 4 / XTAL freq
* PC0 will be high for 2 / XTAL freq
* A 9.8304MHz clock gives a loop period of about 600 nanoseconds.
*
* Revision History
* Date     Author      Description
* 09/14/12 A. Weber    Initial Release
* 11/18/13 A. Weber    Renamed for ATmega328P
*************************************************************/

#include <avr/io.h>
#include <avr/delay.h>
#include "pin_toggle.h"


int main(void)
{
    DDRC = 0x3f;        // Set PORTC 0-5 to output
    DDRB = 0xbf;        // Set PORTB 0-5 & 7 to output
    DDRD = 0xff;        // Set PORTD 0-7 to output

    while (1) {
	// PORTC
    checkB();
    //checkC();
    //checkD();
    }

    return 0;   /* never reached */
}
