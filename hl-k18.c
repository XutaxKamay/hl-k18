#include "main.h"

void init_tris_output_leds(void)
{
    TRISA &= ~(BIT_PORTA_OUT_COL5 | BIT_PORTA_OUT_COL6
            | BIT_PORTA_OUT_COL7 | BIT_PORTA_OUT_COL8);

    TRISC &= ~(BIT_PORTC_OUT_COL1 | BIT_PORTC_OUT_SPEAKER);

    TRISD &= ~(BIT_PORTD_OUT_LINE1 | BIT_PORTD_OUT_LINE2
            | BIT_PORTD_OUT_LINE3 | BIT_PORTD_OUT_LINE4
            | BIT_PORTD_OUT_LINE5 | BIT_PORTD_OUT_LINE6
            | BIT_PORTD_OUT_LINE7 | BIT_PORTD_OUT_LINE8);

    TRISE &= ~(BIT_PORTE_OUT_COL2 | BIT_PORTE_OUT_COL3 | BIT_PORTE_OUT_COL4);
}

void show_8x8_led_column(int col)
{
    switch (col)
    {
        case 1:
        {
            LATC |= BIT_PORTC_OUT_COL1;
            break;
        }
        case 2:
        {
            LATE |= BIT_PORTE_OUT_COL2;
            break;
        }
        case 3:
        {
            LATE |= BIT_PORTE_OUT_COL3;
            break;
        }
        case 4:
        {
            LATE |= BIT_PORTE_OUT_COL4;
            break;
        }
        case 5:
        {
            LATA |= BIT_PORTA_OUT_COL5;
            break;
        }
        case 6:
        {
            LATA |= BIT_PORTA_OUT_COL6;
            break;
        }
        case 7:
        {
            LATA |= BIT_PORTA_OUT_COL7;
            break;
        }
        case 8:
        {
            LATA |= BIT_PORTA_OUT_COL8;
            break;
        }
        default:
        {
            SHOW_LCD_PROGRAMMING_ERROR();
            break;
        }
    }
}

void hide_8x8_led_column(int col)
{
    switch (col)
    {
        case 1:
        {
            LATC &= ~BIT_PORTC_OUT_COL1;
            break;
        }
        case 2:
        {
            LATE &= ~BIT_PORTE_OUT_COL2;
            break;
        }
        case 3:
        {
            LATE &= ~BIT_PORTE_OUT_COL3;
            break;
        }
        case 4:
        {
            LATE &= ~BIT_PORTE_OUT_COL4;
            break;
        }
        case 5:
        {
            LATA &= ~BIT_PORTA_OUT_COL5;
            break;
        }
        case 6:
        {
            LATA &= ~BIT_PORTA_OUT_COL6;
            break;
        }
        case 7:
        {
            LATA &= ~BIT_PORTA_OUT_COL7;
            break;
        }
        case 8:
        {
            LATA &= ~BIT_PORTA_OUT_COL8;
            break;
        }
        default:
        {
            SHOW_LCD_PROGRAMMING_ERROR();
            break;
        }
    }
}

void show_8x8_led_line(int line)
{
    switch (line)
    {
        case 1:
        {
            LATD |= BIT_PORTD_OUT_LINE1;
            break;
        }
        case 2:
        {
            LATD |= BIT_PORTD_OUT_LINE2;
            break;
        }
        case 3:
        {
            LATD |= BIT_PORTD_OUT_LINE3;
            break;
        }
        case 4:
        {
            LATD |= BIT_PORTD_OUT_LINE4;
            break;
        }
        case 5:
        {
            LATD |= BIT_PORTD_OUT_LINE5;
            break;
        }
        case 6:
        {
            LATD |= BIT_PORTD_OUT_LINE6;
            break;
        }
        case 7:
        {
            LATD |= BIT_PORTD_OUT_LINE7;
            break;
        }
        case 8:
        {
            LATD |= BIT_PORTD_OUT_LINE8;
            break;
        }
        default:
        {
            SHOW_LCD_PROGRAMMING_ERROR();
            break;
        }
    }
}

void hide_8x8_led_line(int line)
{
    switch (line)
    {
        case 1:
        {
            LATD &= ~BIT_PORTD_OUT_LINE1;
            break;
        }
        case 2:
        {
            LATD &= ~BIT_PORTD_OUT_LINE2;
            break;
        }
        case 3:
        {
            LATD &= ~BIT_PORTD_OUT_LINE3;
            break;
        }
        case 4:
        {
            LATD &= ~BIT_PORTD_OUT_LINE4;
            break;
        }
        case 5:
        {
            LATD &= ~BIT_PORTD_OUT_LINE5;
            break;
        }
        case 6:
        {
            LATD &= ~BIT_PORTD_OUT_LINE6;
            break;
        }
        case 7:
        {
            LATD &= ~BIT_PORTD_OUT_LINE7;
            break;
        }
        case 8:
        {
            LATD &= ~BIT_PORTD_OUT_LINE8;
            break;
        }
        default:
        {
            SHOW_LCD_PROGRAMMING_ERROR();
            break;
        }
    }
}

void clear_8x8_leds(void)
{
    for (int i = 1; i <= 8; i++)
    {
        hide_8x8_led_column(i);
        hide_8x8_led_line(i);
    }
}

void clear_numbers_on_leds(void)
{
    clear_8x8_leds();
}

