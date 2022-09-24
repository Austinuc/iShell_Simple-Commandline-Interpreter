#include "main.h"

/**
  * init_data - Initializes shell_data structure
  * @shelldata: shell_data object
  * @av: command line argument strings
  *
  * Return: void
  */

void init_data(shell_data *shelldata, char **av)
{
	int i = 0, elems = 0;

	shelldata->input = NULL;
	shelldata->av = av;
	shelldata->args = NULL;
	shelldata->status = 0;
	shelldata->_env = environ;

	for (; environ[i]; i++)/*get num of env variables*/
		elems++;

	shelldata->_env = malloc(sizeof(char *) * elems + 1);

	for (i = 0; environ[i]; i++)
		shelldata->_env[i] = strdup(environ[i]);
	
	shelldata->_env[i] = NULL;

}
