#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include<string.h>

int print_int(int val);
void printer(char screen[], int *index);
int _printf(const char *format, ...);
int write_char(char s);
int pu_ts(const char *s);

#endif
