#include "shell.h"

/**
*add_env_var- add a new environmen variable to the linked list
*@head: pointer to the head of the linked list
*@name: environment variable name
*@value: environment variable value
*/
void add_env_var(struct Node **head, const char *name, const char *value)
{
	size_t n_len = _strlen(name);
	size_t v_len = _strlen(value);
	char *new_env_var = malloc(n_len + v_len + 2);
	struct Node *current = *head;

	if (new_env_var == NULL)
	{
		return;
	}
	_memcpy(new_env_var, (void *)name, n_len);
	new_env_var[n_len] = '=';
	_memcpy(new_env_var + n_len + 1, (void *)value, v_len);
	new_env_var[n_len + v_len + 1] = '\0';

	while (current != NULL)
	{
		if (_strncmp(current->str, name, n_len) == 0 && current->str[n_len] == '=')
		{
			free(current->str);
			current->str = new_env_var;
			return;
		}
		current = current->next;
	}
	add_node(head, new_node(new_env_var));
}


/**
*update_environ - update the environ variable with the listed list content
*@head: head of the linked list
*/
void update_environ(struct Node *head)
{
	size_t count = 0;
	size_t i;
	struct Node *current = head;
	char **new_environ;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	new_environ = malloc((count + 1) * sizeof(char *));
	if (new_environ == NULL)
	{
		return;
	}
	current = head;
	for (i = 0; i < count; i++)
	{
		new_environ[i] = current->str;
		current = current->next;
	}
	new_environ[count] = NULL;
	environ = new_environ;
}
