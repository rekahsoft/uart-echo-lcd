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
 * @file lcdLib.h
 * @author Collin J. Doering <collin.doering@rekahsoft.ca>
 * @date Sep 29, 2015
 * @brief Functions to initialize, and operate a character LCD.
 */

#ifndef LCD_LIB_H
#define LCD_LIB_H

// Includes -----------------------------------------------------------------------------------
#include "lcd_instr.h"
#include "lcdLibConfig.h"

//---------------------------------------------------------------------------------------------
// Library function declarations

/**
  Initialize the LCD display via software initialization as specified by the datasheet.
*/
void initLCD(void);

/**
  Writes a character to the LCD display at the current cursor position after the LCD display is
  ready for new data. Allows the following ASCII escapes: '\n', '\r', '\f' and '\b'; ignores
  ASCII escape '\a'.
 */
void writeCharToLCD(char);

/**
  Writes a string to the LCD starting from the current cursor position.
 */
void writeStringToLCD(char*);

//---------------------------------------------------------------------------------------------
// LCD command functions (all have associated ANSI escape)

/**
  Clears the display and positions the cursor in the top left of the LCD screen.
 */
void clearDisplay(void);

/**
  Brings the cursor the the top left of the LCD screen.
 */
void returnHome(void);

/**
   Gets the current row and column of the LCD cursor and sets given pointers row and column to
   their respective values. Note indexes start at 1.
*/
void getCursorPosition(uint8_t* row, uint8_t* column);

/**
   Using the given parameters row and column, sets the current row and column occupied by the LCD
   cursor. Note indexes start at 1.
 */
void setCursorPosition(uint8_t row, uint8_t column);

/**
   Moves the cursor n positions up. If the cursor is at the edge of the screen this has no effect.
 */
void moveCursorUp(uint8_t n);

/**
   Moves the cursor n positions down. If the cursor is at the edge of the screen this has no effect.
 */
void moveCursorDown(uint8_t n);

/**
   Moves the cursor n positions forward. If the cursor is at the edge of the screen this has no effect.
 */
void moveCursorForward(uint8_t n);

/**
   Moves the cursor n positions backwards. If the cursor is at the edge of the screen this has no effect.
 */
void moveCursorBackward(uint8_t n);

/**
   Moves the cursor to the beginning of the line n lines down.
 */
void moveCursorNextLine(uint8_t n);

/**
   Moves the cursor to the beginning of the line n lines up.
 */
void moveCursorPreviousLine(uint8_t n);

/**
   Moves the cursor to column n. If n is off screen go to the last line.
 */
void moveCursorToColumn(uint8_t n);

/**
   Scroll whole page up by n lines. New lines are added at the bottom.
 */
void scrollUp(uint8_t n);

/**
   Scroll whole page down by n lines. New lines are added at the top.
 */
void scrollDown(uint8_t n);

/**
   Saves the cursors current position.
 */
void saveCursorPosition(void);

/**
   Restores the last saved cursor position.
 */
void restoreCursorPosition(void);

/**
   Clears part or all of screen dependent on the value of n:
   0 or missing: clear from cursor to end of screen
   1: clear from cursor to end of screen
   2: clear entire screen
 */
void eraseDisplay(uint8_t n);

/**
   Erases part of a line dependent on the value of n:
   0 or missing: clear from cursor to end of the line
   1: clear from cursor to beginning of the line
   2: clear entire line
 */
void eraseInline(uint8_t n);

/**
   Hides the cursor
 */
void hideCursor(void);

/**
   Shows the cursor
 */
void showCursor(void);

//---------------------------------------------------------------------------------------------
// Utility functions (with no associated ASCII or ANSI escape)

/**
   Turns the cursor blink off.
 */
void blinkCursorOff(void);

/**
   Turns the cursor blink on.
 */
void blinkCursorOn(void);

/**
   Turns the display off.
 */
void displayOff(void);

/**
   Turns the display on.
 */
void displayOn(void);

//---------------------------------------------------------------------------------------------

/**
   Read a single character from the row and column given (1 based) returning the cursor to
   its previous original position.
 */
char readCharFromLCD(uint8_t row, uint8_t column);

/**
   Read a line i (ones based) into str.
*/
void readLCDLine(uint8_t i, char* str);

//---------------------------------------------------------------------------------------------
// Advanced functions for special cases

/**
   Read len characters from (from_row, from_column) to (to_row, to_column) returning the cursor
   to its original position after the read. Upon success (not overflowing the screen), 0 is
   returned; otherwise non zero will be returned. The str pointer will be updated with the
   characters read from the screen. Even in the case of failure, str may be partially populated.
 */
void readCharsFromLCD(uint8_t from_row, uint8_t from_column, uint8_t to_row, uint8_t to_column, char* str, uint8_t len);

/**
  Initialize the LCD display via its internal reset circuit.

  Note: this is not the recommended way to initialize the LCD as it is unreliable and depends
        on the power supply. Preferably the software initialization method should be used (via
        the initLCD function).
 */
void initLCDByInternalReset(void);


//---------------------------------------------------------------------------------------------
// Mode and settings sanity check (preprocessor tests of lcdLibConfig.h)
//---------------------------------------------------------------------------------------------

#if !defined(LCD_CHARACTERS_PER_LINE)
#error "All modes require LCD_CHARACTERS_PER_LINE to be defined."
#elif !defined(LCD_NUMBER_OF_LINES)
#error "All modes require LCD_NUMBER_OF_LINES to be defined."
#elif !defined(LCD_LINE_BEGINNINGS)
#error "All modes require LCD_LINE_BEGINNINGS to be defined."
#else

