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
    /**
     * Set all to output for now
     */
    TRISA = 0b00000000;
    TRISB = 0b00000000;
    TRISC = 0b00000000;
    TRISD = 0b00000000;
    TRISE = 0b00000000;
}

