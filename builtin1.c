#include "shell.h"

/**
 * _myhistory - displays history
 * @info: Structure
 *  Return: 0 always
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to the string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success
 */
int unset_alias(info_t *info, char *str)
{
	char *k, l;
	int ret;

	k = _strchr(str, '=');
	if (!k)
		return (1);
	l = *k;
	*k = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*k = l;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: parameter
 * @str: string
 *
 * Return: Always 0 on success
 */
int set_alias(info_t *info, char *str)
{
	char *k;

	k = _strchr(str, '=');
	if (!k)
		return (1);
	if (!*++k)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: 0 always
 */
int print_alias(list_t *node)
{
	char *k = NULL, *a = NULL;

	if (node)
	{
		k = _strchr(node->str, '=');
		for (a = node->str; a <= k; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(k + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - function
 * @info: Structure
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int e = 0;
	char *k = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (e = 1; info->argv[e]; e++)
	{
		k = _strchr(info->argv[e], '=');
		if (k)
			set_alias(info, info->argv[e]);
		else
			print_alias(node_starts_with(info->alias, info->argv[e], '='));
	}

	return (0);
}
