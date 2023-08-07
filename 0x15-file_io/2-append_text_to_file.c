#include "main.h"

/**
 * append_text_to_file - creates a file and puts text in it
 * with 600 perms (do not change if it exists)
 *
 * @filename: name for file
 * @text_content: text to put into file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, length = 0, wlength = 0;

	if (!filename)
		return (-1);
	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);
	while (text_content && *(text_content + length))
	{
		length++;
	}
	if (length)
		wlength = write(fd, text_content, length);

	if (close(fd) == -1 || wlength != length)
		return (-1);
	return (1);

}
