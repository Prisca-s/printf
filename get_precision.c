#include "main.h"

/**
* get_precision - Calculates the precision for printing
* @format: Formatted string in which to print the arguments
* @i: List of arguments to be printed.
* @list: list of arguments.
*
* Return: Precision.
*/
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}

int get_precision(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	
	int written = 0;
	while (*format != '\0') {
		if (*format == '%') {
		++format;
		int precision = get_precision(format, (int*)&format, args);
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
