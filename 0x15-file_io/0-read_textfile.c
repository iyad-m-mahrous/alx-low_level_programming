#include "main.h"

/**
 * read_textfile - prints text from a file
 *
 * @filename: name of the file
 * @letters: number of characters to read
 *
 * Return: actual number of letters read, 0 if end of file
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, rlength, wlength;
	char *buff;

	if (!filename)
		return (0);

	fd = open(filename, 0_RDONLY);
	if (fd == -1)
		return (0);
	buff = malloc(sizeof(*buff) * letters);
	if (!buff)
	{
		close(fd);
		return (0);
	}
	rlength = read(fd, buff, letters);
	if (rlength == -1)
	{
		close(fd);
		free(buff);
		return (0);
	}
	wlength = write(STDOUT_FILENO, buff, rlength);

	free(buff);
	close(fd);

	if (wlength != rlength)
		return (0);

	return (wlength);


}
