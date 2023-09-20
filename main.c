#include "main.h"

/**
 * main - Shell Program
 * @argc: ...
 * @argv: ...
 * @env: ...
 *
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	char *input_str = NULL;
	size_t n = 0;

	(void) argc;
	(void) argv;
	(void) env;
	while (1)
	{
		printf("(SHELL)$ ");
		if (getline(&input_str, &n, stdin) == -1)
			break;
		input_str = strtok(input_str, "\n");
		if (access(input_str, X_OK) == -1)
			fprintf(stderr, "No such file or directory\n");
	}
	free(input_str);
	return (0);
}
