#include "shell.h"

/**
*which_func - which function
*@command: the command
*Return: path to executable
*/
char *which_func(char *command)
{
	char *path = _getenv("PATH");
	char *p_copy;
	char *d;

	if (path == NULL)
	{
		return (NULL);
	}
	p_copy = _strdup(path);
	d = _strtok(p_copy, ":");

	while (d != NULL)
	{
		char full_path[1024];

		_strcpy(full_path, d);
		_strcat(full_path, "/");
		_strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			free(p_copy);
			return (_strdup(full_path));
		}
		d = _strtok(NULL, ":");
	}
	free(p_copy);
	return (NULL);
}


/**
*print_all_aliases- prints aliases
*@aliases: the aliases
*/
void print_all_aliases(alias_t *aliases)
{
	alias_t *alias;

	for (alias = aliases; alias; alias = alias->next)
		print_alias(alias);
}
