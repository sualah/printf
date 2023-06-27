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
					char *s = va_arg(args, char *);

					count += _puts(s);
					break;
				}
				case 'd':
				case 'i':
				{
					int num = va_arg(args, int);

					if (num < 0)
					{
						num = -num;
						_putchar('-');
						count++;
					}
					count += _puts(convert(num, 10));
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
