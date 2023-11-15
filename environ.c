#include "shell.h"

/**
 * _myenv - print
 * @info: Structure containing
 * Return: 0 always
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - value
 * @info: structure containing
 * @name: env
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *l;

	while (node)
	{
		l = starts_with(node->str, name);
		if (l && *l)
			return (l);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize
 * @info: potential arguments
 *  Return: 0 always
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("wrong number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove variable
 * @info: Structure prototype
 *  Return: 0 always
 */
int _myunsetenv(info_t *info)
{
	int x;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (x = 1; x <= info->argc; x++)
		_unsetenv(info, info->argv[x]);

	return (0);
}

/**
 * populate_env_list - populates
 * @info: Structure
 * Return: 0 always
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t x;

	for (x = 0; environ[x]; x++)
		add_node_end(&node, environ[x], 0);
	info->env = node;
	return (0);
}
