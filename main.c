/*
 * File:   main.c
 * Author: kamay
 *
 * Created on July 19, 2020, 3:41 AM
 */

#include "main.h"

void delay(uintptr_t delay)
{
    while (delay != 0)
    {
        delay--;
    }
}

void init_tris(void)
{
    /**
     * Set first everything to outputs.
     */
    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0x00;
    TRISD = 0x00;
    TRISE = 0x00;
}

void init_output_ports(void)
{
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;
    LATD = 0x00;
    LATE = 0x00;
}

void main(void)
{
    init_tris();
    init_output_ports();
    
    init_lcd1602();
}

