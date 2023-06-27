#include "main.h"
#include <stdio.h>

/**
 * _print_hex - prints the hexadecimal representation of a number
 * @num: The number to print
 *
 * Return: The number of characters written.
 */
int _print_hex(int num)
{
	char *hex = "0123456789ABCDEF";
	int count = 0;

	if (num / 16)
		count += _print_hex(num / 16);

	_putchar(hex[num % 16]);
	count++;
    return (count);
}
