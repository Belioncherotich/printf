#include "main.h"

/**
 * get_precision - Calculates the precision for printing.
 * @format: Format to print the arguments.
 * @i: List arguments to be printed.
 * @list: list arguments.
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int cur_i = *i + 1;
	int precs = -1;

	if (format[cur_i] != '.')
		return (precs);

	precs = 0;

	for (cur_i += 1; format[cur_i] != '\0'; cur_i++)
	{
		if (is_digit(format[cur_i]))
		{
			precs *= 10;
			precs += format[cur_i] - '0';
		}
		else if (format[cur_i] == '*')
		{
			cur_i++;
			precs = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cur_i - 1;

	return (precs);
}