#if LCD_NUMBER_OF_LINES == 1
#define LCD_LINES 0
#else
#define LCD_LINES (1 << INSTR_FUNC_SET_N)
#endif

#define LCD_CHARACTERS_PER_SCREEN (LCD_CHARACTERS_PER_LINE * LCD_NUMBER_OF_LINES)
#endif

#if !defined(LCD_FONT_5x8) &&\
    !defined(LCD_FONT_5x10)
#error "All modes require LCD_FONT_5x8 or LCD_FONT_5x10 to be defined."
#elif defined(LCD_FONT_5x8) && \
      defined(LCD_FONT_5x10)
#error "LCD_FONT_5x8 and LCD_FONT_5x10 are mutually exclusive. Choose one."
#elif defined(LCD_FONT_5x8)
#define LCD_FONT 0
#elif defined(LCD_FONT_5x10)
#define LCD_FONT (1 << INSTR_FUNC_SET_F)
#endif

#if !defined (LCD_RS)          || \
    !defined (LCD_RS_PORT)     || \
    !defined (LCD_RS_DDR)      || \
    !defined (LCD_RW)          || \
    !defined (LCD_RW_PORT)     || \
    !defined (LCD_RW_DDR)      || \
    !defined (LCD_ENABLE)      || \
    !defined (LCD_ENABLE_PORT) || \
    !defined (LCD_ENABLE_DDR)
#error "All modes require LCD_RS[,_PORT,_DDR], LCD_RW[,_PORT,_DDR], and LCD_ENABLE[,_PORT,_DDR] be defined."
#endif

#if defined (EIGHT_BIT_ARBITRARY_PIN_MODE) && \
    defined (FOUR_BIT_MODE)
#error "EIGHT_BIT_ARBITRARY_PIN_MODE and FOUR_BIT_MODE are mutually exclusive. Choose one."
#elif defined (EIGHT_BIT_ARBITRARY_PIN_MODE) || \
      defined (FOUR_BIT_MODE)

// EIGHT_BIT_ARBITRARY_PIN_MODE specific requirements
#ifdef EIGHT_BIT_ARBITRARY_PIN_MODE
#if !defined (LCD_DBUS0)      || \
    !defined (LCD_DBUS0_PORT) || \
    !defined (LCD_DBUS0_DDR)  || \
    !defined (LCD_DBUS0_PIN)  || \
    !defined (LCD_DBUS1)      || \
    !defined (LCD_DBUS1_PORT) || \
    !defined (LCD_DBUS1_DDR)  || \
    !defined (LCD_DBUS1_PIN)  || \
    !defined (LCD_DBUS2)      || \
    !defined (LCD_DBUS2_PORT) || \
    !defined (LCD_DBUS2_DDR)  || \
    !defined (LCD_DBUS2_PIN)  || \
    !defined (LCD_DBUS3)      || \
    !defined (LCD_DBUS3_PORT) || \
    !defined (LCD_DBUS3_DDR)  || \
    !defined (LCD_DBUS3_PIN)
#error "EIGHT_BIT_ARBITRARY_PIN_MODE require that LCD_DBUS*[,_PORT,_DDR,_PIN] be defined."
#endif
#endif

// Requirements for EIGHT_BIT_ARBITRARY_PIN_MODE and FOUR_BIT_MODE
#if !defined (LCD_DBUS4)      || \
    !defined (LCD_DBUS4_PORT) || \
    !defined (LCD_DBUS4_DDR)  || \
    !defined (LCD_DBUS4_PIN)  || \
    !defined (LCD_DBUS5)      || \
    !defined (LCD_DBUS5_PORT) || \
    !defined (LCD_DBUS5_DDR)  || \
    !defined (LCD_DBUS5_PIN)  || \
    !defined (LCD_DBUS6)      || \
    !defined (LCD_DBUS6_PORT) || \
    !defined (LCD_DBUS6_DDR)  || \
    !defined (LCD_DBUS6_PIN)  || \
    !defined (LCD_DBUS7)      || \
    !defined (LCD_DBUS7_PORT) || \
    !defined (LCD_DBUS7_DDR)  || \
    !defined (LCD_DBUS7_PIN)
#error "Both EIGHT_BIT_ARBITRARY_PIN_MODE and FOUR_BIT_MODE require that LCD_DBUS*[,_PORT,_DDR,_PIN] be defined."
#endif

// Set LCD_BF automatically for both EIGHT_BIT_ARBITRARY_PIN_MODE and FOUR_BIT_MODE
#undef  LCD_BF
#define LCD_BF         LCD_DBUS7

#else
#if !defined (LCD_DBUS_PORT) || \
    !defined (LCD_DBUS_DDR)  || \
    !defined (LCD_DBUS_PIN)  || \
    !defined (LCD_BF)
#error "Default mode requires that LCD_DBUS_[PORT,DDR,PIN] and LCD_BF be defined."
#endif

#undef  LCD_DBUS7_PORT
#define LCD_DBUS7_PORT LCD_DBUS_PORT
#undef  LCD_DBUS7_DDR
#define LCD_DBUS7_DDR  LCD_DBUS_DDR
#undef  LCD_DBUS7_PIN
#define LCD_DBUS7_PIN  LCD_DBUS_PIN
#endif

#endif /* LCD_LIB_H */
