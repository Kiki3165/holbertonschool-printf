#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
*
*print_integer - print integer
*
*@ap: variable list
*
*/
int print_integer(va_list ap)
{
    int counter;
	int number, divisor;
	unsigned int tmp;

	divisor = 1;
	number = va_arg(ap, int);
	counter = 0;

	if (number < 0)
	{
		counter += _putchar('-');
		tmp = number * -1;
	}
	else
		tmp = number;

	while (tmp / divisor > 9)
		divisor = divisor * 10;

	while (divisor != 0)
	{
	counter += _putchar(tmp / divisor + '0');
	tmp %= divisor;
	divisor = divisor / 10;
	}
	return (counter);
}
/**
 *print_char - print char
 *@ap: variable list
 *Return: void
 */
int print_char(va_list ap)
{
    int c = va_arg(ap, int);
    return (write(1, &c, 1));
}
/**
*print_str - print strings
*@ap: variable list
*Return: void
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
int i = 0, j = 0, len = 0;
print_arg ops[] = {
    {'c', print_char},
    {'s', print_str},
	{'i', print_integer},
	{'d', print_integer},
    {0, NULL}
    };
    if (format == NULL || ((format[i] == '%') && (format[i + 1] == '\0')))
    return (-1);
    va_start(ap, format);
    for (; format && format[i] != '\0'; i++)
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
                for (j = 0; ops[j].t_arg != 0; j++)
                    if (ops[j].t_arg == format[i + 1])
                    {
                        len += ops[j].f(ap);
                        i = i + 1;
                        break;
                    }
                if (ops[j].t_arg == 0)
                    len += write(1, &format[i], 1);
            }
        }
        else
            len += write(1, &format[i], 1);
    }
    va_end(ap);
    return (len);
}
