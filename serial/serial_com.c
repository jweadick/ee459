/*************************************************************
*       at328-6.c - Demonstrate interface to a serial LCD display
*
*       This program will print a message on an LCD display
*       using a serial interface.  It is designed to work with a
*       Matrix Orbital LK204-25 using an RS-232 interface.
*
* Revision History
* Date     Author      Description
* 11/07/07 A. Weber    First Release
* 02/26/08 A. Weber    Code cleanups
* 03/03/08 A. Weber    More code cleanups
* 04/22/08 A. Weber    Added "one" variable to make warning go away
* 04/11/11 A. Weber    Adapted for ATmega168
* 11/18/13 A. Weber    Renamed for ATmega328P
*************************************************************/

#include <avr/io.h>
#include <util/delay.h>

// void lcd_init(void);
// void lcd_moveto(unsigned char, unsigned char);
// void lcd_stringout(char *);

// void sci_init(void);
// void sci_out(char);
// void sci_outs(char *);

void serial_init (unsigned short);
void serial_out (char);
char serial_in (void);



char str1[] = "12345678901234567890";
char str2[] = ">> USC EE459L <<";
char str3[] = ">> at328-6.c <<<";
char str4[] = "-- April 11, 2011 --";

#define FOSC 7373800		// Clock frequency
#define BAUD 9600             // Baud rate used by the LCD
#define MYUBRR FOSC/16/BAUD-1   // Value for UBRR0 register

int main(void) {

    // sci_init();                 // Initialize the SCI port
    
    //lcd_init();                 // Initialize the LCD

    // lcd_moveto(0, 0);
    // lcd_stringout(str1);        // Print string on line 1
    // lcd_moveto(1, 2);
    // lcd_stringout(str2);        // Print string on line 2
    // lcd_moveto(2, 2);
    // lcd_stringout(str3);        // Print string on line 3
    // lcd_moveto(3, 0);
    // lcd_stringout(str4);        // Print string on line 4
	
	serial_init(MYUBRR);		// Initialize the Serial Port

    while (1) {                 // Loop forever
    }

    return 0;   /* never reached */
}

/*
serial_init - Initialize the USART port
*/
void serial_init ( unsigned short ubrr ) {
	UBRR0 = ubrr ; // Set baud rate
	UCSR0B |= (1 << TXEN0 ); // Turn on transmitter
	UCSR0B |= (1 << RXEN0 ); // Turn on receiver
	UCSR0C = (3 << UCSZ00 ); // Set for async . operation , no parity ,
	// one stop bit , 8 data bits
}

/*
serial_out - Output a byte to the USART0 port
*/
void serial_out ( char ch )
{
	while (( UCSR0A & (1 << UDRE0 )) == 0);
	UDR0 = ch ;
}

/*
serial_in - Read a byte from the USART0 and return it
*/
char serial_in ()
{
	while ( !( UCSR0A & (1 << RXC0 )) );
	return UDR0 ;
}
