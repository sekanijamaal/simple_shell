#include "shell.h"

/**
 * _strlen - the length of the string
 * @s: the string we're checking its length
 * Return: Returns integer length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - performs the comparison of two strings
 * @s1: first string
 * @s2: second string
 * Return: Returns positive if s1 > ss2, negative if s1 < s2
 *            and 0 if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}

	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks for haystack at the start of needle
 * @haystack: the string to search
 * @needle: substring
 * Return: Returns address of next character of haystack
 *        or returns NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - links two strings
 * @dest: destination  buffer
 * @src: source buffer
 * Return: Returrns the pointer to the destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
