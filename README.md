The project consists of normal functions, derived functions, main files, man page  and a README.md file.
Which produces output based on  a format specifiers listed below.

    len = _printf("Let's try to printf a simple sentence.\n");

    len2 = printf("Let's try to printf a simple sentence.\n");
  
    ui = (unsigned int)INT_MAX + 1024;

    addr = (void *)0x7ffe637541f0;

    _printf("Length:[%d, %i]\n", len, len);

    printf("Length:[%d, %i]\n", len2, len2);

    _printf("Negative:[%d]\n", -762534);

    printf("Negative:[%d]\n", -762534);

    _printf("Unsigned:[%u]\n", ui);

    printf("Unsigned:[%u]\n", ui);

    _printf("Unsigned octal:[%o]\n", ui);

    printf("Unsigned octal:[%o]\n", ui);

    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);

    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);

    _printf("Character:[%c]\n", 'H');

    printf("Character:[%c]\n", 'H');

    _printf("String:[%s]\n", "I am a string !");

    printf("String:[%s]\n", "I am a string !");

    _printf("Address:[%p]\n", addr);

    printf("Address:[%p]\n", addr);

    len = _printf("Percent:[%%]\n");

    len2 = printf("Percent:[%%]\n");

    _printf("Len:[%d]\n", len);

    printf("Len:[%d]\n", len2);

    _printf("Unknown:[%r]\n");

    printf("Unknown:[%r]\n");

    Author:
	IBEZIM ONYINYECHI C.