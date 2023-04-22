#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

/* Function prototypes */
int _printf(const char *format, ...);

		/* functions.c */
int print_char(va_list types, char buffer[], int flags, 
		int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int print_int(va_list types, char buffer[], int flags,
		int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags,
		int width, int precision, int size);
		/* functions1.c */

#endif /* MAIN_H */
