#include "main.h"
#include <stddef.h>
#include <stdio.h>

<<<<<<< HEAD
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
			spec_functions = conver_specs(format[i]);
			holder = (spec_functions) ? spec_functions(lists) : nothing_found(format[i]);
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
=======

/**
 * _printf - prints and input into the standard output
 * @format: the format string
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)

{
	int sum = 0;
	va_list ap;
	char *p, *start;

	params_t params = PARAMS_INIT;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))/* checking for NULL char */
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, ap);
		if (*p != '%')/*checking for the % specifier*/
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params)) /* while char at p is flag character */
		{
			p++; /* next character */
		}
		p = get_width(p, &params, ap);
		p = get_precision(p, &params, ap);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(start, p,
					params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
>>>>>>> 1e35c19322a393eb25358c83636b0d6ff580cb78
}
