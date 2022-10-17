#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * char_find - converts a char to a string
 * @c: char
 * Return: string
 */

char *char_find(va_list c)
{
	char string[2];
	char *p;

	p = string;
	string[0] = va_arg(c, int);
	string[1] = '\0';
	return (p);
}

/**
 * string_find - passes a string to print
 * @s: string
 * Return: "string"
 */

char *string_find(va_list s)
{
	char *string;

	string = va_arg(s, char *);
	if (string == NULL)
		return ("(null)");
	return (string);
}

/**
 * percent_find - passes a '%' sign
 * Return: percent sign as a character
 */

char *percent_find(void)
{
	char *string;

	string = "%";
	return (string);
}
