#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * convert - convert from int to string
 * @num: number
 * @base: number base
 * Return: string
 */
char *convert(unsigned int num, int base)
{
	char Rep[] = "0123456789ABCDEF";
	char *buffer = malloc(50 * sizeof(char));
	char *ptr = buffer;
	size_t len, i;


	if (buffer == NULL)
		return(NULL);
	do
	{
		*ptr++ = Rep[num % base];
		num /= base;
	}
	while (num != 0);
	*ptr = '\0';
	len = strlen(buffer);
	for (i = 0; i < len / 2; i++)
	{
		char temp = buffer[i];
		buffer[i] = buffer[len - i - 1];
		buffer[len - i - 1] = temp;
	}
	return (buffer);
}
