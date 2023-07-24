#include "main.h"
#include <stdarg.h>


/**
 * print_c - Prints a character
 * @types: List a of args
 * @buffer: Array to handle printing
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision declaration
 * @size: Size specifier
 * Return: char(success)
 */
int print_c(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (print_char(c, buffer, flags, width, precision, size));
}

/**
 * print_s - Prints a string
 * @types: List a of args
 * @buffer: Buffer array to handle printing
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision declaration
 * @size: Size specifier
 * Return: string(success)
 */
int print_s(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * print_percent - Prints a percentage sign
 * @types: List of args
 * @buffer: array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision declaration
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percentage(va_list types, char buffer[],
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

/************************* PRINT INT *************************/
/**
 * print_i - Print integer
 * @types: argList
 * @buffer: array to handle printing
 * @flags: active flags
 * @width: width.
 * @precision: Precision declaration
 * @size: Size specifier
 * Return: Number of chars printed(Success)
 */
int print_i(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (print_num(is_negative, i, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_b - Prints a number as binary.
 * @types: Arg list
 * @buffer: Array to handle print
 * @flags: Active flags
 * @width: Width.
 * @precision: Precision declaration
 * @size: Size
 * Return: Numbers of char printed.(success)
 */
int print_b(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
