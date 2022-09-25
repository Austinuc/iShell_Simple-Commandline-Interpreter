#include "main.h"

/**
  * read_from_file - reads command from text file
  * @shelldata: struct holding initialized arguments from commanline
  *            av[1] holds the filename to read command from
  * @input: buffer to write the read command
  * @interactive: breaks the shell loop after all cmds contained in file
                  are executed
  *
  * Return: number of chars read from file
  */

ssize_t read_from_file(shell_data *shelldata, char **input, int *interactive)
{
	FILE * fp;
	ssize_t nread;
	size_t len = 0;

	printf("Before file open");
	fp = fopen(shelldata->av[1], "r");
	printf("\nAfter file open");
	if (fp == NULL)
		return (0);
	nread = getline(input, &len, fp);
	printf("After file getline");

	fclose(fp);

	*interactive = 0;
	return (nread);
}


/**
  * rm_newlinechar - Removes newline char from user input
  * @input: input string from user
  *
  * Return: NULL
  */

void rm_newlinechar(char **input)
{
	int i = 0;

	while ((*input)[i] != '\0')
	{
		if ((*input)[i] == '\n')
			(*input)[i] = '\0';
		i++;
	}
}


/**
  * get_filename - Gets the executable file name frm a path
  * @path: Given path to the executable file
  *
  * Return: Only the file name, discard the file path
  */

char *get_filename(char *path)
{
	char *next = NULL, *filename = NULL, *temp = NULL;

	temp = _strtok_r(path, "/", &next); /*Get 1st pathname or filename*/
		filename = temp; /*save a pointer to it*/
		while (1)
		{
			if ((temp = _strtok_r(NULL, "/", &next)) == NULL)
				return (filename); /*last pathname is the executable filename*/
			filename = temp; /*always point to pathname*/
		}
}

/**
  * loop_shell - Loops back to shell prompt after executing a command
  * @shelldata: initialized shell data structure
  *
  * Return: void
  */

void loop_shell(shell_data *shelldata)
{
	int check = 10, interactive = 1;
	char *input, *temp = NULL;
	pid_t cpid;

	while (check > 0 && interactive)
	{
		input = NULL;
		printf("Before loop %s\n", shelldata->av[1]);
		if (shelldata->av[1] != NULL)
		{
			printf("Before loop 2 %s\n", shelldata->av[1]);
			check = (int) read_from_file(shelldata,
					&input, &interactive);
			printf("After loop %s\n", shelldata->av[1]);
		}
		else
			check = get_user_input(&input, &interactive);

		if (!input) continue;
		/*Check for errors reading user input*/
		if (check == -1 || check == 0)
		{
			perror("Error reading input! Please try again\n");
			check = 10;
			continue;
		}
		rm_newlinechar(&input);
		check = _strcmp("exit", input);
		if (check == 0)
		{
			shelldata->status = 0;
			break;
		}
		shelldata->args = get_tokens(input, TOK_DELIM);
		if (shelldata->args[0] == NULL)
		{
			shelldata->status = 98;
			write(2, "Command does not exist\n", 23);
			check = 10;
			continue;
		}
		/*Get 1st cmd to use as path for execve func*/
		shelldata->input = strdup(shelldata->args[0]);

		temp = get_filename(shelldata->input);
		shelldata->args[0] = strdup(temp);
		printf("Filename: %s\n", shelldata->args[0]);
		cpid = fork(); /*Create a child process*/

		if (cpid == 0) /*Execute command in the child process*/
			execve(shelldata->input, shelldata->args, shelldata->_env);
		else
		{
			wait(NULL);
			if (!interactive)
				return;
			check = 10;
			shelldata->status = 0;
		}

	}
}

/*
int main(int ac, char **av)
{
	char *filename = NULL;

	if (ac > 1)
	{
		filename = get_filename(av[1]);
		printf("Filename: %s\n", filename);
	}
	return (0);
}*/
