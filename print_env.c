#include "main.h"

/**
 * print_env - Prints Environment
 *
 * Return: Nothing
 */
void print_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}

	return;
}
