#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: Name of the file to create.
 * @text_content: Text to  write in the file.
 * Return: 1 on success, -1 on failure (file can not be created,
 * file can not be written, write “fails”, etc…)
 */
int create_file(const char *filename, char *text_content)
{
	int of, wf;

	if (!filename)
		return (-1);

	of = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);

	if (of == -1)
	{
		return (-1);
	}

	if (!text_content)
		return (1);

	wf = write(of, text_content, strlen(text_content));
	close(of);
	if (wf == -1)
	{
		close(of);
		return (-1);
	}

	return (1);
}
