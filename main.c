#include "main.h"

/**
 */
int main(int argc, char **argv, char **env)
{
	char *buff = NULL;
	size_t n = 0, i;
	char *args[100];
	pid_t pid;

	while (1)
	{
		printf("$ ");
		if (getline(&buff, &n, stdin) == -1)
			break;
		args[0] = strtok(buff, "\n");
		for (i = 1; i < 100; i++)
		{
			args[i] = strtok(NULL, "\n");
			if (!args[i])
				break;
		}

		pid = fork();
		if (pid == 0)
		{
			if (execve(args[0], args, env) == -1)
				fprintf(stderr, "%s: No such file or directory\n", argv[0]);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}

	printf("\n");
	return (0);
}
