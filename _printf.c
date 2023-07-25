#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Returned chars.
 */
int _printf(const char *format, ...)
{
	int a, prtd = 0, prtd_char = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[buff_ind++] = format[a];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			prtd_char++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &a);
			width = get_width(format, &a, list);
			precision = get_precision(format, &a, list);
			size = get_size(format, &a);
			++a;
			prtd = handle_print(format, &a, list, buffer,
				flags, width, precision, size);
			if (prtd == -1)
				return (-1);
			prtd_char += prtd;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (prtd_char);
}

/**
 * print_buffer - Prints the contents of the buffer
 * @buffer: Array of chars
 * @buff_ind: Index to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
