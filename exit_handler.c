#include "main.h"

/**
 * exit_handler - Handles the Exit call
 * @args: Array of strings where the exit
 * call is stored with it's arguments
 * @pname: Program name incase we show an error
 *
 * Return: 0 if exit wasnt called
 * -1 if called and didnt work
 */
int exit_handler(char **args, char *pname, char **allocated)
{
	int i, exit_code;

	if (strcmp(args[0], "exit"))
		return (0);

	if (!args[1])
	{
		free(*allocated);
		exit(0);
	}

	for (i = 0; args[1][i]; i++)
	{
		if (!isdigit(args[1][i]))
		{
			fprintf(stderr, "%s: Illegal number: %s\n", pname, args[1]);
			return (-1);
		}
	}

	free(allocated);
	exit_code = atoi(args[1]);
	exit(exit_code);
}
