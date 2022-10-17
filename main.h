#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct spec_types - Struct to get function of specifier
 * @spec: specifier
 * @f: The function associated
 */

typedef struct spec_types
{
	char *spec;
	char *(*f)();
} s_types;

char *(*conver_specs(char s))(va_list);
int _printf(const char *format, ...);
char *char_find(va_list c);
char *string_find(va_list s);
char *percent_find(void);
char *nothing_found(char c);
int _strlen(char *s);
char *chartos(char c);
void _puts(char *buffer, int size);
int alloc_buffer(char *hold, int hlen, char *buffer, int size, double *total);

#endif
