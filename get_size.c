#include "main.h"

/**
 * get_size - Calculate the size to cast the argument.
 * @format: Format in which to print the arguments.
 * @i: Arguments to be printed.
 * Return: Size
 */
int get_size(const char *format, int *i)
{
	int cur_i = *i + 1;
	int sze = 0;

	if (format[cur_i] == 'l')
		sze = S_LONG;
	else if (format[cur_i] == 'h')
		sze = S_SHORT;

	if (sze == 0)
		*i = cur_i - 1;
	else
		*i = cur_i;

	return (sze);
}
