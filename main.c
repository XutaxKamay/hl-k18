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
     * Set first everything to inputs.
     */
    TRISA = 0xFF;
    TRISB = 0xFF;
    TRISC = 0xFF;
    TRISD = 0xFF;
    TRISE = 0xFF;
}

void init_ports(void)
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
    init_ports();

    /**
     * Then we set for output for specific bits.
     */

    init_tris_output_leds();

    int64_t number = 13379500;
    int64_t waiting_to_increment = 0;

    while (true)
    {
        if (waiting_to_increment % 100 == 0)
            number++;

        show_number_on_leds_int64(number);

        waiting_to_increment++;
    }
}

