#include "main.h"
/
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
/
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
    char cent = string[i];

    if (cent == '%')
    {
      i++, flag++;
      cent = string[i];
      if (cent == '\0' && _strlen((char *)string) == 1)
        return (-1);
      if (cent == '\0')
        return (cont);
      if (cent == '%')
      {
        flag++;
      } else
      {
        cont_fm = function_manager(cent, arg);
        if (cont_fm >= 0 && cont_fm != -1)
        {
          i++;
          aux = string[i];
          if (cent == '%')
            flag--;
          cont = cont + cont_fm;
        } else if (cont_fm == -1 && cent != '\n')
        {
          cont += _putchar('%');
        }
      }
    }
    check_per = check_percent(&flag, cent);
    cont += check_per;
    if (check_per == 0 && cent != '\0' && cent != '%')
      cont += _putchar(cent), i++;
    check_per = 0;
  }
  return (cont);
}
/
 * check_percent - call function manager
 *@flag: value by reference
 *@cent: character
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

/
 * call_funct_manager - call function manager
 *@dom: character parameter
 *@arg: va_list arg
 *Description: This functio<F11>n call function manager
 *Return: num of characteres printed
 */

int call_funct_manager(char dom, va_list arg)
{
  int cont = 0;

  cont = function_manager(dom, arg);
  return (cont);
}
