#include "main.h"

/**
* get_precision - Calculates the precision for printing
* @format: Formatted string in which to print the arguments
* @i: List of arguments to be printed.
* @list: list of arguments.
*
* Return: Precision.
*/
int get_precision(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	
	int written = 0;
	while (*format != '\0') {

	if (*format == '%') {
		++format;
		int precision = -1;
		if (*format == '.') {
			++format;
			precision = 0;
			while (is_digit(*format)) {
				precision *= 10;
				precision += *format - '0';
				++format;
			}
		}
	if (*format == 'd') {
		int value = va_arg(args, int);
		written += printf("%.*d", precision, value);
	} else if (*format == 'f') {
		double value = va_arg(args, double);
		written += printf("%.*f", precision, value);
	} else if (*format == 's') {
		char *value = va_arg(args, char*);
		written += printf("%.*s", precision, value);
	}
	} else {
		putchar(*format);
		++written;
	}
		++format;
	}

	va_end(args);
	return written;
}

int main()
{
	my_printf("Printing an integer: %d\n", 123);
	my_printf("Printing a float with precision: %.2f\n", 3.14159);
	my_printf("Printing a string with precision: %.4s\n", "hello world");
	return 0;
}
