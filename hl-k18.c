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

    result |= shift_cursor_left_or_right ? (1 << 1) : 0;
    result |= shift_cursor ? (1 << 0) : 0;

    return result;
}

uint8_t generate_lcd1602_display_control_cmd(bool *RS,
        bool *RW, bool display_visible, bool cursor_visible, bool cursor_blink)
{
    uint8_t result = 0b1000;

    *RS = false;
    *RW = false;

    result |= display_visible ? (1 << 2) : 0;
    result |= cursor_visible ? (1 << 1) : 0;
    result |= cursor_blink ? (1 << 0) : 0;

    return result;
}

uint8_t generate_lcd1602_display_shift(bool *RS,
        bool *RW, bool shift_cursor_or_display, bool shift_left_or_right)
{
    uint8_t result = 0b10000;

    *RS = false;
    *RW = false;

    result |= shift_cursor_or_display ? (1 << 3) : 0;
    result |= shift_left_or_right ? (1 << 2) : 0;

    return result;
}

uint8_t generate_lcd1602_function_set_cmd(bool *RS,
        bool *RW, bool interface_4_or_8_bits,
        bool lines_1_or_2, bool matrix_5x8_or_5x11)
{
    uint8_t result = 0b100000;

    *RS = false;
    *RW = false;

    result |= interface_4_or_8_bits ? (1 << 4) : 0;
    result |= lines_1_or_2 ? (1 << 3) : 0;
    result |= matrix_5x8_or_5x11 ? (1 << 2) : 0;

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
    /*
     * Set D7 as input
     */

    TRIS_LCD1602_BF = 1;

    WRITE_LCD1602_RS = false;
    WRITE_LCD1602_RW = true;

    /*
     * Enable Port is enabled before checking if Busy Flag is on
     */

    WRITE_LCD1602_EN = true;

    /*
     * Wait for the Busy Flag
     */

    while (READ_LCD1602_BF);

    /*
     * Set D7 as output
     */

    TRIS_LCD1602_BF = 0;

    /*
     * Don't forget it set it back to false
     */

    WRITE_LCD1602_EN = false;
}

void pulse_lcd1602(bool RS, bool RW, uint8_t data)
{
    /*
     * Init TRIS (as outputs)
     */

    TRIS_LCD1602_RS = 0;
    TRIS_LCD1602_RW = 0;
    TRIS_LCD1602_EN = 0;
    TRIS_LCD1602_BF = 0;
    TRIS_LCD1602_DATA = 0x00;

    /*
     * Set Register Select & Read or Write bit ports
     */

    WRITE_LCD1602_RS = RS;
    WRITE_LCD1602_RW = RW;
    WRITE_DATA_LCD1602 = data;

    /*
     * Let's pulsate now.
     */

    WRITE_LCD1602_EN = true;

    __delay_ms(PULSE_DURATION_MS_FOR_LCD1602);

    WRITE_LCD1602_EN = false;

    __delay_ms(PULSE_DURATION_MS_FOR_LCD1602);

    /*
     * Ok we've done the request to the LCD at this point,
     * let's wait for the busy flag now.
     */

    wait_for_ready_lcd1602();
}

void init_lcd1602(void)
{
    bool RS, RW;
    uint8_t data;

    /*
     * Wait a bit for its initialization.
     */

    __delay_ms(100);

    data = generate_lcd1602_function_set_cmd(&RS, &RW, true, true, false);

    pulse_lcd1602(RS, RW, data);

    data = generate_lcd1602_display_control_cmd(&RS,
            &RW, true, false, false);

    pulse_lcd1602(RS, RW, data);

    data = generate_lcd1602_clear_display_cmd(&RS, &RW);

    pulse_lcd1602(RS, RW, data);
}

void write_to_lcd1602(const char* msg)
{
    bool RS, RW;
    uint8_t data;
    int i;
    int strlength = strlen(msg);

    /*
     * Clear display
     */

    data = generate_lcd1602_clear_display_cmd(&RS, &RW);

    pulse_lcd1602(RS, RW, data);

    /*
     * Be sure that we've set the address to Display Data RAM
     */

    data = generate_lcd1602_set_ddram_address(&RS, &RW, 0);

    pulse_lcd1602(RS, RW, data);

    if (strlength > MAX_CHARACTERS_LCD1602)
    {
        strlength = MAX_CHARACTERS_LCD1602;
    }

    /*
     * Write first line on DDRAM
     */

    for (i = 0; i < strlength; i++)
    {
        /*
         * Set cursor on next line
         * Basically, addresses on first line goes to 0x00 to 0x10
         * Second lines goes to 0x40 to 0x4F
         */

        if (i == MAX_CHARACTERS_LCD1602 / 2)
        {
            data = generate_lcd1602_set_ddram_address(&RS, &RW,
                    ADDRESS_TO_NEXT_LINE_LCD1602);
            pulse_lcd1602(RS, RW, data);
        }

        data = generate_lcd1602_write_cgram_or_ddram(&RS, &RW, msg[i]);

        pulse_lcd1602(RS, RW, data);
    }
}

void show_lcd1602(const char* fmt, ...)
{
    /**
     * 2 lines 6 characters
     */

    char buffer[MAX_CHARACTERS_LCD1602];
    va_list args;
    va_start(args, fmt);

    vsnprintf(buffer, MAX_CHARACTERS_LCD1602, fmt, args);

    write_to_lcd1602(buffer);

    va_end(args);
}