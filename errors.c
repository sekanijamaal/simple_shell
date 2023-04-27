#include "shell.h"

/**
 * _eputs - prints input string
 * @str: string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int r = 0;

	if (!str)
		return;
	while (str[r] != '\0')
	{
		_eputchar(str[r]);
		r++;
	}
}

/**
 * _eputchar - writes character s to stderr
 * @s: character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char s)
{
	static int r;
	static char buf[WRITE_BUF_SIZE];

	if (s == BUF_FLUSH || r >= WRITE_BUF_SIZE)
	{
		write(2, buf, r);
		r = 0;
	}
	if (s != BUF_FLUSH)
		buf[r++] = s;
	return (1);
}

/**
 * _putfd - writes  character s to given fd
 * @s: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char s, int fd)
{
	static int r;
	static char buf[WRITE_BUF_SIZE];

	if (s == BUF_FLUSH || r >= WRITE_BUF_SIZE)
	{
		write(fd, buf, r);
		r = 0;
	}
	if (s != BUF_FLUSH)
		buf[r++] = s;
	return (1);
}

/**
 * _putsfd - prints input string
 * @str: string to be printed
 * @fd: filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int r = 0;

	if (!str)
		return (0);
	while (*str)
	{
		r += _putfd(*str++, fd);
	}
	return (r);
}
