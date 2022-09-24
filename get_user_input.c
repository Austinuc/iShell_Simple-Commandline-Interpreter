#include "main.h"

/**
  * get_user_input - Gets the user input either from pipped or from terminal
  * @input: buffer to store user input
  * @interactive: sets status for interactive(val = 1)
  *               or non-interactive (val = 0) shell
  *
  * Return: > 0 for success, -1 0r 0 on failure
  */

int get_user_input(char **input, int *interactive)
{
	size_t n = 0;
	int status = -1;

	/*Check if stdin is connected to terminal*/
	if (isatty(fileno(stdin)))
	{
		*interactive = 1;
		write(STDOUT_FILENO, "myShell:) ", 10);
		status =  getline(input, &n, stdin);
	}
	else /*Shell was invoke in non-interactive mode*/
	{
		*interactive = 0;
		status = getline(input, &n, stdin);
	}
	return (status);
}
