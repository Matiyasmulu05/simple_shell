#include "shell.h"

/**
 * get_environ - returns the string
 * @info: Structure
 * Return: 0 always
 */
char **get_environ(info_t *info)
{
        if (!info->environ || info->env_changed)
        {
                info->environ = list_to_strings(info->env);
                info->env_changed = 0;
        }

        return (info->environ);
}

/**
 * _unsetenv - remove
 * @info: Structure
 *  Return: 1 on delete, 0 otherwise
 * @var: string property
 */
int _unsetenv(info_t *info, char *var)
{
        list_t *node = info->env;
        size_t w = 0;
        char *k;

        if (!node || !var)
                return (0);

        while (node)
        {
                k = starts_with(node->str, var);
                if (k && *k == '=')
                {
                        info->env_changed = delete_node_at_index(&(info->env), w);
                        w = 0;
                        node = info->env;
                        continue;
                }
                node = node->next;
                w++;
        }
        return (info->env_changed);
}

/**
 * _setenv - func
 * @info: the structure
 * @var: string
 * @value: the string value
 *  Return: 0 always
 */
int _setenv(info_t *info, char *var, char *value)
{
        char *buf = NULL;
        list_t *node;
        char *k;

        if (!var || !value)
                return (0);

        buf = malloc(_strlen(var) + _strlen(value) + 2);
        if (!buf)
                return (1);
        _strcpy(buf, var);
        _strcat(buf, "=");
        _strcat(buf, value);
        node = info->env;
        while (node)
        {
                k = starts_with(node->str, var);
                if (k && *k == '=')
                {
                        free(node->str);
                        node->str = buf;
                        info->env_changed = 1;
                        return (0);
                }
                node = node->next;
        }
        add_node_end(&(info->env), buf, 0);
        free(buf);
        info->env_changed = 1;
        return (0);
}
