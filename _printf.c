#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - print values
 * @format: string
 * @...: variable argument
 * Return: return character count
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int digits[10];
        int num_digits = 0;
	int i;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
				{
					int c = va_arg(args, int);
					_putchar(c);
					count++;
					break;
				}
				case 's':
				{
					const char *s = va_arg(args, const char *);
					while (*s != '\0')
					{
						_putchar(*s);
						s++;
						count++;
					}
					break;
				}
				case 'd':
				case 'i':
				{
					int num = va_arg(args, int);
					if (num < 0)
					{
						_putchar('-');
						count++;
						num = -num;
					}
					do {
						digits[num_digits++] = num % 10;
						num /= 10;
					} while (num > 0);
					for (i = num_digits - 1; i >= 0; i--)
					{
						_putchar('0' + digits[i]);
						count++;
					}
					break;
				}
				case '%':
				{
					_putchar('%');
					count++;
					break;
				}
				default:
					break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
