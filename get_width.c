#include "main.h"

/**
 * get_width - Calculates the width.
 * @format: Format to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list arguments.
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int cur_i;
	int wdt = 0;

	for (cur_i = *i + 1; format[cur_i] != '\0'; cur_i++)
	{
		if (is_digit(format[cur_i]))
		{
			wdt *= 10;
			wdt += format[cur_i] - '0';
		}
		else if (format[cur_i] == '*')
		{
			cur_i++;
			wdt = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cur_i - 1;

	return (wdt);
}
