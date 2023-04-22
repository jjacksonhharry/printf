# include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - function that produces output according to a format
 * @format: list of types of arguments
 * Return: printed_chars
 */
int _printf(const char *format, ...)
{
	int i, printed_chars = 0, printed = 0;
	int width, size, flags, precision, buff_ind = 0;
	va_list printf;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(printf, format);

	for (i = 0; format && format[i] != '\0'; i++)
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, printf);
			precision = get_precision(format, &i, printf);
			size = get_size(format, &i);
			i++;
			printed = handle_print(format, &i, printf, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	print_buffer(buffer, &buff_ind);
	va_end(printf);
	return (printed_chars);
}
/**
 * print_buffer - print buffer contents
 * @buffer: array of characters
 * @buff_ind: index
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
