#include "main.h"

/*** PRINT_CHAR ***/
/**
 * print_char - Prints char.
 * @types: List of arguments.
 * @buffer: Array to handle print.
 * @flags: Calculate active flags.
 * @width: Get Width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Chars printed.
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char e = va_arg(types, int);

	return (handle_write_char(e, buffer, flags, width, precision, size));
}
/*** PRINT_STRING ***/
/**
 * print_string - Prints string.
 * @types: List arguments.
 * @buffer: Array to handle print.
 * @flags: Calculate active flags.
 * @width: Get width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Chars printed.
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, a;
	char *aaa = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (aaa == NULL)
	{
		aaa = "(null)";
		if (precision >= 6)
			aaa = "      ";
	}

	while (aaa[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &aaa[0], len);
			for (a = width - len; a > 0; a--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = width - len; a > 0; a--)
				write(1, " ", 1);
			write(1, &aaa[0], length);
			return (width);
		}
	}

	return (write(1, aaa, len));
}
/*** PRINT_PERCENT_SIGN ***/
/**
 * print_percent - Prints percent sign.
 * @types: List arguments
 * @buffer: Array to handle print.
 * @flags: Calculate active flags.
 * @width: Get width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Chars printed.
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/*** PRINT_INT ***/
/**
 * print_int - Print int.
 * @types: List arguments
 * @buffer: Array to handle print.
 * @flags: Calculate active flags.
 * @width: Get width.
 * @precision: Precision speciier.
 * @size: Size specifier.....
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	int is_neg = 0;
	long int b = va_arg(types, long int);
	unsigned long int num;

	b = convert_size_number(b, size);

	if (b == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)b;

	if (b < 0)
	{
		num = (unsigned long int)((-1) * b);
		is_neg = 1;
	}

	while (num > 0)
	{
		buffer[a--] = (num % 10) + '0';
		num /= 10;
	}

	a++;

	return (write_number(is_neg, a, buffer, flags, width, precision, size));
}

/*** PRINT_BINARY ***/
/**
 * print_binary - Prints unsigned number.
 * @types: List arguments.
 * @buffer: Array to handle print.
 * @flags: Calculate active flags.
 * @width: Get width.
 * @precision: Precision specificier.
 * @size: Size specifier.
 * Return: Char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int b, d, a, sum;
	unsigned int i[32];
	int cnt;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	b = va_arg(types, unsigned int);
	d = 2147483648; /* (2 ^ 31) */
	i[0] = b / d;
	for (a = 1; a < 32; a++)
	{
		d /= 2;
		i[a] = (b / d) % 2;
	}
	for (a = 0, sum = 0, cnt = 0; a < 32; a++)
	{
		sum += i[a];
		if (sum || a == 31)
		{
			char y = '0' + i[a];

			write(1, &y, 1);
			cnt++;
		}
	}
	return (cnt);
}
