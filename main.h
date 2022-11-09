#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char * const format, ...);
void print_char(va_list ap);
void print_string(va_list ap);

/**
 * struct print - a structure
 *
 * @t_arg: The operator associated with a function
 * @f: The function associated
 */
typedef struct print
{
	char t_arg;
	void (*f)(va_list);
} print_arg;

#endif
