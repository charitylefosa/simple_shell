#include <string.h>
#include "shell.h"

void handle_segmfault(int signo __attribute__((unused)));

int ex_code = 0; /* initializes exit code value with 0*/

/**
*main - entry point of the program
*@ac: number of command line arguments
*@av: array of command line arguments
*Return: 0 on sucess
*/
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *argv[MAX_ARGS], *ar[MAX_ARGS];

	char *__attribute__ ((unused)) cmd1, *cmd_copy = NULL;

	int __attribute__((unused)) num_arg, r, count = 0;
	signal(SIGSEGV, handle_segmfault);
	do {
		count++;
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		cmd = read_command();
		if (cmd == NULL)
			exit(ex_code);
		if (cmd[0] == '\0' || (_strcmp(cmd, "\n") == 0))
			continue;
		rewmspaces(cmd);
		cmd_copy = strdup(cmd);
		tokenize(cmd_copy, ar);
		tokenize(cmd, argv);
		if (cmd[0] == '\0' || (_strcmp(cmd, "\n") == 0))
		{
			free(cmd);
			free(cmd_copy);
			continue;
		}
		if (_strcmp(argv[0], "exit") == 0)
		{
			r = code_exit(ar[1], count, av[0], argv);
			free(cmd);
			free(cmd_copy);
			if (r == 500)
				continue;
			exit(r);
		}
		if (process_cmd(argv) == 0)
		{
		}
		else
			_exec(argv, av[0], count);
		free(cmd);
		free(cmd_copy);
	} while (1);
	return (0);
}


/**
*wspace- checks character space or tab
*@s: character to be checked
*
*Return: 1 on sucess
*	0 if not sucessful
*/
int wspace(char s)
{
	if (s == ' ' || s == '\t')
		return (1);
	return (0);
}

/**
*rewmspaces - remove white spaces
*@s: string to be checked
*/
void rewmspaces(char *s)
{
	int length = _strlen(s);
	int i = 0, j = length - 1, k;
	int l, count, m;

	if (s == NULL)
		return;

	while (i < length && wspace(s[i]))
	{
		i++;
	}
	while (j >= i && wspace(s[j]))
	{
		j--;
	}
	k = 0;
	while (i <= j)
	{
		s[k++] = s[i++];
	}
	s[k] = '\0';
	l = 0;
	count = 0;
	for (m = 0; m <= j; m++)
	{
		if (s[m] != ' ')
		{
			s[l++] = s[m];
			count = 0;
		}
		else if (count == 0)
		{
			s[l++] = s[m];
			count++;
		}
	}
	s[l] = '\0';
}


/**
*read_command- reads the command user has input
*
*Return: pointer to the command string input
*/
char *read_command(void)
{
	char *cmd1 = _getline();

	signal(SIGINT, handle_sigint);
	return (cmd1);
}


/**
*handle_sigint- signal handler for SIGINT (Ctrl+C)
*@signo: signal number
*/
void handle_sigint(int signo __attribute__((unused)))
{
	write(1, "\n", 1);
	if (cmd != NULL)
	{
		free(cmd);
		cmd = NULL;
	}
	exit(0);
}
