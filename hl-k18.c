#include "main.h"

void init_output_tris_leds(void)
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
        return;
    }
    else if (digit > 9)
    {
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
    bool is_positive;

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
        return;
    }
    else if (number > MAXIMUM_INT_ON_LEDS)
    {
        return;
    }

    last_number = number;

    is_positive = number >= 0;

    if (!is_positive)
    {
        number = -number;
        stop_to_cell_number = 2;
    }

    *(int64_t*) (digits) = 0x1111111111111111;

    while (cell_number >= stop_to_cell_number && number != 0)
    {
        remainder = number % (divisor * 10);

        cell_number--;

        digits[cell_number] = (unsigned char) (remainder / divisor);

        number -= remainder;

        divisor *= 10;
    }

    if (!is_positive)
    {
        digits[cell_number - 1] = NEGATIVE_CHAR;
    }

draw_directly:
    init_output_tris_leds();

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
            show_8x8_led_column(digit_cell);
            show_8x8_led_line(2);
        }
        else
        {
            show_number_on_cell_on_leds(digit_cell, (int) digits[digit_cell - 1]);
        }

        __delay_us(REFRESH_DELAY);
    }
}

void show_number_on_leds_double(double number)
{
    int64_t whole_number, decimals;
    static double last_number = MAXIMUM_DOUBLE_ON_LEDS + 1.0;
    int64_t remainder = 0;
    int64_t cell_number = MAX_DIGITS;
    int64_t stop_to_cell_number = 1;
    int64_t divisor = 1;
    bool is_positive;

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

    if (number < MINIMUM_DOUBLE_ON_LEDS)
    {
        return;
    }
    else if (number > MAXIMUM_DOUBLE_ON_LEDS)
    {
        return;
    }

    if (last_number == number)
    {
        goto draw_directly;
    }

    last_number = number;

    is_positive = number >= 0;

    if (!is_positive)
    {
        number = -number;
        stop_to_cell_number = 2;
    }

    whole_number = (int64_t) number;

    /**
     * We want a precision of 2
     */
    decimals = (int64_t) ((number - (double) whole_number) * 100.0);

    *(int64_t*) (digits) = 0x1111111111111111;

    if (decimals != 0)
    {
        /**
         * ?X ex: 98 % 10 -> 8
         */
        digits[cell_number - 1] = decimals % 10;
        /**
         * X? ex: 98 / 10 -> 9
         */
        digits[cell_number - 2] = decimals / 10;
    }
    else
    {
        *(int*) (&digits[cell_number - 2]) = 0;
    }

    cell_number -= 2;

    if (whole_number != 0)
    {
        while (cell_number >= stop_to_cell_number && whole_number != 0)
        {
            remainder = whole_number % (divisor * 10);

            cell_number--;

            digits[cell_number] = (unsigned char) (remainder / divisor);

            whole_number -= remainder;

            divisor *= 10;
        }
    }
    else
    {
        cell_number--;
        digits[cell_number] = 0;
    }

    if (!is_positive)
    {
        digits[cell_number - 1] = NEGATIVE_CHAR;
    }

draw_directly:
    init_output_tris_leds();

    for (int digit_cell = MAX_DIGITS;
            digit_cell >= 1;
            digit_cell--)
    {
        if (digits[digit_cell - 1] == IGNORE_DIGIT)
        {
            break;
        }

        clear_numbers_on_leds();

        /**
         * This is the dot for the double/float values.
         */
        if (digit_cell == 6)
        {
            show_8x8_led_column(6);
            show_8x8_led_line(1);
        }

        if (digits[digit_cell - 1] == NEGATIVE_CHAR)
        {
            show_8x8_led_column(digit_cell);
            show_8x8_led_line(2);
        }
        else
        {
            show_number_on_cell_on_leds(digit_cell, (int) digits[digit_cell - 1]);
        }

        __delay_us(REFRESH_DELAY);
    }
}

uint8_t generate_lcd1602_clear_display_cmd(bool *RS, bool *RW)
{
    *RS = false;
    *RW = false;

    return 0b1;
}

uint8_t generate_lcd1602_return_home_cmd(bool *RS, bool *RW)
{
    *RS = false;
    *RW = false;

    return 0b10;
}

uint8_t generate_lcd1602_entry_set_mode(bool *RS,
        bool *RW,
        bool shift_cursor_left_or_right,
        bool shift_cursor)
{
    uint8_t result = 0b100;

    *RS = false;
    *RW = false;

    result |= (1 << 1) & shift_cursor_left_or_right;
    result |= (1 << 0) & shift_cursor;

    return result;
}

uint8_t generate_lcd1602_display_control_cmd(bool *RS,
        bool *RW, bool display_visible, bool cursor_visible, bool cursor_blink)
{
    uint8_t result = 0b1000;

    *RS = false;
    *RW = false;

    result |= (1 << 2) & display_visible;
    result |= (1 << 1) & cursor_visible;
    result |= (1 << 0) & cursor_blink;

    return result;
}

uint8_t generate_lcd1602_display_shift(bool *RS,
        bool *RW, bool shift_cursor_or_display, bool shift_left_or_right)
{
    uint8_t result = 0b10000;

    *RS = false;
    *RW = false;

    result |= (1 << 3) & shift_cursor_or_display;
    result |= (1 << 2) & shift_left_or_right;

    return result;
}

uint8_t generate_lcd1602_function_set_cmd(bool *RS,
        bool *RW, bool interface_4_or_8_bits,
        bool lines_1_or_2, bool matrix_5x8_or_5x11)
{
    uint8_t result = 0b100000;

    *RS = false;
    *RW = false;

    result |= (1 << 4) & interface_4_or_8_bits;
    result |= (1 << 3) & lines_1_or_2;
    result |= (1 << 2) & matrix_5x8_or_5x11;

    return result;
}

uint8_t generate_lcd1602_set_cgram_address(bool *RS,
        bool *RW, uint8_t ACG)
{
    uint8_t result = 0b1000000;

    *RS = false;
    *RW = false;

    ACG &= ~(0b11000000);

    result |= ACG;

    return result;
}

uint8_t generate_lcd1602_set_ddram_address(bool *RS,
        bool *RW, uint8_t ADD)
{
    uint8_t result = 0b10000000;

    *RS = false;
    *RW = false;

    ADD &= ~(0b10000000);

    result |= ADD;

    return result;
}

uint8_t generate_lcd1602_write_cgram_or_ddram(bool *RS,
        bool *RW, uint8_t D)
{
    uint8_t result = 0;

    *RS = true;
    *RW = false;

    result = D;

    return result;
}

uint8_t generate_lcd1602_read_cgram_or_ddram(bool *RS,
        bool *RW, uint8_t D)
{
    uint8_t result = 0;

    *RS = true;
    *RW = true;

    result = D;

    return result;
}

void wait_for_ready_lcd1602(void)
{

}

void init_lcd1602(void)
{
}

void show_lcd1602(const char* msg, ...)
{
    /**
     * 2 lines 6 characters
     */
    char buffer[2 * 16];
    va_list list;
    va_start(list, msg);

    vsnprintf(buffer, sizeof (buffer), msg, list);

    va_end(list);
}