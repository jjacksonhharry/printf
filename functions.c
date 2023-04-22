#include "main.h"
		/* -print char- */
/**
 * print_char - function that prints a character
 * @size: size of specifier
 * @precision: precisoin specifications
 * @width: width
 * @flags: calculates active flags
 * @buffer: buffer to handle print
 * @types: list of arg
 * Return: number of chars printed
 */
int print_char(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
		/* -print a string- */
/**
 * print_string - function that prints a string
 * @size: size of specifier
 * @precision: precisoin specifications
 * @width: width
 * @flags: calculates active flags
 * @buffer: buffer to handle print
 * @types: list of arg
 * Return: number of chars printed
 */
int print_string(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int i, length = 0;
	chr *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));

}
		/* -print percent sign- */
/**
 * print_percent - functio that print percent sign
 * @types: arguments list
 * @buffer: array of buffer
 * @flags: calculate active flags
 * @width: gets width
 * @precision: specification of precision
 * @size: specifier size
 * Return: number of characters
 */
int print_percent(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
		/* -print integer- */
/**
 * print_int - function that prints integer
 * @types: arguments list
 * @buffer: array of buffer
 * @flags: calculate active flags
 * @width: gets width
 * @precision: specification of precision
 * @size: specifier size
 * Return: number of characters
 */
int print_int(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int is_neagative = 0;
	int i = BUFF_SIZE - 2;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

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
		/* -print binary */
/**
 * print_binary - function that prints binary
 * @types: arguments list
 * @buffer: array of buffer
 * @flags: calculate active flags
 * @width: gets width
 * @precision: specification of precision
 * @size: specifier of size
 * Return: number of characters
 */
int print_binary(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	int count;
	unsigned int a[32];

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
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
