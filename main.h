#ifndef MAIN_H
#define MAIN_H
#define BUFSIZE 1024
#include <stdarg.h>

/**
 * struct specifier - contains specifiers for printf
 *
 * @width: width of field to print
 * @precision: precision of field to print
 * @length: modifies type length. h/l flags. 0 default, +1 per l, -1 per h
 * @widthflag: tells whether width is set
 * @precisionflag: tells whether precision is set
 * @left: left justify, '-'. 0 for right, 1 for left
 * @sign: force sign, '+'. 0 for no, 1 for yes
 * @space: space pad left side of positive numbers if leading 0s. 0 no 1 yes
 * @zero: zero pad numbers up to width. 0 for no, 1 for yes.
 * @zerox: add leading 0, 0x, or 0X to o, x or X specifiers. 0 no 1 yes
 * @specifier: the data type to print, c, s, d, x, etc.
 */

// Yakubu's code
/*typedef struct specifier
{
	unsigned int width;
	unsigned int precision;
	int length;
	char widthflag;
	char precisionflag;
	char left;
	char sign;
	char space;
	char zero;
	char zerox;
	char specifier;
} specifier;
*/

int _printf(const char *format, ...);


#endif
