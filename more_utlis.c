#include "shell.h"

/**
*rem_spaces- remove trailing spaces from a string
*@str: string to remove from
*/
void rem_spaces(char *str)
{
	size_t len = _strlen(str);
	size_t start = 0;
	size_t i;

	if (len > 0)
	{
		while (len > 0 && str[len - 1] == ' ')
			len--;
		str[len] = '\0';
	}
	while (str[start] == ' ')
		start++;
	if (start > 0)
	{
		i = 0;
		while (str[start + i] != '\0')
		{
			str[i] = str[start + i];
			i++;
		}
		str[i] = '\0';
	}
}


/**
*tokenize -tokenize a string into an array of tokens
*@command: string to tokenize
*@argv:pointer where the tokens are stored
*/
void tokenize(char *command, char *argv[MAX_ARGS])
{
	char *tok;
	int i = 0;

	tok = _strtok(command, " ");
	while (tok != NULL)
	{
		argv[i++] = tok;
		tok = _strtok(NULL, " ");
	}
	argv[i] = NULL;
}

/**
*num_args- count the number of arguments in an array of arguments
*@argv: array of arguments
*Return: number of arguments in the array
*/
int num_args(char *argv[])
{
	int i = 0;

	while (argv[i] != NULL)
		i++;
	return (i);
}


/**
*_atoi-  convert string to integer
*@str: string to convert
*Return: integer value of the string
*/
int _atoi(const char *str)
{
	int i, n = 0;
	int sign = 1;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '-')
			sign = -1;
		else if (str[i] >= '0' && str[i] <= '9')
			n = n * 10 + (str[i] - '0');
		else
			break;
	}
	return (n * sign);
}


/**
*code_exit - exit with a status code
*@status: status code to exit with
*@c: command count
*@a: shell name
*@ag: input command string
*Return: exit code
*/
int code_exit(char *status __attribute__((unused)), int c, char *a, char **ag)
{
	int i = ex_code;
	int j;

	if (status != NULL)
	{
		j = 0;
		while (status[j])
		{
			if (!(status[j] > 47 && status[j] < 58))
			{
				_perrore(a, c, ag[0], ag[1]);
				ex_code = 2;
				return (500);
			}
			j++;
		}
		i = _atoi(status);
	}
	return (i);
}
