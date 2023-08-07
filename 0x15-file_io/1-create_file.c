#include "main.h"

/**
 * create_file - creates a file and puts text in it
 * with 600 perms (do not change if it exists)
 *
 * @filename: name for file
 * @text_content: text to put into file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, length = 0, wlength;

	if (!filename)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	if (!text_content || !(*text_content))
	{
		close(fd);
		return (1);
	}
	while (*(text_content + length))
	{
		length++;
	}

	wlength = write(fd, text_content, length);
	if (wlength != length)
		return (-1);
	close(fd);
	return (1);
}
