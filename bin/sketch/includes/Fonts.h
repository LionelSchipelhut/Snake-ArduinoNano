#ifndef __FONTS_H__
#define __FONTS_H__

#include <Adafruit_GFX.h>

const uint8_t Roboto_10Bitmaps[] PROGMEM = {

	// Bitmap Data:
	0x00, // ' '
	0xAA,0x88, // '!'
	0xDB,0x00, // '"'
	0x51,0x4F,0x94,0xFA,0x8A,0x00, // '#'
	0x47,0x25,0x06,0x0A,0x5C,0x40, // '$'
	0xC1,0xB3,0x41,0x05,0xCA,0x87,0x00, // '%'
	0xE2,0x4A,0x30,0xAA,0x4E,0x80, // '&'
	0x90, // '''
	0x52,0x49,0x24,0x88, // '('
	0x84,0x42,0x22,0x24,0x48, // ')'
	0x26,0x88,0xE0, // '*'
	0x20,0x8F,0x88,0x20, // '+'
	0x50, // ','
	0xE0, // '-'
	0x80, // '.'
	0x11,0x08,0x44,0x22,0x10, // '/'
	0xE4,0xA5,0x29,0x4B,0x80, // '0'
	0x6A,0x22,0x22,0x20, // '1'
	0x71,0x28,0x84,0x21,0x07,0x80, // '2'
	0x71,0x20,0x8C,0x0B,0x27,0x00, // '3'
	0x10,0x43,0x14,0x53,0xE1,0x00, // '4'
	0xF4,0x38,0x21,0x4B,0x80, // '5'
	0x64,0x39,0x29,0x49,0x80, // '6'
	0xF8,0x21,0x04,0x20,0x84,0x00, // '7'
	0xE4,0xA4,0xC9,0x4B,0x80, // '8'
	0x71,0x28,0x92,0x78,0x67,0x00, // '9'
	0x80,0x80, // ':'
	0x40,0x05,0x00, // ';'
	0x13,0x38,0x20, // '<'
	0xF0,0x3C, // '='
	0x83,0x1D,0x00, // '>'
	0x74,0x84,0x42,0x00,0x80, // '?'
	0x3C,0x21,0x26,0x95,0x4A,0xA5,0x52,0xF9,0x80,0x78,0x00, // '@'
	0x10,0x30,0x28,0x28,0x7C,0x44,0xC6, // 'A'
	0xF2,0x49,0x3C,0x8A,0x2F,0x00, // 'B'
	0x72,0x28,0x20,0x82,0x27,0x00, // 'C'
	0xF2,0x68,0xA2,0x8A,0x6F,0x00, // 'D'
	0xF4,0x21,0xE8,0x43,0xC0, // 'E'
	0xF4,0x21,0xE8,0x42,0x00, // 'F'
	0x72,0x28,0x2E,0x8A,0x27,0x00, // 'G'
	0x8A,0x28,0xBE,0x8A,0x28,0x80, // 'H'
	0xAA,0xA8, // 'I'
	0x08,0x20,0x82,0x0A,0x27,0x00, // 'J'
	0x9A,0x4A,0x38,0xA2,0x48,0x80, // 'K'
	0x84,0x21,0x08,0x43,0xC0, // 'L'
	0x86,0xC6,0xC6,0xCA,0xAA,0xB2,0x92, // 'M'
	0x8B,0x2C,0xAA,0x9A,0x68,0x80, // 'N'
	0x72,0x28,0xA2,0x8A,0x27,0x00, // 'O'
	0xF2,0x28,0xBC,0x82,0x08,0x00, // 'P'
	0x72,0x28,0xA2,0x8A,0x27,0x02, // 'Q'
	0xF2,0x28,0xBC,0x92,0x48,0x80, // 'R'
	0x78,0x91,0x11,0xC0,0xD8,0x9E,0x00, // 'S'
	0xFC,0x40,0x81,0x02,0x04,0x08,0x00, // 'T'
	0x85,0x0A,0x14,0x28,0x49,0x1E,0x00, // 'U'
	0x84,0x91,0x22,0x43,0x06,0x0C,0x00, // 'V'
	0x88,0x96,0x45,0x51,0x54,0x55,0x18,0x82,0x20, // 'W'
	0xC4,0x90,0xC0,0x83,0x09,0x31,0x00, // 'X'
	0x84,0x91,0x21,0x82,0x04,0x08,0x00, // 'Y'
	0xF8,0x10,0x41,0x02,0x08,0x3F,0x00, // 'Z'
	0xD2,0x49,0x24,0x98, // '['
	0x82,0x10,0x82,0x10,0x82, // '\'
	0xC9,0x24,0x92,0x58, // ']'
	0x63,0x24, // '^'
	0xF8, // '_'
	0xC8, // '`'
	0x72,0x47,0x24,0x68, // 'a'
	0x84,0x21,0xE9,0x4A,0x5E, // 'b'
	0x73,0x28,0x22,0x70, // 'c'
	0x10,0x85,0xE9,0x4A,0x5E, // 'd'
	0x72,0x2F,0xA0,0x78, // 'e'
	0x64,0x4E,0x44,0x44, // 'f'
	0xF4,0xA5,0x2F,0x0B,0x80, // 'g'
	0x84,0x21,0xE9,0x4A,0x52, // 'h'
	0x8A,0xA8, // 'i'
	0xC2,0x49,0x24,0x80, // 'j'
	0x84,0x21,0x6C,0x62,0x92, // 'k'
	0xAA,0xAA, // 'l'
	0xFE,0x92,0x92,0x92,0x92, // 'm'
	0xF4,0xA5,0x29,0x00, // 'n'
	0xF4,0xA5,0x2F,0x00, // 'o'
	0xF4,0xA5,0x2F,0x42,0x00, // 'p'
	0xF4,0xA5,0x2F,0x08,0x40, // 'q'
	0x50,0x00, // 'r'
	0x71,0x27,0x22,0x70, // 's'
	0x4E,0x44,0x46, // 't'
	0x94,0xA5,0x2F,0x00, // 'u'
	0x89,0x45,0x18,0x20, // 'v'
	0x9B,0x2D,0x16,0x84,0x82,0x40, // 'w'
	0xD9,0x42,0x14,0xD8, // 'x'
	0x89,0x45,0x18,0x20,0x84,0x00, // 'y'
	0xF0,0x42,0x10,0xF8, // 'z'
	0x24,0x44,0x84,0x44,0x42, // '{'
	0xAA,0xAA, // '|'
	0x84,0x44,0x24,0x44,0x48 // '}'
};
const GFXglyph Roboto_10Glyphs[] PROGMEM = {
// bitmapOffset, width, height, xAdvance, xOffset, yOffset
	  {     0,   1,   1,   3,    0,    0 }, // ' '
	  {     1,   2,   7,   4,    1,   -7 }, // '!'
	  {     3,   3,   3,   4,    1,   -8 }, // '"'
	  {     5,   6,   7,   7,    1,   -7 }, // '#'
	  {    11,   5,   9,   7,    1,   -8 }, // '$'
	  {    17,   7,   7,   8,    1,   -7 }, // '%'
	  {    24,   6,   7,   7,    1,   -7 }, // '&'
	  {    30,   3,   2,   3,    0,   -8 }, // '''
	  {    31,   3,  10,   4,    1,   -8 }, // '('
	  {    35,   4,  10,   4,    0,   -8 }, // ')'
	  {    40,   5,   4,   5,    0,   -7 }, // '*'
	  {    43,   6,   5,   7,    0,   -6 }, // '+'
	  {    47,   3,   2,   3,    0,   -1 }, // ','
	  {    48,   4,   1,   4,    0,   -3 }, // '-'
	  {    49,   2,   1,   4,    1,   -1 }, // '.'
	  {    50,   5,   8,   5,    0,   -7 }, // '/'
	  {    55,   5,   7,   7,    1,   -7 }, // '0'
	  {    60,   4,   7,   7,    1,   -7 }, // '1'
	  {    64,   6,   7,   7,    0,   -7 }, // '2'
	  {    70,   6,   7,   7,    0,   -7 }, // '3'
	  {    76,   6,   7,   7,    0,   -7 }, // '4'
	  {    82,   5,   7,   7,    1,   -7 }, // '5'
	  {    87,   5,   7,   7,    1,   -7 }, // '6'
	  {    92,   6,   7,   7,    0,   -7 }, // '7'
	  {    98,   5,   7,   7,    1,   -7 }, // '8'
	  {   103,   6,   7,   7,    0,   -7 }, // '9'
	  {   109,   2,   5,   3,    1,   -5 }, // ':'
	  {   111,   3,   6,   3,    0,   -5 }, // ';'
	  {   114,   5,   4,   6,    0,   -5 }, // '<'
	  {   117,   5,   3,   6,    1,   -5 }, // '='
	  {   119,   5,   4,   6,    1,   -5 }, // '>'
	  {   122,   5,   7,   6,    0,   -7 }, // '?'
	  {   127,   9,   9,  10,    1,   -7 }, // '@'
	  {   138,   8,   7,   8,    0,   -7 }, // 'A'
	  {   145,   6,   7,   7,    1,   -7 }, // 'B'
	  {   151,   6,   7,   8,    1,   -7 }, // 'C'
	  {   157,   6,   7,   8,    1,   -7 }, // 'D'
	  {   163,   5,   7,   7,    1,   -7 }, // 'E'
	  {   168,   5,   7,   7,    1,   -7 }, // 'F'
	  {   173,   6,   7,   8,    1,   -7 }, // 'G'
	  {   179,   6,   7,   8,    1,   -7 }, // 'H'
	  {   185,   2,   7,   4,    1,   -7 }, // 'I'
	  {   187,   6,   7,   7,    0,   -7 }, // 'J'
	  {   193,   6,   7,   7,    1,   -7 }, // 'K'
	  {   199,   5,   7,   6,    1,   -7 }, // 'L'
	  {   204,   8,   7,  10,    1,   -7 }, // 'M'
	  {   211,   6,   7,   8,    1,   -7 }, // 'N'
	  {   217,   6,   7,   8,    1,   -7 }, // 'O'
	  {   223,   6,   7,   7,    1,   -7 }, // 'P'
	  {   229,   6,   8,   8,    1,   -7 }, // 'Q'
	  {   235,   6,   7,   7,    1,   -7 }, // 'R'
	  {   241,   7,   7,   7,    0,   -7 }, // 'S'
	  {   248,   7,   7,   7,    0,   -7 }, // 'T'
	  {   255,   7,   7,   7,    0,   -7 }, // 'U'
	  {   262,   7,   7,   7,    0,   -7 }, // 'V'
	  {   269,  10,   7,  10,    0,   -7 }, // 'W'
	  {   278,   7,   7,   7,    0,   -7 }, // 'X'
	  {   285,   7,   7,   7,    0,   -7 }, // 'Y'
	  {   292,   7,   7,   7,    0,   -7 }, // 'Z'
	  {   299,   3,  10,   4,    1,   -8 }, // '['
	  {   303,   5,   8,   5,    0,   -7 }, // '\'
	  {   308,   3,  10,   4,    0,   -8 }, // ']'
	  {   312,   5,   3,   5,    0,   -7 }, // '^'
	  {   314,   6,   1,   6,    0,    0 }, // '_'
	  {   315,   3,   2,   4,    0,   -8 }, // '`'
	  {   316,   6,   5,   6,    0,   -5 }, // 'a'
	  {   320,   5,   8,   7,    1,   -8 }, // 'b'
	  {   325,   6,   5,   6,    0,   -5 }, // 'c'
	  {   329,   5,   8,   7,    1,   -8 }, // 'd'
	  {   334,   6,   5,   6,    0,   -5 }, // 'e'
	  {   338,   4,   8,   4,    0,   -8 }, // 'f'
	  {   342,   5,   7,   7,    1,   -5 }, // 'g'
	  {   347,   5,   8,   7,    1,   -8 }, // 'h'
	  {   352,   2,   7,   3,    1,   -7 }, // 'i'
	  {   354,   3,   9,   3,    0,   -7 }, // 'j'
	  {   358,   5,   8,   6,    1,   -8 }, // 'k'
	  {   363,   2,   8,   3,    1,   -8 }, // 'l'
	  {   365,   8,   5,  10,    1,   -5 }, // 'm'
	  {   370,   5,   5,   7,    1,   -5 }, // 'n'
	  {   374,   5,   5,   7,    1,   -5 }, // 'o'
	  {   378,   5,   7,   7,    1,   -5 }, // 'p'
	  {   383,   5,   7,   7,    1,   -5 }, // 'q'
	  {   388,   3,   5,   4,    1,   -5 }, // 'r'
	  {   390,   6,   5,   6,    0,   -5 }, // 's'
	  {   394,   4,   6,   4,    0,   -6 }, // 't'
	  {   397,   5,   5,   7,    1,   -5 }, // 'u'
	  {   401,   6,   5,   6,    0,   -5 }, // 'v'
	  {   405,   9,   5,   9,    0,   -5 }, // 'w'
	  {   411,   6,   5,   6,    0,   -5 }, // 'x'
	  {   415,   6,   7,   6,    0,   -5 }, // 'y'
	  {   421,   6,   5,   6,    0,   -5 }, // 'z'
	  {   425,   4,  10,   4,    0,   -8 }, // '{'
	  {   430,   2,   8,   3,    1,   -7 }, // '|'
	  {   432,   4,  10,   4,    0,   -8 } // '}'
};
const GFXfont Roboto_10 PROGMEM = {
(uint8_t  *)Roboto_10Bitmaps,(GFXglyph *)Roboto_10Glyphs,0x20, 0x7E, 13};

#endif