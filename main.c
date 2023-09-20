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
	char *args[2];
	pid_t pid;


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
		{
			perror(argv[0]);
			continue;
		}
		args[0] = input_str;
		args[1] = NULL;
		pid = fork();
		if (pid == 0)
		{
			execve(input_str, args, env);
			perror("Execve");
		}
		else
			wait(NULL);
	}
	free(input_str);
	return (0);
}
