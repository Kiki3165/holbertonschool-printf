#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * print_char - print char
 * @ap: variable list
 * Return: void
 */
int print_char(va_list ap)
{
	int c = va_arg(ap, int);

	return (write(1, &c, 1));
}
/**
 * print_str - print strings
 * @ap: variable list
 * Return: void
 *
 */
int print_str(va_list ap)
{

	char *next_arg;

	next_arg = va_arg(ap, char *);
	next_arg == NULL ? next_arg = "(null)" : next_arg;
	return (write(1, next_arg, strlen(next_arg)));
}
/**
 * _printf - print float
 * @format: the format scope
 * Return: void
 */
int _printf(const char * const format, ...)
{
	va_list ap;
	int i = 0;
	int j;
	int len = 0;

	print_arg ops[] = {
		{'c', print_char},
		{'s', print_str},
		{0, NULL}
	};
	if ((format == NULL))
	{
		return (-1);
	}
	va_start(ap, format);
	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				i = i + 1;
				len += write(1, &format[i], 1);
			}
			else
			{
				for (j = 0; ops[j].t_arg; j++)
				{
					if (ops[j].t_arg == format[i + 1])
					{
						len += ops[j].f(ap);
						i = i + 1;
					}
				}
			}
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}
