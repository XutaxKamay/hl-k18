/* 
 * File:   hl-k18.h
 * Author: kamay
 *
 * Created on July 20, 2020, 12:56 PM
 */

#ifndef HL_K18_H
#define	HL_K18_H

#define REFRESH_DELAY 300

/**
 * Columns for HL-K18
 */
#define BIT_PORTA_OUT_COL8 (1 << 1)
#define BIT_PORTA_OUT_COL7 (1 << 2)
#define BIT_PORTA_OUT_COL6 (1 << 3)
#define BIT_PORTA_OUT_COL5 (1 << 5)
#define BIT_PORTE_OUT_COL4 (1 << 0)
#define BIT_PORTE_OUT_COL3 (1 << 1)
#define BIT_PORTE_OUT_COL2 (1 << 2)
#define BIT_PORTC_OUT_COL1 (1 << 0)

/**
 * Lines for HL-K18
 */

#define BIT_PORTD_OUT_LINE8 (1 << 0)
#define BIT_PORTD_OUT_LINE7 (1 << 1)
#define BIT_PORTD_OUT_LINE6 (1 << 2)
#define BIT_PORTD_OUT_LINE5 (1 << 3)
#define BIT_PORTD_OUT_LINE4 (1 << 4)
#define BIT_PORTD_OUT_LINE3 (1 << 5)
#define BIT_PORTD_OUT_LINE2 (1 << 6)
#define BIT_PORTD_OUT_LINE1 (1 << 7)

/**
 * Speaker for HL-K18
 */
#define BIT_PORTC_OUT_SPEAKER (1 << 1)

/**
 * Leds stuffs
 */
#define MAX_DIGITS 8
#define IGNORE_DIGIT 0x11
#define NEGATIVE_CHAR 0x10
#define DOT_CHAR 0x12
#define MINIMUM_INT_ON_LEDS -9999999
#define MAXIMUM_INT_ON_LEDS 99999999
#define MINIMUM_DOUBLE_ON_LEDS -99999.00
#define MAXIMUM_DOUBLE_ON_LEDS 999999.00

/**
 * LCD1602
 * 
 * Some definitions:
 * ******************************************
 * DDRAM stands for Display Data RAM
 * CGRAM stands for Character Generator RAM
 * D0-D7 are used to write data to the DDRAM.
 * ******************************************
 */

#define WRITE_LCD1602_RS LATAbits.LA2
#define WRITE_LCD1602_RW LATAbits.LA3
#define WRITE_LCD1602_EN LATAbits.LA5

#define READ_LCD1602_RS PORTAbits.RA2
#define READ_LCD1602_RW PORTAbits.RA3
#define READ_LCD1602_EN PORTAbits.RA5

#define TRIS_LCD1602_RS TRISAbits.RA2
#define TRIS_LCD1602_RW TRISAbits.RA3
#define TRIS_LCD1602_EN TRISAbits.RA5

/**
 * LCD1602
 * D0-D7
 */
#define WRITE_LCD1602_D0 LATDbits.LATD0
#define WRITE_LCD1602_D1 LATDbits.LATD1
#define WRITE_LCD1602_D2 LATDbits.LATD2
#define WRITE_LCD1602_D3 LATDbits.LATD3
#define WRITE_LCD1602_D4 LATDbits.LATD4
#define WRITE_LCD1602_D5 LATDbits.LATD5
#define WRITE_LCD1602_D6 LATDbits.LATD6
#define WRITE_LCD1602_D7 LATDbits.LATD7
#define WRITE_LCD1602_BF BIT_PORTD_LCD1602_D7

#define READ_LCD1602_D0 PORTDbits.RD0
#define READ_LCD1602_D1 PORTDbits.RD1
#define READ_LCD1602_D2 PORTDbits.RD2
#define READ_LCD1602_D3 PORTDbits.RD3
#define READ_LCD1602_D4 PORTDbits.RD4
#define READ_LCD1602_D5 PORTDbits.RD5
#define READ_LCD1602_D6 PORTDbits.RD6
#define READ_LCD1602_D7 PORTDbits.RD7
#define READ_LCD1602_BF READ_LCD1602_D7

/*
 * BF is also D7 used for data, so it's both an input and output
 */
#define TRIS_LCD1602_BF TRISDbits.RD7

#define TRIS_LCD1602_DATA TRISD
#define WRITE_DATA_LCD1602 LATD
#define READ_DATA_LCD1602 PORTD

/*
 * Usually it shouldn't take more than 2 milliseconds.
 */
#define PULSE_DURATION_MS_FOR_EN 2

/**
 * LCD1602 Instructions
 */

/**
 * 
 * @param RS
 * @param RW
 * @return 
 */
uint8_t generate_lcd1602_clear_display_cmd(bool *RS, bool *RW);

/**
 * 
 * @param RS
 * @param RW
 * @return 
 */
uint8_t generate_lcd1602_return_home_cmd(bool *RS, bool *RW);

/**
 * 
 * @param RS
 * @param RW
 * @param shift_cursor_left_or_right
 * @param shift_cursor
 * @return 
 */
uint8_t generate_lcd1602_entry_set_mode(bool *RS,
        bool *RW,
        bool shift_cursor_left_or_right,
        bool shift_cursor);

/**
 * 
 * @param RS
 * @param RW
 * @param display_visible
 * @param cursor_visible
 * @param cursor_blink
 * @return 
 */
uint8_t generate_lcd1602_display_control_cmd(bool *RS,
        bool *RW, bool display_visible, bool cursor_visible, bool cursor_blink);

/**
 * 
 * @param RS
 * @param RW
 * @param shift_cursor_or_display
 * @param shift_left_or_right
 * @return 
 */
uint8_t generate_lcd1602_display_shift(bool *RS,
        bool *RW, bool shift_cursor_or_display, bool shift_left_or_right);

/**
 * 
 * @param RS
 * @param RW
 * @param interface_4_or_8_bits
 * @param lines_1_or_2
 * @param matrix_5x8_or_5x11
 * @return 
 */
uint8_t generate_lcd1602_function_set_cmd(bool *RS,
        bool *RW, bool interface_4_or_8_bits,
        bool lines_1_or_2, bool matrix_5x8_or_5x11);

/**
 *
 * @param RS
 * @param RW
 * @param ACG
 * @return 
 */
uint8_t generate_lcd1602_set_cgram_address(bool *RS,
        bool *RW, uint8_t ACG);

/**
 * 
 * @param RS
 * @param RW
 * @param ADD
 * @return 
 */
uint8_t generate_lcd1602_set_ddram_address(bool *RS,
        bool *RW, uint8_t ADD);

/**
 * 
 * @param RS
 * @param RW
 * @param D
 * @return 
 */
uint8_t generate_lcd1602_write_cgram_or_ddram(bool *RS,
        bool *RW, uint8_t D);

/**
 * 
 * @param RS
 * @param RW
 * @param D
 * @return 
 */
uint8_t generate_lcd1602_read_cgram_or_ddram(bool *RS,
        bool *RW, uint8_t D);

void init_lcd1602(void);
void show_lcd1602(const char* msg, ...);

void init_output_tris_leds(void);

void show_8x8_led_column(int col);
void hide_8x8_led_column(int col);
void show_8x8_led_line(int line);
void hide_8x8_led_line(int line);
void clear_8x8_leds(void);

void clear_numbers_on_leds(void);
void show_number_on_cell_on_leds(int cell_number, int digit);
void show_number_on_leds_int64(int64_t number);
void show_number_on_leds_double(double number);

#endif	/* HL_K18_H */

