#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

char *print_s(va_list list);

char *print_c(va_list list);

char *print_d(va_list list);

char *itob(va_list list);

char *rot13(va_list list);

char *rev_string(va_list list);

char *itoOctal(va_list list);




char* (*get_func(char i))(va_list);

char *create_buffer(void);

void write_buffer(char *buffer, int len, va_list list);

char *_strcpy(char *dest, char *src);

int _strlen(char *s);



/**
 * struct types - Program for struct
 * created by Celine and 
 * @id: identifier for the type to print - d is integer
 * @func: ptr to functions that print according to identifier -  print_c
 */

typedef struct types
{
	char id;
	char* (*func)(va_list);
}
print;

#endif
