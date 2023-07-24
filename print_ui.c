#include"main.h"
/**
 * print_ui - Prints an unsigned number
 * @types: Arg list
 * @buffer: Array to handle printing
 * @flags: Active flags
 * @width: Width
 * @precision: Precision declaration
 * @size: Size
 * Return: Number of chars printed.(success)
 */
int print_ui(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_uint(0, i, buffer, flags, width, precision, size));
}
