#include "main.h"
#include <stdio.h>
#include <stdlib.h>

void close_file(int fd);
char *b_holder(char *file);


/**
 * close_file - a fuction  that closes file descriptor
 * @fd: file descriptor
 */
void close_file(int fd)
{
	int close_result = close(fd);

	if (close_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}


/**
 * b_holder - function that allocate size to a buffer.
 * @file: the file
 * Return: new buffer
 */
char *b_holder(char *file)
{
	char *buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buf);
}



/**
 * main - a program that copies the content of a file to another file
 * @argc: the arguments count to the program
 * @argv: the arguments vector
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int from, to, read_result, write_result;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = b_holder(argv[2]);
	from = open(argv[1], O_RDONLY);
	read_result = read(from, buf, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (from == -1 || read_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
				argv[1]);
		free(buf);
		exit(98);
	}
	do {
		write_result = write(to, buf, read_result);
		if (to == -1 || write_result == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n",
					argv[2]);
			free(buf);
			exit(99);
		}
		read_result = read(from, buf, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	} while (read_result > 0);

	free(buf);
	close_file(from);
	close_file(to);

	return (0);
}

