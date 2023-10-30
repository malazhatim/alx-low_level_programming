#include "main.h"

/**
 * create_file - reads a text file and prints it to the POSIX standard output
 * @filename: name of the file to be read
 * @text_content: a NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int c = 0, w, op;

	if (!filename)
		return (-1);

	op = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (op < 0)
		return (-1);

	if (text_content)
	{
		while (text_content[c])
			c++;

		w = write(op, text_content, c);
		if (w != c)
			return (-1);
	}

close(op);
return (1);
}
