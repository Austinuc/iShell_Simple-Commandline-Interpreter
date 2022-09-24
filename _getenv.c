#include "main.h"
/**
  * free_pp - Frees a pointer to pointer allocated with malloc
  * @pp: Given double pointer
  * @size: number of elems its pointing to
  *
  * Return: void
  */

void free_pp(char **pp, unsigned int size)
{
	unsigned int i = 0;

	while (i < size)
	{
		free(pp[i]);
		i++;
	}
	free(pp);
}

extern char **environ;

int _cmp(const char *, const char*);

int _cmp(const char *str1, const char *str2)
{
	int i = 0, result = -9;

	while (str1[i] || str2[i])
	{
		if (str1[i] == str2[i])
			result = 0;
		else
			return (-10);
		i++;
	}
	return (result);
}


/**
  * _getenv - gets the value of an environment variable
  * @name: environment variable name
  *
  * Return: pointer to the value of the field or NULL if not found
  */

char *_getenv(const char *name)
{
	char *delim = "=", *value = NULL, *token = "=", **temp;
	unsigned int i = 0, len;
	int cmp;

	while (environ[i])
		i++;
	len = i;

	temp = malloc(sizeof(char *) * len + 1);
	for (i = 0; environ[i]; i++)
		temp[i] = strdup(environ[i]);
	temp[i] = NULL;

	i = 0;
	while (temp[i])
	{
		token = strtok(token, " ");/*Resets strtok*/
		token = strtok(temp[i], delim);
		cmp = _cmp(name, token);
		if (cmp == 0)
		{
			value = strtok(NULL, "\0");
			value = strdup(value);
			printf("value: %s\n", value);
			break;
		}
		i++;
	}
	free_pp(temp, len);
	return (value);

}

/*
int main(int ac, char **av)
{
	char *value = NULL;
	int i = 1;

	if (ac > 1)
	{
		while (i < ac)
		{
			value = _getenv(av[i]);
			
			printf("%s: %s\n", av[i], value);
			i++;
		}
	}
	else
	{
		fprintf(stderr, "Usage: %s <environ name> ... \n", av[0]);
		exit(EXIT_FAILURE);
	}
	return (0);
}
*/
