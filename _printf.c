#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * printIdentifiers - prints special characters
 * @next: character after the %
 * @arg: argument for the indentifier
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int printIdentifiers(char next, va_list arg)
{
	int functsIndex;

	identifierStruct functs[] = {
		{"c", print_character},
		{"s", print_string},
		{"d", print_int},
		{"i", print_int},
		{"u", print_unsigned},
		{"b", print_unsignedToBinary},
		{"o", print_oct},
		{"x", print_hex},
		{"X", print_HEX},
		{"S", print_STR},
		{NULL, NULL}
	};

	for (functsIndex = 0; functs[functsIndex].indentifier != NULL; functsIndex++)
	{
		if (functs[functsIndex].indentifier[0] == next)
			return (functs[functsIndex].printer(arg));
	}
	return (0);
}

/*
 *_printf - printf
 *@format: const char pointer
 *Description: this functions implement some functions of printf
 *Return: num of characteres printed
 */
int _printf(const char *format, ...)
{
  const char *string;
  int cont = 0;
  va_list arg;

  if (!format)
    return (-1);

  va_start(arg, format);
  string = format;

  cont = loop_format(arg, string);

  va_end(arg);
  return (cont);
}
/*
 *loop_format - loop format
 *@arg: va_list arg
 *@string: pointer from format
 *Description: This function make loop tp string pointer
 *Return: num of characteres printed
 */
int loop_format(va_list arg, const char *string)
{
  int i = 0, flag = 0, cont_fm = 0, cont = 0, check_per = 0;

  while (i < _strlen((char *)string) && *string != '\0')
  {
    char aux = string[i];

    if (aux == '%')
    {
      i++, flag++;
      aux = string[i];
      if (aux == '\0' && _strlen((char *)string) == 1)
        return (-1);
      if (aux == '\0')
        return (cont);
      if (aux == '%')
      {
        flag++;
      } else
      {
        cont_fm = function_manager(aux, arg);
        if (cont_fm >= 0 && cont_fm != -1)
        {
          i++;
          aux = string[i];
          if (aux == '%')
            flag--;
          cont = cont + cont_fm;
        } else if (cont_fm == -1 && aux != '\n')
        {
          cont += _putchar('%');
        }
      }
    }
    check_per = check_percent(&flag, aux);
    cont += check_per;
    if (check_per == 0 && aux != '\0' && aux != '%')
      cont += _putchar(aux), i++;
    check_per = 0;
  }
  return (cont);
}
/*
 * check_percent - call function manager
 *@flag: value by reference
 *@aux: character
 *Description: This function print % pear
 *Return: 1 if % is printed
 */
int check_percent(int *flag, char cent)
{
  int tmp_flag;
  int cont = 0;

  tmp_flag = *flag;
  if (tmp_flag == 2 && cent == '%')
  {
    _putchar('%');
    tmp_flag = 0;
    cont = 1;
  }
  return (cont);
}

/*
 * call_function_manager - call function manager
 *@aux: character parameter
 *@arg: va_list arg
 *Description: This function call function manager
 *Return: num of characteres printed
 */

int call_function_manager(char dom, va_list arg)
{
  int cont = 0;

  cont = function_manager(dom, arg);
  return (cont);
}
