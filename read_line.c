#include "main.h"


/**
  * _getline - reads  an  entire  line from stream, storing the 
  * address of the buffer containing the text into *lineptr.
  * The buffer is  null-terminated  and  includes the newline
  * character, if one was found.
  * @lineptr: Pointer to the buffer containing the text
  * @n: pointer to number of bytes to read
  * @stream: where to readline from
  *
  * Return: number of bytes read
  */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buf;
	ssize_t len = 0;
	unsigned int i = 0;

	if (*lineptr == NULL && *n == 0)
	{
		buf = malloc(sizeof(char) * 1024);
		if (buf == NULL)
			exit(98);
		while (i < 1023)
		{
			buf[i] = '0';
			i++;
		}
		buf[i] = '\0';
		*lineptr = buf;
	}
	else
	{
		buf = *lineptr;
	}
	*n = (size_t) i;
	i = 0;
	while (1)
	{
		if (i >= *n)
		{
			buf = _realloc(buf, i, (i + 1024));
			*n += 1024;
		}
		buf[i] = getc(stream);
		if (buf[i] == '\n' || buf[i] == '\0')
			break;
		i++;
	}
	buf[++i] = '\0';
	printf("%s", buf);
	return (i);
}


/**
  * main - prints user input on next line
  *
  * Return: 0 on success
  *

int main(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t len;

	len = _getline(&lineptr, &n, stdin);

	return (len);

}*/
