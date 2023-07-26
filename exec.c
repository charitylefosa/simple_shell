#include "shell.h"

/**
 * _exec - Execute command
 *
 * @_argum: Array of aarguments
 * @av: The name of the program
 * @count: The count of command
 */
void _exec(char **_argum, char *av, int count)
{
	char *cmd1;
	/*char *envp[] = {"TERM=xterm-256color", NULL};*/
	char err[50];
	int status;

	_strcpy(err, av);
	ex_code = 0;
	if (_argum[0][0] == '/')
	{
		if (access_check(_argum, NULL, err, count, environ))
			return;
	}
	else
	{
		if (_argum[0][0] != '.')
		{
			cmd1 = which_func(_argum[0]);
			if (cmd1 == NULL)
			{

				_perror(err, count, _argum[0]);
				return;
			}
			if (access_check(_argum, cmd1, err, count, environ))
				return;
			free(cmd1);
		}
		else
		{
			cmd1 = _argum[0];
			if (access_check(_argum, cmd1, err, count, environ))
				return;
		}
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		ex_code = (WEXITSTATUS(status));
	}
}

/**
 * _execve - Runs error code aand exec
 * @c: Command prompt
 * @p: Arguments to command
 * @r: Environment variable
 */

void _execve(char *c, char **p, char **r)
{
	if ((execve(c, p, r) == -1))
		ex_code = 127;
	ex_code = 1;
}

/**
 * _perror - Printing error and checking exit code
 * @err: Error string
 * @count: Number of command
 * @c: The file name
 */

void _perror(char *err, int count, char *c)
{
	ex_code = 127;
	_print(err);
	_print(": ");
	_pnumber(count);
	_print(": ");
	_print(c);
	_print(": not found\n");
}

/**
 * _print - Prints a character
 * @s: String input
 */

void _print(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}

/**
 * _pnumber - Prints number
 * @n: Integer
 */

void _pnumber(int n)
{
	int first = n, count = 0, x = 1, i, tmp;

	tmp = n;

	if (n < 0)
	{
		_putchar('-');
		n = (n * -1) - 1;
	}
	while (first != 0)
	{
		first = first / 10;
		count++;
	}
	while (x <= count)
	{
		first = n;
		i = x;
		while (i < count)
		{
			first = first / 10;
			i++;
		}
		if (tmp < 0 && x == count)
			_putchar(((first % 10) + 48) + 1);
		else
			_putchar((first % 10) + 48);
		x++;
	}
	if (count == 0)
		_putchar('0');
}
