#include "variadic_functions.h"

/**
 * print_char - function that print one char
 * @all: char to print
 *
 * Return: Null value
 */
void print_char(va_list all)
{
	printf("%c", va_arg(all, int));
}

/**
 * print_int - function that print an int
 * @all: int to print
 *
 * Return: Null value
 */
void print_int(va_list all)
{
	printf("%d", va_arg(all, int));
}

/**
 * print_float - function that print a float
 * @all: float to print
 *
 * Return: Null value
 */
void print_float(va_list all)
{
	printf("%f", va_arg(all, double));
}

/**
 * print_string - function that print a string
 * @all: string to print
 *
 * Return: Null value
 */
void print_string(va_list all)
{
	char *string;

	string = va_arg(all, char *);
	if (string == NULL)
		string = "(nil)";

	printf("%s", string);
}

/**
 * print_all - function that prints anything
 * @format: type of arguments passed to the function
 *
 * Return: Null value
 */
void print_all(const char * const format, ...)
{
	int i = 0, j = 0;
	char *str = "";

	print_arg all[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string},
		{NULL, NULL},
	};

	va_list to_print;

	va_start(to_print, format);


	while (format != NULL && format[j])
	{
		while (i < 4)
		{
			if (format[j] == *all[i].t_arg)
			{
				printf("%s", str);
				all[i].f(to_print);
				str = ", ";
			}
			i++;
		}
		i = 0;
		j++;
	}

	va_end(to_print);
	printf("\n");
}