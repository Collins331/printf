#ifndef MAIN_H
#define MAIN_H

/*standard libraries*/
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024


#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/*short and long definition*/
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmtt - Struct definition
 * @fmtt: The format of the specified type
 * @fn: The pointer to the specified format.
 */
struct fmtt
{
	char fmtt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct definition
 * @fmtt: The format.
 * @fm_t: alias for struct fmtt.
 */
typedef struct fmtt ft_t;

int _printf(const char *format, ...);
int handle_print(const char *fmtt, int *i, va_list list,
		char buffer[], int flags, int width, int precision, int size);

/******************fxn prototypes************************/
int print_c(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int print_s(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int print_percentage(va_list types, char buffer[], int flags,
		int width, int precision, int size);

int print_i(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int print_b(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int print_ui(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags,
		int width, int precision, int size);

int print_hexa(va_list types, char map_to[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size);

int print_non_printable(va_list types, char buffer[], int flags,
		int width, int precision, int size);

int print_pointer(va_list types, char buffer[], int flags,
		int width, int precision, int size);

int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

int print_reverse(va_list types, char buffer[], int flags,
		int width, int precision, int size);

int print_rot13string(va_list types, char buffer[], int flags,
		int width, int precision, int size);

int print_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int print_num(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length, int width, int flags,
		char padd, char extra_c, int padd_start);

int write_uint(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
