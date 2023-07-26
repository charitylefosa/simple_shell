#include "shell.h"

/**
 * _strtok - strtok implementation
 * @str: string
 * @delim: delimiter
 *
 * Return: token
 */
char *_strtok(char *str, char const *delim)
{
	static char *ptr;
	int size = 0;
	char *tok;
	int i = 0;

	if (str != NULL)
		ptr = str;
	while (ptr[i] != '\0')
		if (ptr[i]  == *delim)
		{
			ptr[i] = '\0';
			tok = ptr;
			ptr = &ptr[i + 1];
			return (tok);
		}
		else
			i++;
	if (ptr[0] != '\0')
	{
		while (ptr[size] != 0)
			size++;
		tok = ptr;
		ptr += size; /* update ptr to '\0' */
		return (tok);
	}
	return (NULL);
}
