#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char c;
    char *s;

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
                    while (*s)
                    {
                        count += write(1, s, 1);
                        s++;
                    }
                    break;
                case '%':
                    count += write(1, &format[i], 1);
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
    return count;
}

