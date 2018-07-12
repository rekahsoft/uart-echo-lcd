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
 * @file lcd_instr.h
 * @author Collin J. Doering <collin.doering@rekahsoft.ca>
 * @date Oct 26, 2015
 * @brief Constant macro definitions of HD44780 compatible character LCD instruction set
 */

/*
  LCD character display instructions
*/

// Simple instructions with no options
#define CMD_INIT             0x30
#define CMD_INIT_FOUR_BIT    0x20
#define CMD_CLEAR_DISPLAY    0x01
#define CMD_RETURN_HOME      0x02

// Entry Set instruction and associated options
#define INSTR_ENTRY_SET      0x04
#define INSTR_ENTRY_SET_ID   1
#define INSTR_ENTRY_SET_S    0

// Display control instruction and associated options
#define INSTR_DISPLAY        0x08
#define INSTR_DISPLAY_D      2
#define INSTR_DISPLAY_C      1
#define INSTR_DISPLAY_B      0

// Cursor or display shift instruction and associated options
#define INSTR_MOV_SHIFT      0x10
#define INSTR_MOV_SHIFT_SC   3
#define INSTR_MOV_SHIFT_RL   2

// Function set instruction and associated options
#define INSTR_FUNC_SET       0x20
#define INSTR_FUNC_SET_DL    4
#define INSTR_FUNC_SET_N     3
#define INSTR_FUNC_SET_F     2

// Set CG RAM address instruction
#define INSTR_CGRAM_ADDR     0x60

// Set DD RAM address instruction
#define INSTR_DDRAM_ADDR     0x80
