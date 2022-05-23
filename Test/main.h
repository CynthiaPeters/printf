#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
int print_sign(va_list arg, int base);
int print_unsigned(va_list arg, int base);
char *convert_to(char representation[], unsigned int num, int base);
int _printf(const char *format, ...);
int _switch(char c, va_list arg);
int print_char(va_list arg);
int print_str(va_list arg);
int print_percent(int *flag, char cent);
void print_binary(unsigned int n, unsigned int* printed);
int print_unsignedToBinary(va_list arg);
int print_ptr(va_list arg);
int print_unsignedIntToHex(unsigned int num, char _case);
int print_hex_base(va_list arg, char _case);
int call_funct_manager(char dom, va_list arg);
int print_base16_upper_lower(va_list arg, char *representation);
int loop_format(va_list arg, const char *string);
int print_rev(va_list arg);
int print_rot13(va_list arg);
int print_STR (va_list arg);

#endif
