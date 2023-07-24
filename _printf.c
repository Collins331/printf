#include "main.h"
/**
  *_printf - prints the arguments passed through to it
  *@format: the character string
  *Return: always integer
  */
int _printf(const char *format, ...)
{
	va_list all;
	int i = 0, count = 0;

	va_start(all, format);
	for (; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write_char(format[i]);
		}
		else if (format[i + 1] == 'c')
		{
			write_char(va_arg(all, int));
			i++;
		}
		else if (format[i + 1] == '%')
		{
			write_char('%');
			i++;
		}
		else if (format[i + 1] == 's')
		{
			char *s = va_arg(all, char*);

			count = pu_ts(s);
			i++;
			count += (count - 1);
		}
			count += 1;
	va_end(all);
	}
	return (count);
}

