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
#define MAX ARGS 1024
#define MAX_NUM_Aliases 100
#define BUFFER_SIZE 5024

extern char int ex_code;
extern char **environ UNUSED;
stratic char *cmd __attribute__((unused));

struct Node
{
	char *str;
	struct Node *next;
};

static struct Node *new_node(char *str) UNUSED;


struct void add_node(struct Node **head, struct Node *node)
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

typeof struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;


int _strcmp(const char *str1, const char *str2)
int _strncmp(const char *s1, constr char *s2, size_r n)
int _strlen(const char *str)
int _strcpy(char *dest, char *src)
int _strncpy(char *dest, char src, int size)

void remove_trailing_and_leading_spaces(char *str)
void tokenize(char *command, char *argv[MAX_ARGS])
int _lexit(char *status __attribute__((unused)), int c, char *a, chr **ag)
int _atoi(const char *str)
int num_args(char *argv[])

void *_memcpy(void *dest, void *src, size_t n);
char *_strcat(char *dest, const char *src);
char *_strdup(char *s);
void *_realloc(void *ptr, size_t size);

void print_list(struct Node *head)
void free_list(struct Node *head)
int _env(void)
int _setenv(const char *name, const char *value)
int _unsetenv(const char *name)

int process_command(char *argv)
void _perrore(char *err, int count, char *c, char *arg)

char *which(char *command)
void print_all_aliases(alias_t *aliases)

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
int wspace(char s)
void rewmspaces(char *s)
char *read_command(void)
void handle_sigint(int signo __attribute__((unused)))

void handle_segfault(int signo __attribute__((unused)))

void add_env_var(struct Nod **head, const char *name, const char *value)
void update_environ(struct Node *head)

#endif	
