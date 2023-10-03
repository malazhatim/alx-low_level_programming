#include "main.h"

/**
* read_textfile - Reads a text file and prints in POSIX stdout.
* @filename: File to read.
* @letters: Number of letter it should read and print.
* Return: Actual number of letter it could read and print.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
ssize_t a, b;
char *buffer;
buffer = malloc(sizeof(char) * letters);
a = open(filename, O_RDONLY);
b = write(STDOUT_FILENO, buffer, read(a, buffer, letters));

	if (!filename)
		return (0);

	if (!buffer)
		return (0);

	if (a == -1 || b == -1)
		return (0);
	close(a);
	free(buffer);
	return (b);
}
