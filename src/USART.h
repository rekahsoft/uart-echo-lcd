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
 * @file USART.h
 * @author Collin J. Doering <collin.doering@rekahsoft.ca>
 * @date Oct  6, 2015
 * @brief Functions to initialize, read and write using USART.
 */

/**
   Initialize USART hardware.
*/
void initUSART(void);

/**
   Transmit a single byte using USART.
*/
void transmitByte(uint8_t data);

/**
   Transmit a string using USART.
*/
void transmitString(const char* data);

/**
   Receive a single byte using USART
*/
uint8_t receiveByte(void);
