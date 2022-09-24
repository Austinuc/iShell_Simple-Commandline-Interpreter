#include "main.h"

/**
  * _strtok_r - splits a string into words
  * @str: input string
  * @delim: delimiter
  * @next: saves pointer to next string to be tokenized
  *
  * Return: string and a pointer to next word
  */
char *_strtok_r(char *str, const char *delim, char **next)
{
	char *buffer = NULL;
	size_t i = 0, j = 0;

	if (str)/*Handles recurring calls for same str*/
		*next = str;/*set buffer 2 new str only if str != NULL*/
	if (!(*next))
		return (buffer);
	for (i = 0; (*next)[i]; i++)
	{
		for (j = 0; delim[j]; j++)/*Loop through delims*/
		{
			if (**next == delim[j])/*remove prefixed delims*/
			{
				while (**next == delim[j])
				{
					/*if all last chars tokens, terminte*/
					if ((*next)[1] == '\0')
						return (buffer);
					(*next)++; /*Point to next char*/
				}
				j = 0;
				continue;/*restart delim check again*/
			}
			if ((*next)[i + 1] == '\0')/*Last token*/
			{
				i++, buffer = strndup(*next, ++i), *next = NULL;
				return(buffer);
			}
			if ((*next)[i] == delim[j])
			{ /*skip if another delim is immediately following*/
				buffer = strndup(*next, ++i);
				buffer[i - 1] = '\0';
				*next = (*next) + i; /*mv ptr to next tokens*/
				return (buffer);
			}
		}
	}
	*next = NULL;
	return (buffer);
}

/**
  * main - Entry point
  * @ac: arg count
  * @av: arg string
  *
  * Return: 0 on success
  *

int main(int ac, char *av[])
{
	char *ptr = NULL, *delim = " |:", *next;
	int len = 0, i = 1;

	if (ac > 0 || av[0])
	{
		ptr = _strtok_r(av[1], delim, &next);
		if (ptr)
			printf("token[%d]: %s\n", i, ptr);
		while (ptr)
		{
			i++;
			ptr = _strtok_r(NULL, delim, &next);
			printf("Other token[%d]: %s\n", i, ptr);
		}
	}
	return (0);
}
*/
