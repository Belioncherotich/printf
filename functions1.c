#include "main.h"

/*** PRINT_UNSIGNED_NUMBER ***/
/**
 * print_unsigned - Prints unsigned number.
 * @types: List arguments.
 * @buffer: Array to handle print.
 * @flags: Calculate active flags.
 * @width: Get width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 10) + '0';
		num /= 10;
	}

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/*** PRINT UNSIGNED NUMBER IN OCTAL ***/
/**
 * print_octal - Prints unsigned number in octal.
 * @types: List arguments.
 * @buffer: Array to handle print.
 * @flags: Calculate active flags.
 * @width: Get width
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Chars printed.
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[a--] = '0';

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/*** PRINT UNSIGNED NUMBER IN HEXADECIMAL ***/
/**
 * print_hexadecimal - Prints unsigned number in hexadecimal.
 * @types: List arguments.
 * @buffer: Array to handle print.
 * @flags: Calculate active flags.
 * @width: Get width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/*** PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL ***/
/**
 * print_hexa_upper - Prints unsigned number in upper hexadecimal.
 * @types: List arguments.
 * @buffer: Array to handle print.
 * @flags: Calculate active flags.
 * @width: Get width.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Chars printed.
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/*** PRINT_HEXX NUM IN LOWER OR UPPER ***/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: List arguments.
 * @map_to: Array of values to map number to.
 * @buffer: Array to handle print.
 * @flags: Calculates active flags.
 * @flag_ch: Calculate active flags.
 * @width: Get width
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Chars printed.
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[a--] = flag_ch;
		buffer[a--] = '0';
	}

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}
