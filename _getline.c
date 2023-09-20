#include "main.h"

/**
 * _getline - My getline function
 * @lineptr: Pointer to pointer to buffer
 * @n: Pointer to length of buffer
 * @stream: Pointer to file stream
 *
 * Return: Number of characters printed
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int readbytes;
	char *buff = *lineptr;
	size_t size = *n, i;

	if (!size || !buff)
	{
		buff = malloc(sizeof(char) * BUFF_SIZE);
		size = BUFF_SIZE;
		*lineptr = buff;
		*n = size;
	}

	i = 0;
	while (1)
	{
		readbytes = read(fileno(stream), buff + i, size);
		if (readbytes == -1)
			return (-1);
		else if ((size_t) readbytes < size)
			break;
		size *= 2;
		buff = realloc(buff, size);
		*lineptr = buff;
		*n = size;
		i += readbytes;
	}
	buff[i + readbytes + 1] = '\0';

	return (i + readbytes);
}






