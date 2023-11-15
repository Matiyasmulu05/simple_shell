#include "shell.h"

/**
 **_strncpy - string
 *@dest: Destination
 *@src: source string
 *@n: the amount of characters
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int w, e;
	char *s = dest;

	w = 0;
	while (src[w] != '\0' && w < n - 1)
	{
		dest[w] = src[w];
		w++;
	}
	if (w < n)
	{
		e = w;
		while (e < n)
		{
			dest[e] = '\0';
			e++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenate
 *@dest: first string
 *@src: second string
 *@n: the amount of bytes
 *Return: THE Concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int w, e;
	char *s = dest;

	w = 0;
	e = 0;
	while (dest[w] != '\0')
		w++;
	while (src[e] != '\0' && e < n)
	{
		dest[w] = src[e];
		w++;
		e++;
	}
	if (e < n)
		dest[w] = '\0';
	return (s);
}

/**
 **_strchr - location of character
 *@s: string
 *@c: character
 *Return: the pointer
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
