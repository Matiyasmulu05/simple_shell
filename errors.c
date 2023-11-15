#include "shell.h"

/**
 *_eputs - prints the input
 * @str: string that is printed
 *
 * Return: not
 */
void _eputs(char *str)
{
	int z = 0;

	if (!str)
		return;
	while (str[z] != '\0')
	{
		_eputchar(str[z]);
		z++;
	}
}

/**
 * _eputchar - writes characte
 * @c: character that is printed
 *
 * Return: Success 1
 * On error, -1 is returned, and errno is set appropriately
 */
int _eputchar(char c)
{
	static int z;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || z >= WRITE_BUF_SIZE)
	{
		write(2, buf, z);
		z = 0;
	}
	if (c != BUF_FLUSH)
		buf[z++] = c;
	return (1);
}

/**
 * _putfd - character that is written
 * @c: The character
 * @fd: filedescriptor
 *
 * Return: success on 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int z;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || z >= WRITE_BUF_SIZE)
	{
		write(fd, buf, z);
		z = 0;
	}
	if (c != BUF_FLUSH)
		buf[z++] = c;
	return (1);
}

/**
 *_putsfd - prints
 * @str: the string that is printed
 * @fd: the written filedescriptor
 *
 * Return: the number of charsput
 */
int _putsfd(char *str, int fd)
{
	int z = 0;

	if (!str)
		return (0);
	while (*str)
	{
		z += _putfd(*str++, fd);
	}
	return (z);
}
