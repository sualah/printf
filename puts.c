#include "main.h"
#include <unistd.h>
#define BUFFER_SIZE 1024

/**
 * _puts - function that prints a string, followed by a new line, to stdout
 *
 * @str: string pointer
 *
 * Return: nothing
 */
int _puts(char *str)
{
	int i;
	char buffer[1024];

	for (i = 0; str[i] != '\0'; i++)
	{
		buffer[i] = str[i];
		if (i == 1023)
		{
			write(1, buffer, i + 1);
			i = -1;
		}
	}
	write(1, buffer, i);
	return (i);
}
