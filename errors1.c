#include "shell.h"

/**
 * _erratoi - converts string to  integer
 * @c:  string to be converted
 * Return: 0 if no numbers in string, converted number else
 *       -1 on error
 */
int _erratoi(char *c)
{
	int r = 0;
	unsigned long int result = 0;

	if (*c == '+')
		c++;  /* TODO: why does this make main return 255? */
	for (r = 0;  c[r] != '\0'; r++)
	{
		if (c[r] >= '0' && c[r] <= '9')
		{
			result *= 10;
			result += (c[r] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prints error message
 * @info: parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number else
 *        -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function prints decimal (integer) number (base 10)
 * @input: input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int r, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (r = 1000000000; r > 1; r /= 10)
	{
		if (_abs_ / r)
		{
			__putchar('0' + current / r);
			count++;
		}
		current %= r;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long m = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		m = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[m % base];
		m /= base;
	} while (m != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int r;

	for (r = 0; buf[r] != '\0'; r++)
		if (buf[r] == '#' && (!r || buf[r - 1] == ' '))
		{
			buf[r] = '\0';
			break;
		}
}
