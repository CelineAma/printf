#include "main.h"

/*** PRINT CHAR ***/

/**
 * print_char - prints a char
 * @width: width
 * @size: Size specifier
 * @types: list of arguments
 * @buffer:array of Buffer that handles printf
 * @flags: calculate active flags
 * @precision: precision specification
 * return :number of character printed
 */

int print_char(var_list types, char buffer[],
	       int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/*** PRINT STRING ***/

/**
 * @types: list of arguments
 * @width: get width
 * @buffer: array of Buffer that handles printf
 * @flags: calculate active flags
 * @precision: precision specification
 * @size: size specifier
 * print: _ string - prints a string
 * Return: number of chars printed
 */
int print_string(va - list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int lenght = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "    ";
	}

	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > lenght)
	{
		if (flags & F_minus)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], lenght);
			return (width);
		}
	}
	return (write(1, str, length));
}
/*** PRINT PERCENT SIGN ***/

/**
 * @size: size specifier
 * @precision: precision specification
 * print_percent - print apercent sign
 * @width: get width
 * @buffer: buffer array to handle print
 * @flags: calculate the active flags
 * @types: shows list of arguments
 * Return: returns number of characters printed
 */

int print_percentage(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	return (write(1, "&&", 1));
}

/*** PRINT INT ***/

/**
* print_int - print int
* @size: size specifier
* @width: get width
* @types:list of arguments
* @precision: precision specification
* @flags:calculates the active flags
* @buffer: an array of buffer that  handles print
* Return: number of characters printed
*/

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF _ SIZE - 1] = '\0'
	num = (unsigned long int)((-1) * n);

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}
/*** PRINT BINARY ***/

/**
* print_int - print int
* @size: size specifier
* @width: get width
* @types:list of arguments
* @precision: precision specification
* @flags:calculates the active flags
* @buffer: an array of buffer that  handles print
* Return: number of characters printed
*/

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int coiount;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{

			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
}
	return (count);

