#include "main.h"

/**
 * get_toks - Gets all tokens from a string and stores them in an array
 * @str: String to get tokens from
 * @arr: Pointer to array to store tokens in
 * @delim: Delimeter
 *
 * Return: Nothing
 */
void get_toks(char *str, char **arr, char *delim)
{
	int i;

	arr[0] = strtok(str, delim);
	for (i = 1; i < 100; i++)
	{
		arr[i] = strtok(NULL, delim);
		if (!arr[i])
			return;
	}

	if (arr[0] == NULL)
		arr[0] = "No Command";
}
