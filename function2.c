#include "main.h"

/*** PRINT_POINTER ***/
/**
 * print_pointer - Prints value of pointer.
 * @types: List arguments.
 * @buffer: Array to handle print
 * @flags: Calculate active flags.
 * @width: Get width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Chars printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char ext_c = 0, pad = ' ';
	int id = BUFF_SIZE - 2, len = 2, pad_srt = 1;
	unsigned long nm_adrs;
	char map_to[] = "0123456789abcdef";
	void *adrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (adrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	nm_adrs = (unsigned long)adrs;

	while (nm_adrs > 0)
	{
		buffer[id--] = map_to[nm_adrs % 16];
		nm_adrs /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (flags & F_PLUS)
		ext_c = '+', len++;
	else if (flags & F_SPACE)
		ext_c = ' ', len++;

	id++;

	return (write_pointer(buffer, id, len,
		width, flags, pad, ext_c, pad_srt));
}

/*** PRINT_NON-PRINTABLE ***/
/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars.
 * @types: List arguments.
 * @buffer: Aray to handle print.
 * @flags: Calculates active flags.
 * @width: Get width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Chars printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, ofset = 0;
	char *aaa = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (aaa == NULL)
		return (write(1, "(null)", 6));

	while (aaa[i] != '\0')
	{
		if (is_printable(aaa[i]))
			buffer[i + ofset] = aaa[i];
		else
			ofset += append_hexa_code(aaa[i], buffer, i + ofset);

		i++;
	}

	buffer[i + ofset] = '\0';

	return (write(1, buffer, i + ofset));
}

/************************* PRINT REVERSE *************************/
/**
 * print_reverse - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *aaa;
	int i, cnt = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	aaa = va_arg(types, char *);

	if (aaa == NULL)
	{
		UNUSED(precision);

		aaa = ")Null(";
	}
	for (i = 0; aaa[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = aaa[i];

		write(1, &z, 1);
		cnt++;
	}
	return (cnt);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *aaa;
	unsigned int i, j;
	int cnt = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	aaa = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (aaa == NULL)
		aaa = "(AHYY)";
	for (i = 0; aaa[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == aaa[i])
			{
				x = out[j];
				write(1, &x, 1);
				cnt++;
				break;
			}
		}
		if (!in[j])
		{
			x = aaa[i];
			write(1, &x, 1);
			cnt++;
		}
	}
	return (cnt);
}
