#include "main.h"

/**
 * _printf - function to print
 * @format: string
 * Return: counter
 */

int _printf(const char *format, ...)
{
	int counter;
	va_list flag;

	delim del[] = {
		{"c", cfunc},
		{"s", sfunc},
		{"d", dfunc},
		{"i", dfunc},
		{0, NULL}
	};

	if (format == NULL)
		return (-1);

	va_start(flag, format);
	counter = get_del(format, del, flag);
	va_end(flag);

	return (counter);
}