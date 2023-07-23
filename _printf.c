#include "main.h"
/**
  *_printf - prints the arguments passed through to it
  *@format: the character string
  *Return: always integer
  */
int _printf(const char *format, ...)
{
	va_list all;
	int count, cl;

	va_start(all, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				cl = va_arg(all, int);
				write_char(cl);
				count++;
			}
			else if (*format == '%')
			{
				write_char('%');
				count++;
			}
			else if (*format == 's')
			{
				char *string = va_arg(all, char*);

				while (*string)
				{
					write_char(*string);
					string++;
					count++;
				}
			}
		}
		write_char(*format);
		count++;
	format++;
	}
	va_end(all);
	return (count);
}
