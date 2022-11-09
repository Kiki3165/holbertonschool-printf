#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

int _strlen(char *s)
{
    int i = 0
    while (s[i])
    i++;
    return (i);
}

int _putchar(char c)
{
    return (write(1, &c, 1));
}

void print_char(va_list ap)
{
int c = va_arg(ap)
}

void print_string(va list ap);
{
    
}