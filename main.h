#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <stdbool.h>

#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;

/**
  * struct list_s - singly linked list of the PATH directories
  * @str: string - (malloc'ed string)
  * @len: length of string
  * @next: points to the next node
  *
  * Description: singly linked list node structure
  */

typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

list_t *add_node(list_t **head, const char *str);

/**
  * struct data - structure containing all relevant data at runtime
  * @input: input commands
  * @status: last status code of the shell
  * @args: command arguments or tokens from command line
  * @av: input strings for non-interactive shell
  * @_env: environment variables
  *
  */

typedef struct data
{
	char *input;
	char **args;
	char **av;
	char **_env;
	int status;
} shell_data;

/*Initialize data structure*/
void init_data(shell_data *, char **);

int tokencount(char *);

int get_user_input(char **input, int *interactive);
char **get_tokens(char *input, char *delim);
char *check_cmd_path(char *token);
char *_getenv(const char*);
char *get_filename(char *);
void loop_shell(shell_data *shelldata);
void rm_newlinechar(char **input);

/*File stream functions*/
ssize_t _getline(char **, size_t *, FILE *);


/*Memory functions*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/*String functions*/
char *string_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
char *_strtok_r(char *, const char *, char **);

#endif /*Header files for Ishell program*/
