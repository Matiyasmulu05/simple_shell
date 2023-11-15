#include "shell.h"

/**
 * _myexit - exit
 * @info: the structure
 *  Return: exit
 */
int _myexit(info_t *info)
{
	int check;

	if (info->argv[1])  /* exit arguement */
	{
		check = _erratoi(info->argv[1]);
		if (check == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the d
 * @info: the structure
 *  Return: 0 always
 */
int _mycd(info_t *info)
{
	char *m, *dir, buffer[1024];
	int chdir_ret;

	m = getcwd(buffer, 1024);
	if (!m)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(m);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the d
 * @info: Structure prototype
 *  Return: 0 always
 */
int _myhelp(info_t *info)
{
	char **_array;

	_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*_array); /* temp att_unused workaround */
	return (0);
}
