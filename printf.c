#include <stdio.h>
#include "main.h"

#include <stddef.h>

/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: printed char
 */

int _printf(const char *format, ...)
{
	int i, ibuff = 0;
	double *printed;
	double all_ibuff = 0;
	char buff_size[BUFSIZE];
	char *container;
	va_list lists;
	char *(*spec_func)(va_list) = NULL;

	if (format == NULL)
		return (-1);
	va_start(lists, format);
	printed = &all_ibuff;
	for (i = 0; i < BUFSIZE; i++)
		buff_size[i] = 0;
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			spec_func = get_spec_func(format[i]);
			container = (spec_func) ? spec_func(lists) : nothing_found(format[i]);
			if (container)
				ibuff = alloc_buffer(container, _strlen(container), buff_size, ibuff, printed);
		}
		else
		{
			container = chartos(format[i]);
			ibuff = alloc_buffer(container, 1, buff_size, ibuff, printed);
		}
	}
	_puts(buff_size, ibuff);
	va_end(lists);
	return (all_ibuff + ibuff);
}
