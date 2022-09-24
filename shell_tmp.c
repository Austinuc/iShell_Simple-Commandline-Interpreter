#include "main.h"


/**
  * main - Entry point of the function
  * @ac: command line argument count
  * @av: array of command line arguments
  * @env: array of environment variables
  *
  * Return: 0 on successful shell exit
  */
int main(int ac, char **av, char **env)
{
	shell_data shelldata;

	init_data(&shelldata, av); /*Initialize shell data object*/

	loop_shell(&shelldata);
	return (shelldata.status);
}
