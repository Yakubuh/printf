#include "main.h"
#include <stddef.h>

/**
 * conver_specs - checks specifier and return function
 * @s: type
 *
 * Return: pointer
 */

char *(conver_specs(char s))(va_list)
{
	int i;

	s_types spec_types[] = {
		{"c", char_find},
		{"s", string_find},
		{"%", percent_find},
	};

	for (i = 0; spec_types[i].spec; i++)
		if (s == *spec_types[i].spec)
			return (spec_types[i].f);

	return (spec_types[i].f);
}
