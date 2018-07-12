/**
 * (C) Copyright Collin J. Doering 2015
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file lcdLibConfig.h
 * @author Collin J. Doering <collin.doering@rekahsoft.ca>
 * @date Oct 4, 2015
 * @brief Configuration file for lcdLib.h
 */

// Includes -------------------------------------------------------------------------------

#include <avr/io.h>

//------------------------------------------------------------------------------------------

/**
  Usage
  =====

  Operates in 3 mutually exclusive modes:
  1. Default Mode
     8-bit mode that requires all its data bus lines be on the same PORT.
  2. EIGHT_BIT_ARBITRARY_PIN_MODE
     8-bit mode that allows the data bus lines to use any IO pin.
  3. FOUR_BIT_MODE
     4-bit mode that allows the data bus lines to use any IO pin.
*/

/*
  Screen characteristics
*/

#define LCD_CHARACTERS_PER_LINE 20      ///< Number of characters per line of the LCD
#define LCD_NUMBER_OF_LINES     4       ///< Number of lines of the LCD
#define LCD_LINE_BEGINNINGS     0x00, \
                                0x40, \
                                0x14, \
                                0x54    ///< Memory locations for each physical line ordered 1 to LCD_NUMBER_OF_LINES

/* Which font to use (can only leave one uncommented) */
#define LCD_FONT_5x8
//#define LCD_FONT_5x10

/* Support ANSI escapes; comment to disable */
#define LCD_ANSI_ESCAPE_ENABLE

/* Modes */

// Default mode: 8-bit data bus

// 8-bit mode with data bus on arbitrary pins
//#define EIGHT_BIT_ARBITRARY_PIN_MODE

// LCD in 4-bit mode (on arbitrary pins)
#define FOUR_BIT_MODE

/* All mode options */

#define LCD_RS          PD2
#define LCD_RS_PORT     PORTD
#define LCD_RS_DDR      DDRD

#define LCD_RW          PD3
#define LCD_RW_PORT     PORTD
#define LCD_RW_DDR      DDRD

#define LCD_ENABLE      PD4
#define LCD_ENABLE_PORT PORTD
#define LCD_ENABLE_DDR  DDRD

/*
  Mode specific settings
*/

/* Default Mode */

// LCD data bus PORT, PIN and DDR.
#define LCD_DBUS_PORT   PORTB

#define LCD_DBUS_DDR    DDRB
#define LCD_DBUS_PIN    PINB

// This must be set in default mode to the MSB of the data lines
#define LCD_BF          PB7

/* EIGHT_BIT_ARBITRARY_PIN_MODE specific settings */

#define LCD_DBUS0      PB0
#define LCD_DBUS0_PORT PORTB
#define LCD_DBUS0_DDR  DDRB
#define LCD_DBUS0_PIN  PINB

#define LCD_DBUS1      PB1
#define LCD_DBUS1_PORT PORTB
#define LCD_DBUS1_DDR  DDRB
#define LCD_DBUS1_PIN  PINB

#define LCD_DBUS2      PB2
#define LCD_DBUS2_PORT PORTB
#define LCD_DBUS2_DDR  DDRB
#define LCD_DBUS2_PIN  PINB

#define LCD_DBUS3      PB3
#define LCD_DBUS3_PORT PORTB
#define LCD_DBUS3_DDR  DDRB
#define LCD_DBUS3_PIN  PINB

/* FOUR_BIT_MODE and EIGHT_BIT_ARBITRARY_PIN_MODE shared settings */

#define LCD_DBUS4      PB4
#define LCD_DBUS4_PORT PORTB
#define LCD_DBUS4_DDR  DDRB
#define LCD_DBUS4_PIN  PINB

#define LCD_DBUS5      PB5
#define LCD_DBUS5_PORT PORTB
#define LCD_DBUS5_DDR  DDRB
#define LCD_DBUS5_PIN  PINB

#define LCD_DBUS6      PB6
#define LCD_DBUS6_PORT PORTB
#define LCD_DBUS6_DDR  DDRB
#define LCD_DBUS6_PIN  PINB

#define LCD_DBUS7      PB7
#define LCD_DBUS7_PORT PORTB
#define LCD_DBUS7_DDR  DDRB
#define LCD_DBUS7_PIN  PINB


/* LCD delays (in microseconds when unspecified) */

#define LCD_ENABLE_HIGH_DELAY   25
#define LCD_ENABLE_LOW_DELAY    25
#define LCD_INIT_DELAY0         15000
#define LCD_INIT_DELAY1         8200
#define LCD_INIT_DELAY2         200

#define LCD_CLEAR_DISPLAY_DELAY 16000
#define LCD_RETURN_HOME_DELAY   16000
#define LCD_GENERIC_INSTR_DELAY 50
