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
	int file_descriptor, bytes_written, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[length] != '\0')
			length++;
	}

	mode_t file_permissions = S_IRUSR | S_IWUSR;

	file_descriptor = open(filename,
			O_CREAT | O_WRONLY | O_TRUNC, file_permissions);
	if (file_descriptor == -1)
		return (-1);

	bytes_written = write(file_descriptor, text_content, length);
	if (bytes_written == -1)
	{
		close(file_descriptor);
		return (-1);
	}

	close(file_descriptor);
	return (1);
}
