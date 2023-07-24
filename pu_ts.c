#include "main.h"
/**
* pu_ts - prints a string
* @s: string to evaluate
* Return:returns length of string
*/
int pu_ts(const char *s)
{
int i = 0;
	while (s[i] != '\0')
	{
	write_char(s[i]);
		i++;
	}
	return (i);
}
