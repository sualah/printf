#include "main.h"
#include <unistd.h>

/**
 * _puts - function that prints a string, followed by a new line, to stdout
 *
 * @str: string pointer
 *
 * Return: nothing
 */
int _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i += 1;
	}
	return (i);
}

