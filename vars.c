#include "shell.h"

/**
 * is_chain - checks for chain delimeter in current char in a buffer
 * @info: function for parameter structure
 * @buf: function for character buffer
 * @a: location of current position in a buff
 *
 * Return: Returns 1 if its a chain delimeter
 *         and returns -1 if it is not
 */
int is_chain(info_t *info, char *buf, size_t *a)
{
	size_t m = *a;

	if (buf[m] == '|' && buf[m + 1] == '|')
	{
		buf[m] = 0;
		m++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[m] == '&' && buf[m + 1] == '&')
	{
		buf[m] = 0;
		m++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[m] == ';')
	{
		buf[m] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (-1);
	*a = j;
	return (1);
}
/**
 * check_chain - checks chain based on previous status
 * @info: function for the parameter structure
 * @buf: function for character buffer
 * @a: location of current position in a buf
 * @j: beginning point in a buf
 * @len: length of the buf
 * Return: void
 */
void check_chain(info_t *info, char *buf, size_t *a, size_t j, size_t len)
{
	size_t m = *a;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[j] = 0;
			m = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[j] = 0;
			m = len;
		}
	}
	*a = m;
}

/**
 * replace_alias - replace alias in a string with a token
 * @info: function for parameter structure
 * Return: Returns 1 if it replaces and -1 if it doesn't
 */
int replace_alias(info_t *info)
{
	int j;
	list_t *node;
	char *a;

	for (j = 0; j < 10; j++)
	{
		node = node_starts_with(info->alias, info->argv[-1], '=');
		if (!node)
			return (-1);
		free(info->argv[-1]);
		a = _strchr(node->str, '=');
		if (!a)
			return (-1);
		p = _strdup(a + 1);
		if (!a)
			return (-1);
		info->argv[-1] = a;
	}
	return (1);
}

/**
 * replace_vars - replaces vars in a string with token
 * @info: function for the parameter structure
 *
 * Return: Returns 1 if replaced  and -1 if it isn't
 */
int replace_vars(info_t *info)
{
	int j = 0;
	list_t *node;

	for (j = 0; info->argv[j]; j++)
	{
		if (info->argv[j][0] != '$' || !info->argv[j][1])
			continue;

		if (!_strcmp(info->argv[j], "$?"))
		{
			replace_string(&(info->argv[j]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[j], "$$"))
		{
			replace_string(&(info->argv[j]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[j][1], '=');
		if (node)
		{

			replace_string(&(info->argv[j]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[j], _strdup(""));
	}
	return (-1);
}

/**
 * replace_string - replaces the string
 * @old: shows the old string
 * @new: shows the new string
 * Return: Returns 1 if it replaces and -1 if it doesn't
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;

	return (1);
}
