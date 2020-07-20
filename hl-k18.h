/* 
 * File:   hl-k18.h
 * Author: kamay
 *
 * Created on July 20, 2020, 12:56 PM
 */

#ifndef HL_K18_H
#define	HL_K18_H

#define LCD_PROGRAMMING_ERROR_STRING "Programming error..."
#define SHOW_LCD_PROGRAMMING_ERROR() show_lcd(LCD_PROGRAMMING_ERROR_STRING)
#define REFRESH_DELAY 30

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

void init_tris_output_leds(void);

void show_8x8_led_column(int col);
void hide_8x8_led_column(int col);
void show_8x8_led_line(int line);
void hide_8x8_led_line(int line);
void clear_8x8_leds(void);
void show_lcd(char* msg, ...);

void clear_numbers_on_leds(void);
void show_number_on_cell_on_leds(int cell_number, char digit);
void show_number_on_leds_int64(int64_t number);
void show_number_on_leds_double(double number);

#endif	/* HL_K18_H */

