/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
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
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

//
// lcd/dogm/status/bed.h - Status Screen Bed bitmaps
//

#if ENABLED(STATUS_ALT_BED_BITMAP)

  #define STATUS_BED_ANIM
  #define STATUS_BED_WIDTH  24

  #define STATUS_BED_TEXT_X (STATUS_BED_X + 11)

  const unsigned char status_bed_bmp[] PROGMEM = {
    B11111111,B11111111,B11000000,
    B01000000,B00000000,B00100000,
    B00100000,B00000000,B00010000,
    B00010000,B00000000,B00001000,
    B00001000,B00000000,B00000100,
    B00000100,B00000000,B00000010,
    B00000011,B11111111,B11111111
  };

  #if HAS_LEVELING
    const unsigned char status_bed_leveled_bmp[] PROGMEM = {
      B11111111,B11111111,B11001110,
      B01000000,B00100000,B00100100,
      B00100000,B00010000,B00010000,
      B00011111,B11111111,B11111000,
      B00001000,B00000100,B00000100,
      B00100100,B00000010,B00000010,
      B01110011,B11111111,B11111111
    };
  #endif

  const unsigned char status_bed_on_bmp[] PROGMEM = {
    B00000010,B00100010,B00000000,
    B00000100,B01000100,B00000000,
    B00000100,B01000100,B00000000,
    B00000010,B00100010,B00000000,
    B00000001,B00010001,B00000000,
    B11111111,B11111111,B11000000,
    B01000000,B10001000,B10100000,
    B00100001,B00010001,B00010000,
    B00010010,B00100010,B00001000,
    B00001000,B00000000,B00000100,
    B00000100,B00000000,B00000010,
    B00000011,B11111111,B11111111
  };

  #if HAS_LEVELING
    const unsigned char status_bed_leveled_on_bmp[] PROGMEM = {
      B00000010,B00100010,B00000000,
      B00000100,B01000100,B00000000,
      B00000100,B01000100,B00000000,
      B00000010,B00100010,B00000000,
      B00000001,B00010001,B00000000,
      B11111111,B11111111,B11001110,
      B01000000,B10101000,B10100100,
      B00100001,B00010001,B00010000,
      B00011111,B11111111,B11111000,
      B00001000,B00000100,B00000100,
      B00100100,B00000010,B00000010,
      B01110011,B11111111,B11111111
    };
  #endif

#else

  #define STATUS_BED_WIDTH  21

  #ifdef STATUS_BED_ANIM

    const unsigned char status_bed_bmp[] PROGMEM = {
      B00011111,B11111111,B11111000,
      B00011111,B11111111,B11111000
    };

    const unsigned char status_bed_on_bmp[] PROGMEM = {
      B00000100,B00010000,B01000000,
      B00000010,B00001000,B00100000,
      B00000010,B00001000,B00100000,
      B00000100,B00010000,B01000000,
      B00001000,B00100000,B10000000,
      B00010000,B01000001,B00000000,
      B00010000,B01000001,B00000000,
      B00001000,B00100000,B10000000,
      B00000100,B00010000,B01000000,
      B00000000,B00000000,B00000000,
      B00011111,B11111111,B11111000,
      B00011111,B11111111,B11111000
    };

  #else

    const unsigned char status_bed_bmp[] PROGMEM = {
      B00000100,B00010000,B01000000,
      B00000010,B00001000,B00100000,
      B00000010,B00001000,B00100000,
      B00000100,B00010000,B01000000,
      B00001000,B00100000,B10000000,
      B00010000,B01000001,B00000000,
      B00010000,B01000001,B00000000,
      B00001000,B00100000,B10000000,
      B00000100,B00010000,B01000000,
      B00000000,B00000000,B00000000,
      B00011111,B11111111,B11111000,
      B00011111,B11111111,B11111000
    };

  #endif

#endif

#ifndef STATUS_BED_X
  #define STATUS_BED_X (LCD_PIXEL_WIDTH - (STATUS_BED_BYTEWIDTH + STATUS_CHAMBER_BYTEWIDTH + STATUS_FAN_BYTEWIDTH) * 8 MINUS_TERN0(STATUS_HEAT_PERCENT, 4))
#endif
