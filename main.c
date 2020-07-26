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

void main(void)
{
    init_lcd1602();

    int number = 0;

    while (true)
    {
    }
}

