#include "main.h"
#include <stdio.h>

/**
 * close_check - closes a file descriptor and prints
 * an error message if it fails
 *
 * @fd: file descriptor to close
 *
 * Return: 0 on success, 100 on error
 */
int close_check(int fd)
{
	int status;

	status = close(fd);
	if (status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
	return (0);
}

/**
 * rw_error - error handler for read or write error
 *
 * @rfd: read file descriptor to close
 * @wfd: write file descriptor to close
 * @filename: filename prompting the error
 * @rw: whether r for read or w for write
 *
 * Return: 98 if read error or 99 if write error
 */
int rw_error(int rfd, int wfd, char *filename, char rw)
{
	if (rw == 'r')
		dprintf(STDERR_FILENO, "Error: Can't read from %s\n", filename);
	else if (rw == 'w')
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
	close_check(rfd);
	close_check(wfd);
	if (rw == 'r')
		return (98);
	return (99);
}


/**
 * main - copy one file to another, new file with perms 664
 * usage - cp file_from file_to
 *
 * @argc: number of arg
 * @argv: list of args
 *
 * Return: 97 if incorrect num of args
 * 98 if file_from does not exist or unreadable
 * 99 if write fails
 * 100 if file close fails
 * 0 otherwise
 */
int main(int argc, char *argv[])
{
	char buff[100];
	int rfd, wfd, rlength = 0, wlength = 0;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}
	rfd = open(argv[1], O_RDONLY);
	if (rfd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		return (98);
	}
	wfd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (wfd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_check(rfd);
		return (99);
	}
	do {
		rlength = read(rfd, buff, 100);
		if (rlength == -1)
			rw_error(rfd, wfd, argv[1], 'r');
		wlength = write(wfd, buff, rlength);
		if (wlength == -1 || wlength != rlength)
			rw_error(rfd, wfd, argv[2], 'w');
	} while (rlength == 100);
	close_check(rfd);
	close_check(wfd);
	return (0);
}
