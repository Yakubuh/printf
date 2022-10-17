#include "main.h"
#include <stddef.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: is a character string
 *
 * Return: the number of characters
 */

int _printf(const char *format, ...)
{
	int i, buffend = 0;
	double totalBuffer = 0;
	double *total;
	char *holder;
	char buffer[BUFSIZE];
	char *(*spec_func)(va_list) = NULL;
	va_list lists;

	if (!format)
		return (-1);
	va_start(lists, format);
	total = &totalBuffer;
	for (i = 0; i < BUFSIZE; i++)
		buffer[i] = 0;
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			spec_func = conver_specs(format[i]);
			holder = (spec_func) ? spec_func(lists) : nothing_found(format[i]);
			if (holder)
				buffend = alloc_buffer(holder, _strlen(holder), buffer, buffend, total);
		}
		else
		{
			holder = chartos(format[i]);
			buffend = alloc_buffer(holder, 1, buffer, buffend, total);
		}
	}
	_puts(buffer, buffend);
	va_end(lists);
	return (totalBuffer + buffend);
}
