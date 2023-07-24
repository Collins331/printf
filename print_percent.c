#include "main.h"

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
