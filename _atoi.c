#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 else
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is  delimeter
 * @v: char to check
 * @delim:  delimeter string
 * Return: 1 if positive, 0 if negative
 */
int is_delim(char v, char *delim)
{
	while (*delim)
		if (*delim++ == v)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @v:  character to input
 * Return: 1 if v is alphabetic, 0 else
 */

int _isalpha(int v)
{
	if ((v >= 'a' && v <= 'z') || (v >= 'A' && v <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @c: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *c)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; c[i] != '\0' && flag != 2; i++)
	{
		if (c[i] == '-')
			sign *= -1;

		if (c[i] >= '0' && c[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (c[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
