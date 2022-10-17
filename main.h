#ifndef MAIN_H
#define MAIN_H
#define BUFSIZE 1024
#include <stdarg.h>

char *(*get_spec_func(char s))(va_list);
int _printf(const char *format, ...);


#endif
