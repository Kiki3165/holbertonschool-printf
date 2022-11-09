#ifndef
#define

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
void print_char(va_list ap);
void print_string(va_list ap);
void print_percent(va_list ap);

typedef struct print
{
	char *t_arg;
	void (*f)(va_list);
} print_arg;

#endif