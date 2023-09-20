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
	char *args[100];
	pid_t pid;

	(void) argc;

	while (1)
	{
		if (isatty(0))
			printf("$ ");
		if (getline(&input_str, &n, stdin) == -1)
			break;
		get_toks(input_str, args, " \n");
		if (!strcmp(input_str, "env"))
		{
			print_env();
			continue;
		}
		if (exit_handler(args, argv[0]) == -1)
			continue;

		if (access(args[0], X_OK) == -1)
		{
			fprintf(stderr, "%s: No such file or directory\n", argv[0]);
			continue;
		}
		pid = fork();
		if (pid == 0)
		{
			if (execve(args[0], args, env) == -1)
				perror("execve");
		}
		else
		{
			wait(NULL);
		}
	}

	if (isatty(0))
		printf("\n");
	return (0);
}
