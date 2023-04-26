#include "shell.h"

/**
 * bfree - frees a pointer and makes the address NULL
 * @ptr: address of the pointer to be freed
 * Return: displays 1 when it is freed and 0 if it isn't
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
