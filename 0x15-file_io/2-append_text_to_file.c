#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int w = 0, c, op;

	if (filename == NULL)
		return (-1);

	op = open(filename, O_WRONLY | O_APPEND);
	if (op < 0)
		return (-1);

	if (text_content)
	{
		while (text_content[w])
			w++;

		c = write(op, text_content, w);
		if (c != w)
			return (-1);
	}

close(op);
return (1);
}
