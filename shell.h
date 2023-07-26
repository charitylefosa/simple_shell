#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stddef.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

#define  UNUSED __attribute__((unused))
#define MAX_ARGS 1024
#define MAX_NUM_Aliases 100
#define BUFFER_SIZE 5024

extern int ex_code;
extern char **environ UNUSED;
static char *cmd __attribute__((unused));

struct Node
{
	char *str;
	struct Node *next;
};


static struct Node *new_node(char *str) UNUSED;

/**
*new_node - Creates a new node for a linked list
*@str: String value to be stored in the new node
*Return: Pointer to the newly created node
*/
static struct Node *new_node(char *str)
{
	struct Node *node = malloc(sizeof(struct Node));

	if (node == NULL)
		return (NULL);
	node->str = str;
	node->next = NULL;
	return (node);
}

static void add_node(struct Node **head, struct Node *node) UNUSED;
/**
*add_node - Adds a node to the end of a linked list
*@head: Pointer to the head of the linked list
*@node: Node to be added to the linked list
*/
static void add_node(struct Node **head, struct Node *node)
{
	if (*head == NULL)
	{
		*head = node;
	}
	else
	{
		struct Node *current = *head;

		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
}

typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;


int _strcmp(const char *str1, const char *str2);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strlen(const char *str);
int _strcpy(char *dest, char *src);
int _strncpy(char *dest, char *src, int size);

void rem_spaces(char *str);
void tokenize(char *command, char *argv[MAX_ARGS]);
int code_exit(char *status __attribute__((unused)), int c, char *a, char **ag);
int _atoi(const char *str);
int num_args(char *argv[]);

void *_memcpy(void *dest, void *src, size_t n);
char *_strcat(char *dest, const char *src);
char *_strdup(char *s);
void *_realloc(void *ptr, size_t size);

void print_list(struct Node *head);
void free_list(struct Node *head);
int _env(void);
int _setenv(const char *name, const char *value);
int _unsetenv(const char *name);

int process_cmd(char **argv);
void _perrore(char *err, int count, char *c, char *arg);

char *which_func(char *command);
void print_all_aliases(alias_t *aliases);

int main(int ac __attribute__((unused)), char **av __attribute__((unused)));
int wspace(char s);
void rewmspaces(char *s);
char *read_command(void);
void handle_sigint(int signo __attribute__((unused)));

void handle_segmfault(int signo __attribute__((unused)));

void add_env_var(struct Node **head, const char *name, const char *value);
void update_environ(struct Node *head);

void _exec(char **_argum, char *av, int count);
void _execve(char *c, char **p, char **r);
void _perror(char *err, int count, char *c);
void _print(char *s);
void _pnumber(int n);

char *_getenv(char *str);

char *_getline(void);
void hash_handler(char *buff);

int _putchar(char c);

char *_strtok(char *str, char const *delim);

void init_aliases(alias_t **aliases);
int alias_command(char *argv[MAX_ARGS], int num_arg __attribute__((unused)));
void set_alias(alias_t **aliases, char *name, char *value);
void print_alias(alias_t *alias);

int access_check(char **arg, char *cmd, char *err, int c, char **e);
int _putchar(char c);

void cd(char *path);

#endif	
