#include <stdio.h>   // Include standard I/O library for putchar
#include <stdarg.h>  // Include standard argument library for va_list, va_start, va_arg, and va_end

// Function prototype for _printf
int _printf(const char *format, ...) {
    va_list args;              // Declare a variable to hold the variable arguments
    int printed_chars = 0;     // Variable to count the number of characters printed
    char *str;                 // Pointer to a string for the %s specifier
    char ch;                   // Variable to hold a character for the %c specifier

    // Initialize the va_list to retrieve additional arguments after 'format'
    va_start(args, format);

    // Loop through each character in the format string
    for (const char *ptr = format; *ptr != '\0'; ptr++) {
        if (*ptr == '%') {     // Check if the current character is a '%'
            ptr++;             // Move to the next character to check the specifier
            switch (*ptr) {    // Switch based on the specifier character
                case 'c':      // Handle %c specifier
                    ch = (char) va_arg(args, int); // Retrieve the character argument
                    putchar(ch);                   // Print the character
                    printed_chars++;               // Increment the character count
                    break;
                case 's':      // Handle %s specifier
                    str = va_arg(args, char *);    // Retrieve the string argument
                    for (; *str != '\0'; str++) {  // Loop through each character in the string
                        putchar(*str);             // Print the character
                        printed_chars++;           // Increment the character count
                    }
                    break;
                case '%':      // Handle %% specifier
                    putchar('%');                  // Print a literal '%'
                    printed_chars++;               // Increment the character count
                    break;
                default:       // Handle unexpected format specifiers
                    putchar('%');                  // Print the '%' character
                    putchar(*ptr);                 // Print the unknown specifier character
                    printed_chars += 2;            // Increment the count for two characters
                    break;
            }
        } else {
            // If the character is not '%', print it as-is
            putchar(*ptr);
            printed_chars++;
        }
    }

    // Clean up the va_list when done
    va_end(args);

    // Return the total number of characters printed
    return printed_chars;
}

