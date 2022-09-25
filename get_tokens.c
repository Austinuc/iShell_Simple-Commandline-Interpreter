#include "main.h"

/**
  * tokencount - counts the number of token in any given string input
  * @str: input string
  * @delim: string of delimiters
  *
  * Description: Delimiter used to count the tokens is a space
  * Return: Number of tokens found
  */
int count_tokens(char *str, char *delim)
{
	int i = 0, len = 0, j;

	if (!str)
		return (0);
	while(*(str + i) && *(str + i + 1))
	{
		for (j = 0; delim[j]; j++)/*Loop through delims*/
		{
			if (*str == delim[j])/*remove prefixed delims*/
			{
				while (*str == delim[j])
					str++;
				j = 0;
			}
			if (*(str + i) == delim[j])
			{ /*skip if another delim is immediately following*/
				switch (*(str + i + 1))
				{
					case ' ' :
					case '\t' :
					case '\r' :
					case '\n' :
						break;
					default :
						len++;
				}
				break;
			}
		}
		i++;
	}
	len++;

	return (len);
}

/**
  * get_tokens - Gets the tokens in an input string
  * @input: user command input
  * @delim: Delimiters
  *
  * Return: Pointer to string tokens
  */

char **get_tokens(char *input, char *delim)
{
	int tok_count, i = 0;
	char **tokens = NULL, *token = NULL, *temp = NULL;

	tok_count = count_tokens(input, delim);
/*	printf("Token count number: %d\n", tok_count);*/

	token = _strtok_r(input, delim, &temp);

	token = check_cmd_path(token);
	
	if (!token)
		tokens = malloc(sizeof(char *));
	else
		tokens = malloc(sizeof(char *) * tok_count + 1);
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 19);
		exit(EXIT_FAILURE);
	}
	while (token)
	{
		tokens[i] = strdup(token);
		token = _strtok_r(NULL, delim, &temp);
		i++;
	}
	tokens[i] = NULL;
	free(token);
	return (tokens);
}

/*

int main(int ac, char **av)
{
	char **str = NULL;
	int i = 1;

	if (ac > 1)
	{
		if (av[i])
		{
			printf("av[%d]: %s, tokdelim: %s\n", i, av[i], TOK_DELIM);
			str = get_tokens(av[i], " ");
		}
		while (*str)
		{
			printf("Returned: %s\n", *str);
			str++;
		}
	}
	return (0);
}*/
