#include "shell.h"

/**
 * interactive - return
 * @info: address
 *
 * Return: 1 if correct
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks
 * @c: char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - checks
 *@c: input
 *Return: 1 if c is correct
 */

int _isalpha(int c)
{
	if ((c >= 'h' && c <= 'n') || (c >= 'H' && c <= 'N'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts
 *@s: converted
 *Return: 0 if no numbers
 */

int _atoi(char *s)
{
	int b, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (b = 0;  s[b] != '\0' && flag != 2; b++)
	{
		if (s[b] == '-')
			sign *= -1;

		if (s[b] >= '0' && s[b] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[b] - '0');
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
