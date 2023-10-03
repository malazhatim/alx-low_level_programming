#include "main.h"

/**
* print_error - print file close error.
* @fd: file descriptor
* Return: None.
*/

void print_error(int fd)
{
	dprintf(STDERR_FILENO, "Error: Can't close of %d\n", fd);
	exit(100);
}

/**
* main - copies the content of a file to another file.
* @argc: number of command line arguments
* @argv: An array containing the program command line arguments
* Return: Always success.
*/
int main(int argc, char *argv[])
{
	int fr, to, c;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97); }
	fr = open(argv[1], O_RDONLY);
	if (argv[1] == NULL || fr < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98); }

	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(fr);
		exit(99);
	}
	while ((c = read(fr, buffer, 1024)) > 0)
	{
		if (c != write(to, buffer, c))
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(fr);
			close(to);
			exit(99);
	}}
	if (c < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98); }
	if (close(fr) < 0)
		print_error(fr);
	if (close(to) < 0)
		print_error(to);
return (0);
}
