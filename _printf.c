#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string composed of zero or more directives
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char c;
	char *s;
	int d;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			switch (format[i])
			{
				case 'c':
					c = va_arg(args, int);
					count += write(1, &c, 1);
					break;
				case 's':
    s = va_arg(args, char *);
    if (s == NULL)
    {
        s = "(null)";
    }
    while (*s)
    {
        count += write(1, s, 1);
        s++;
    }
    break;

				case '%':
					count += write(1, &format[i], 1);
					break;
				case 'd':
				case 'i':
					d = va_arg(args, int);
					count += print_number(d);
					break;
				default:
					count += write(1, &format[i - 1], 1);
					count += write(1, &format[i], 1);
			}
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}

	va_end(args);
	return (count);
}

/**
 * print_number - prints an integer
 * @n: integer to be printed
 * Return: the number of characters printed
 */
int print_number(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += write(1, "-", 1);
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
	{
		count += print_number(num / 10);
	}

	count += write(1, &"0123456789"[num % 10], 1);

	return (count);
}

