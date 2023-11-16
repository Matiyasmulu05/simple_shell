#include "shell.h"

/**
 * _erratoi - converter
 * @s: the string that is converted
 * Return: 0 if no numbers in string
 */
int _erratoi(char *s)
{
        int z = 0;
        unsigned long int result = 0;

        if (*s == '+')
                s++;  /* TODO: why does this make main return 255? */
        for (z = 0;  s[z] != '\0'; z++)
        {
                if (s[z] >= '0' && s[z] <= '9')
                {
                        result *= 10;
                        result += (s[z] - '0');
                        if (result > INT_MAX)
                                return (-1);
                }
                else
                        return (-1);
        }
        return (result);
}

/**
 * print_error - print
 * @info: return info
 * @estr: string
 * Return: 0 if no numbers in string
 */
void print_error(info_t *info, char *estr)
{
        _eputs(info->fname);
        _eputs(": ");
        print_d(info->line_count, STDERR_FILENO);
        _eputs(": ");
        _eputs(info->argv[0]);
        _eputs(": ");
        _eputs(estr);
}

/**
 * print_d - function
 * @input: the input
 * @fd: the filedescriptor
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
        int (*__putchar)(char) = _putchar;
        int z, count = 0;
        unsigned int _abs_, current;

<<<<<<< HEAD
	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (z = 1000000000; z > 1; z /= 10)
	{
		if (_abs_ / z)
		{
			__putchar('0' + current / z);
			count++;
		}
		current %= z;
	}
	__putchar('0' + current);
	count++;
=======
        if (fd == STDERR_FILENO)
                __putchar = _eputchar;
        if (input < 0)
        {
                _abs_ = -input;
                __putchar('-');
                count++;
        }
        else
                _abs_ = input;
        current = _abs_;
        for (z = 1000000000; z > 1; z /= 10)
        {
                if (_abs_ / z)
                {
                        __putchar('0' + current / z);
                        count++;
                }
                current %= z;
        }
        __putchar('0' + current);
        count++;
>>>>>>> main

        return (count);
}

/**
 * convert_number - converter
 * @num: number
 * @base: base
 * @flags: argumen
 * Return: string
 */

char *convert_number(long int num, int base, int flags)
{
        static char *arry;
        static char buffer[50];
        char sign = 0;
        char *ptr;
        unsigned long n = num;

        if (!(flags & CONVERT_UNSIGNED) && num < 0)
        {
                n = -num;
                sign = '-';

<<<<<<< HEAD
	}
	arry = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
=======
        }
        arry = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
        ptr = &buffer[49];
        *ptr = '\0';
>>>>>>> main

        do      {
                *--ptr = arry[n % base];
                n /= base;
        } while (n != 0);

        if (sign)
                *--ptr = sign;
        return (ptr);
}

/**
 * remove_comments - function
 * @buf: the string address
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
        int z;

        for (z = 0; buf[z] != '\0'; z++)
                if (buf[z] == '#' && (!z || buf[z - 1] == ' '))
                {
                        buf[z] = '\0';
                        break;
                }
}

