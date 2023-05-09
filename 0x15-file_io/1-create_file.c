#include "main.h"

/**
 * create_file - a function that creates a file.
 * @filename: A string  to the name of the file to create.
 * @text_content: A string to write to the file.
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int file_descriptor, write_result, length = 0;
	int result = 1;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		char *text_ptr = text_content;

		while (*text_ptr++)
			length++;
	}

	file_descriptor = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (file_descriptor == -1)
		return (-1);

	write_result = write(file_descriptor, text_content, length);
	if (write_result == -1)
		result = -1;

	if (close(file_descriptor) == -1)
		result = -1;

	return (result);
}

