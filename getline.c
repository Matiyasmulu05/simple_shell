#include "shell.h"

/**
 * input_buf - commands
 * @info: parameter
 * @buf: address of the buffer
 * @len: address
 *
 * Return: byte
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
        ssize_t s = 0;
        size_t len_p = 0;

        if (!*len) /* if nothing left in the buffer, fill it */
        {
                /*bfree((void **)info->cmd_buf);*/
                free(*buf);
                *buf = NULL;
                signal(SIGINT, sigintHandler);
#if USE_GETLINE
                s = getline(buf, &len_p, stdin);
#else
                s = _getline(info, buf, &len_p);
#endif
                if (s > 0)
                {
                        if ((*buf)[s - 1] == '\n')
                        {
                                (*buf)[s - 1] = '\0'; /* remove trailing newline */
                                s--;
                        }
                        info->linecount_flag = 1;
                        remove_comments(*buf);
                        build_history_list(info, *buf, info->histcount++);
                        /* if (_strchr(*buf, ';')) is this a command chain? */
                        {
                                *len = s;
                                info->cmd_buf = buf;
                        }
                }
        }
        return (s);
}

/**
 * get_input - newline
 * @info: struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
        static char *buf; /* the ';' command chain buffer */
        static size_t w, e, len;
        ssize_t s = 0;
        char **buf_p = &(info->arg), *k;

        _putchar(BUF_FLUSH);
        s = input_buf(info, &buf, &len);
        if (s == -1) /* EOF */
                return (-1);
        if (len)        /* we have commands left in the chain buffer */
        {
                e = w; /* init new iterator to current buf position */
                k = buf + w; /* get pointer for return */

                check_chain(info, buf, &e, w, len);
                while (e < len) /* iterate to semicolon or end */
                {
                        if (is_chain(info, buf, &e))
                                break;
                        e++;
                }

                w = e + 1; /* increment past nulled ';'' */
                if (w >= len) /* reached end of buffer? */
                {
                        w = len = 0; /* reset position and length */
                        info->cmd_buf_type = CMD_NORM;
                }

                *buf_p = k; /* pass back pointer to current command position */
                return (_strlen(k)); /* return length of current command */
        }

        *buf_p = buf; /* else not a chain, pass back buffer from _getline() */
        return (s); /* return length of buffer from _getline() */
}

/**
 * read_buf - bufer
 * @info: struct
 * @buf: buffer
 * @i: size
 *
 * Return: s
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
<<<<<<< HEAD
	ssize_t s = 0;

	if (*i)
		return (0);
	s = read(info->readfd, buf, READ_BUF_SIZE);
	if (s >= 0)
		*i = s;
	return (s);
=======
        ssize_t s = 0;

        if (*i)
                return (0);
        s = read(info->readfd, buf, READ_BUF_SIZE);
        if (s >= 0)
                *i = s;
        return (s);
>>>>>>> main
}

/**
 * _getline - input
 * @info: struct
 * @ptr: address of a pointer
 * @length: size
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
        static char buf[READ_BUF_SIZE];
        static size_t w, len;
        size_t l;
        ssize_t r = 0, a = 0;
        char *p = NULL, *new_p = NULL, *d;

        p = *ptr;
        if (p && length)
                a = *length;
        if (w == len)
                w = len = 0;

        r = read_buf(info, buf, &len);
        if (r == -1 || (r == 0 && len == 0))
                return (-1);

        d = _strchr(buf + w, '\n');
        l = d ? 1 + (unsigned int)(d - buf) : len;
        new_p = _realloc(p, a, a ? a + l : l + 1);
        if (!new_p) /* MALLOC FAILURE! */
                return (p ? free(p), -1 : -1);

        if (a)
                _strncat(new_p, buf + w, l - w);
        else
                _strncpy(new_p, buf + w, l - w + 1);

        a += l - w;
        w = l;
        p = new_p;

        if (length)
                *length = a;
        *ptr = p;
        return (a);
}

/**
 * sigintHandler - blocks
 * @sig_num: number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
        _puts("\n");
        _puts("$ ");
        _putchar(BUF_FLUSH);
}

