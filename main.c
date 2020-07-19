/*
 * File:   main.c
 * Author: kamay
 *
 * Created on July 19, 2020, 3:41 AM
 */

#include "main.h"

void delay(unsigned long delay)
{
    while (delay != 0)
    {
        delay--;
    }
}

void main(void)
{
    TRISA = 0b00000000;
    TRISB = 0b00000000;
    TRISC = 0b00000000;
    TRISD = 0b00000000;
    TRISE = 0b00000000;

    PORTA = 0b00000000;
    PORTB = 0b00000000;
    PORTC = 0b00000000;
    PORTD = 0b00000000;
    PORTE = 0b00000000;

    while (1)
    {
        // ? ? ? col4 ? col3 col2 col1 ?
        PORTA = 0b00101110;
        // l 8,7,6,5,4,3,2,1
        PORTD = 0b11111111;
        // ? ? ? ? ? ? speaker col8
        PORTC = 0b00000001;
        // ? ? ? ? ? col7 col6 col5
        PORTE = 0b00000111;
    }
}