void show_number_on_cell_on_leds(int cell_number, int digit)
{
    if (digit < 0)
    {
        show_lcd("Exceeds (cell:%i-digit:%X) on leds", cell_number, digit);
        return;
    }
    else if (digit > 9)
    {
        show_lcd("Exceeds (cell:%i-digit:%X) on leds", cell_number, digit);
        return;
    }

    show_8x8_led_column(cell_number);

    switch (digit)
    {
        case 0:
        {
            show_8x8_led_line(8);
            show_8x8_led_line(7);
            show_8x8_led_line(6);
            show_8x8_led_line(5);
            show_8x8_led_line(4);
            show_8x8_led_line(3);
            break;
        }
        case 1:
        {
            show_8x8_led_line(7);
            show_8x8_led_line(6);
            break;
        }
        case 2:
        {
            show_8x8_led_line(8);
            show_8x8_led_line(7);
            show_8x8_led_line(2);
            show_8x8_led_line(4);
            show_8x8_led_line(5);
            break;
        }
        case 3:
        {
            show_8x8_led_line(8);
            show_8x8_led_line(7);
            show_8x8_led_line(2);
            show_8x8_led_line(6);
            show_8x8_led_line(5);
            break;
        }
        case 4:
        {
            show_8x8_led_line(3);
            show_8x8_led_line(2);
            show_8x8_led_line(6);
            show_8x8_led_line(7);
            break;
        }
        case 5:
        {
            show_8x8_led_line(8);
            show_8x8_led_line(3);
            show_8x8_led_line(2);
            show_8x8_led_line(6);
            show_8x8_led_line(5);
            break;
        }
        case 6:
        {
            show_8x8_led_line(3);
            show_8x8_led_line(2);
            show_8x8_led_line(4);
            show_8x8_led_line(5);
            show_8x8_led_line(6);
            show_8x8_led_line(8);
            break;
        }
        case 7:
        {
            show_8x8_led_line(8);
            show_8x8_led_line(7);
            show_8x8_led_line(6);
            break;
        }
        case 8:
        {
            show_8x8_led_line(8);
            show_8x8_led_line(7);
            show_8x8_led_line(6);
            show_8x8_led_line(5);
            show_8x8_led_line(4);
            show_8x8_led_line(3);
            show_8x8_led_line(2);
            break;
        }
        case 9:
        {
            show_8x8_led_line(8);
            show_8x8_led_line(7);
            show_8x8_led_line(6);
            show_8x8_led_line(5);
            show_8x8_led_line(3);
            show_8x8_led_line(2);
            break;
        }
    }

}

void show_number_on_leds_int64(int64_t number)
{
    static int64_t last_number = MAXIMUM_INT_ON_LEDS + 1;
    int64_t remainder = 0;
    int64_t cell_number = MAX_DIGITS;
    int64_t stop_to_cell_number = 1;
    int64_t divisor = 1;

    static unsigned char digits[MAX_DIGITS] = {
        IGNORE_DIGIT,
        IGNORE_DIGIT,
        IGNORE_DIGIT,
        IGNORE_DIGIT,
        IGNORE_DIGIT,
        IGNORE_DIGIT,
        IGNORE_DIGIT,
        IGNORE_DIGIT
    };

    if (last_number == number)
    {
        goto draw_directly;
    }

    if (number < MINIMUM_INT_ON_LEDS)
    {
        show_lcd("Exceeds (num:%lld) on leds", number);
        return;
    }
    else if (number > MAXIMUM_INT_ON_LEDS)
    {
        show_lcd("Exceeds (num:%lld) on leds", number);
        return;
    }

    last_number = number;

    bool isPositive = number >= 0;

    if (!isPositive)
    {
        number = -number;
        stop_to_cell_number = 2;
    }

    *(int64_t*) (digits) = 0x1111111111111111;

    while (cell_number >= stop_to_cell_number && number != 0)
    {
        remainder = number % (divisor * 10);

        digits[cell_number - 1] = (unsigned char) (remainder / divisor);

        number -= remainder;

        cell_number--;

        divisor *= 10;
    }

    // -
    if (!isPositive)
    {
        digits[cell_number - 1] = NEGATIVE_CHAR;
    }

draw_directly:
    for (int digit_cell = MAX_DIGITS;
            digit_cell >= 1;
            digit_cell--)
    {
        if (digits[digit_cell - 1] == IGNORE_DIGIT)
        {
            break;
        }

        clear_numbers_on_leds();

        if (digits[digit_cell - 1] == NEGATIVE_CHAR)
        {
            show_8x8_led_column(1);
            show_8x8_led_line(2);
        }
        else
        {
            show_number_on_cell_on_leds(digit_cell, (int) digits[digit_cell - 1]);
        }

        delay(REFRESH_DELAY);
    }
}

void show_number_on_leds_double(double number)
{
    if (number < MINIMUM_DOUBLE_ON_LEDS)
    {
        show_lcd("Exceeds (num:%f) on leds", number);
        return;
    }
    else if (number > MAXIMUM_DOUBLE_ON_LEDS)
    {
        show_lcd("Exceeds (num:%f) on leds", number);
        return;
    }
}

void show_lcd(const char* msg, ...)
{
    va_list list;
    va_start(list, msg);

    printf(msg, list);

    va_end(list);
}