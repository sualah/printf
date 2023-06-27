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
					
					int sign = 0;

					if (num < 0)
					{
						num = -num;
						sign = '-';
					}
					else if (*format == '+')
					{
						sign = '+';
					}
					else if (*format == ' ')
					{
						sign = ' ';
					}

					if (sign != 0)
					{
						_putchar(sign);
						count++;
					}
				       /*	if (num < 0)
					{
						num = -num;
						_putchar('-');
						count++;
					} */
					count += _puts(convert(num, 10));
					break;
				}
				case 'b':
				{
					int num = va_arg(args, int);
					
					if (*format == '#')
					{
						_putchar('0');
						_putchar('b');
						count += 2;
					}
					count += _puts(convert(num, 2));
					break;
				}
				case 'u':
				{
					unsigned int num = va_arg(args, unsigned int);
					
					if (*format == '#')
					{
						_putchar('0');
						count++;
					}
					count += _puts(convert(num, 10));
					break;
				}
				case 'o':
				{
					unsigned int num = va_arg(args, unsigned int);

					if (*format == '#')
					{
						_putchar('0');
						count++;
					}
					count += _puts(convert(num, 8));
					break;
				}
				case 'x':
				case 'X':
				{
					unsigned int num = va_arg(args, unsigned int);

					if (*format == '#')
					{
						_putchar('0');
						_putchar(*format);
						count += 2;
					}
					count += _puts(convert(num, 16));
					break;
				}
				case 'S':
				{
					char *s = va_arg(args, char *);

					count += _puts_hex(s);
					break;
				}
				case 'p':
				{
					void *ptr = va_arg(args, void *);

					count += _puts("0x");
					count += _puts(convert((unsigned long)ptr, 16));
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
