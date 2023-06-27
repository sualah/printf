#include "main.h"
#include <stdio.h>

/**
 * _puts - function that prints a string, followed by a new line, to stdout
 *
 * @str: string pointer
 *
 * Return: The number of characters written.
 */
int _puts_hex(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0')
    {
        if (str[i] < ' ' || str[i] >= 127)
        {
            _putchar('\\');
            _putchar('x');
            if (str[i] < 16)
                _putchar('0');
            count += 3;
            count += _print_hex(str[i]);
        }
        else
        {
            _putchar(str[i]);
            count++;
        }

        i++;
    }

    return (count);
}
