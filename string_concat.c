#include "main.h"

/**
  * string_concat - Concatenates two strings
  * @s1: string 1
  * @s2: string 2
  * 
  *
  * Return: pointer to newly allocated space in mem containing the concat str
  */

char *string_concat(char *s1, char *s2)
{
	char *ptr;
	unsigned int i = 0, j = 0, k = 0, n;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (*(s2 + i) != '\0')
		i++;
	n = i;
	i = 0;
	while (*(s1 + i) != '\0')
		i++;
	n += i;
	ptr = malloc(sizeof(char) * (n + 1));
	if (ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (j = 0; j < n; j++)
	{
		if (j < i)
			*(ptr + j) = *(s1 + j);
		else
		{
			*(ptr + j) = *(s2 + k);
			k++;
		}
	}
	*(ptr + j) = '\0';
	return (ptr);
}
