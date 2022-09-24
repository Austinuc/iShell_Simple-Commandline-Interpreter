#include "main.h"


/**
  * check_cmd_path - Finds the first token in the environment PATH and
  *                  checks if file is executable
  * @token: First token from the user input
  *
  *
  *
  * Description: The command syntax is as follows 
  *              "<cmd/path to cmd>(required) [options...](optional)"
  * Examples: "ls -la", "/bin/ls -la", etc.
  *
  * Return: absolute path to cmd if found & executable, NULL otherwise
  */

char *check_cmd_path(char *token)
{
	struct stat sb;
	unsigned int status, j;
	char *env_path = NULL, *path = NULL, *next = NULL;
	list_t *head = NULL;

	/*check if token is an absolute path or current dir*/
	if (*token == '/' || *token == '.')
	{
		/*check if path exists and is executable*/
		j = stat(token, &sb);
		if (j == 0 && (sb.st_mode & S_IXUSR))
			return (token);
		else
			return (NULL);
	}
	printf("_getenv: ran\n");
	env_path = _getenv("PATH");/*get all dirs in PATH*/

	/*Create a singly linked list of PATH dirs*/
	path = _strtok_r(env_path, ":", &next);

	while (path)
	{
		add_node(&head, path);
		path = _strtok_r(NULL, ":", &next);
	}
	/**
	  * check if token command exist in any dir of the PATH
	  * also verify if file path is executable
	  */
	while (head)
	{
		path = string_concat(head->str, "/");
		path = string_concat(path, token);
		status = stat(path, &sb);
		if (status == 0 && (sb.st_mode & S_IXUSR))
			return (path);
		head = head->next;
	}

	printf("Path not found\n");
	return (NULL);
}

/*
int main(int ac, char **av)
{
	char *path;

	if (ac > 1)
	{
		path = check_cmd_path(av[1]);
		if (path)
			printf("FOUND: %s\n", path);
		else
			printf("NOT FOUND\n");
	}
	return (0);
}
*/
