#include "main.h"
/**
  * append_text_to_file - Appends text at the end of a file.
  * @filename: Name of the file and text_content.
  * @text_content: The NULL terminated string to add at the end of the file.
  * Return: 1 on success, -1 on failure
  */
int append_text_to_file(const char *filename, char *text_content)
{
	int of, wf, b;

	if (filename == NULL)
		return (-1);
	if (text_content == NULL)
		return (1);

	of = open(filename, O_APPEND | O_WRONLY);
	if (of == -1)
		return (-1);

	for (b = 0; text_content[b] != '\0'; b++)
		;
	wf = write(of, text_content, b);
	if (wf == -1)
		return (-1);

	close(of);
	return (1);
}
