#include "main.h"

/**
 * get_flags - Calculate active flags.
 * @format: Format in which to print the arguments.
 * @i: take parameter.
 * Return: Flags.
 */
int get_flags(const char *format, int *i)
{
	int a, cur_i;
	int flgs = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cur_i = *i + 1; format[cur_i] != '\0'; cur_i++)
	{
		for (a = 0; FLAGS_CH[a] != '\0'; a++)
			if (format[cur_i] == FLAGS_CH[a])
			{
				flgs |= FLAGS_ARR[a];
				break;
			}

		if (FLAGS_CH[a] == 0)
			break;
	}

	*i = cur_i - 1;

	return (flgs);
}
