#include "main.h"


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

