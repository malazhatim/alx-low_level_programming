#include "main.h"

/**
* print_error - print file close error.
* @f_d: file descriptor
* Return: None.
*/

void print_error(int f_d)
{
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", f_d);
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
	int op_f, op_t, w;
	char buff[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97); }
	op_f = open(argv[1], O_RDONLY);
	if (argv[1] == NULL || op_f < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98); }

	op_t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (op_t < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(op_f);
		exit(99); }
	while ((w = read(op_f, buff, 1024)) > 0)
	{
		if (w != write(op_t, buff, w))
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(op_f);
			close(op_t);
			exit(99);
	}}
	if (w < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98); }
	if (close(op_f) < 0)
		print_error(op_f);
	if (close(op_t) < 0)
		print_error(op_t);
return (0);
}
