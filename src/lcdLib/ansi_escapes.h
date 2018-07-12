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
 * @file ansi_escapes.h
 * @author Collin J. Doering <collin.doering@rekahsoft.ca>
 * @date Oct 9, 2015
 * @brief Macros to ease writing ANSI escapes.
 */

#define CSI "\e["                   ///< Control Sequence Introducer

#define CUU(n) CSI #n "A"           ///< Cursor up
#define CUD(n) CSI #n "B"           ///< Cursor down
#define CUF(n) CSI #n "C"           ///< Cursor forward
#define CUB(n) CSI #n "D"           ///< Cursor backward

#define CNL(n) CSI #n "E"           ///< Cursor next line
#define CPL(n) CSI #n "F"           ///< Cursor previous line

#define CHA(n) CSI #n "G"           ///< Cursor horizontal absolute
#define CUP(n,m) CSI #n ";" #m "H"  ///< Cursor position

#define ED(n) CSI #n "J"            ///< Erase display
#define EL(n) CSI #n "K"            ///< Erase in line
#define SU(n) CSI #n "S"            ///< Scroll up
#define SD(n) CSI #n "T"            ///< Scroll down

#define HVP(n,m) CSI #n ";" #m "f"  ///< Horizontal and vertical position

// #define SGR(n,m) CSI #n #m         ///< Select graphic rendition

#define AUX_ON  CSI "5i"             ///< AUX port on
#define AUX_OFF CSI "4i"             ///< AUX port off

// #define DSR CSI "6 n"             ///< Device status report

#define SCP CSI "s"                  ///< Save cursor position
#define RCP CSI "u"                  ///< Restore cursor position

#define HIDE_CURSOR CSI "?25l"       ///< DECTCEM: hide cursor
#define SHOW_CURSOR CSI "?25h"       ///< DECTCEM: show cursor
