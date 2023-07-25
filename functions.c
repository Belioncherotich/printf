#include "main.h"

/* PRINT CHAR*/

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char b = va_arg(types, int);

	return (handle_write_char(b, buffer, flags, width, precision, size));
}
/* CODE PRINTS A STRING*/
/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, c;
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
			for (i = width - len; c > 0; c--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (c = width - len; c > 0; c--)
				write(1, " ", 1);
			write(1, &aaa[0], len);
			return (width);
		}
	}

	return (write(1, aaa, len));
}
/*PRINTS  PERCENT SIGN */
/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
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

/* CODE WILLPRINT INT */
/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int c = BUFF_SIZE - 2;
	int is_neg = 0;
	long int n = va_arg(types, long int);
	unsigned long int nm;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[c--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	nm = (unsigned long int)n;

	if (n < 0)
	{
		nm = (unsigned long int)((-1) * n);
		is_neg = 1;
	}

	while (nm > 0)
	{
		buffer[i--] = (nm % 10) + '0';
		nm /= 10;
	}

	c++;

	return (write_number(is_neg, c, buffer, flags, width, precision, size));
}

/* WILL PRINT BINARY */
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 *
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int m, n, c, sm;
	unsigned int a[32];
	int cnt;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	m = va_arg(types, unsigned int);
	n = 2147483648; /* (2 ^ 31) */
	a[0] = m / n;
	for (c = 1; c < 32; c++)
	{
		n /= 2;
		a[c] = (m / n) % 2;
	}
	for (c = 0, sm = 0, cnt = 0; c < 32; c++)
	{
		sm += a[c];
		if (sm || c == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			cnt++;
		}
	}
	return (cnt);
}
