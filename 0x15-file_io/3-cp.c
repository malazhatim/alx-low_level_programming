#include "main.h"
#define BUFFERSIZE 1204
/**
  * main - Copies content.
  * @argc: Arguments count.
  * @argv: Files names.
  * Return: 0 on success
  */
int main(int argc, char **argv)
{
	int in, out, re, ch;
	char buffer[BUFFERSIZE];

	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)

		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	in = open(argv[1], O_RDONLY);
	if (in == -1)
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]), exit(98);
	out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (out == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
	re = ch = 1;
	while (re)
	{
		re = read(in, buffer, BUFFERSIZE);
	if (re == -1)
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]), exit(98);
		if (re > 0)
		{
			ch = write(out, buffer, re);
			if (ch == -1)
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]), exit(99);
		}
	}
	ch = close(in);
	if (ch == -1)
		dprintf(STDERR_FILENO, "Error: Can't close  %d\n", in), exit(100);

	ch = close(out);

	if (ch == -1)
		dprintf(STDERR_FILENO, "Error: Can't close  %d\n", out), exit(100);
	return (0);
}
