#include "main.h"

/**
 * append_text_to_file - a function that appends text at the end of a file.
 * @filename: the name of the file
 * @text_content: the NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
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

	file_descriptor = open(filename, O_WRONLY | O_APPEND);

	if (file_descriptor == -1)
		return (-1);

	write_result = write(file_descriptor, text_content, length);

	if (write_result == -1)
		result = -1;

	if (close(file_descriptor) == -1)
		result = -1;

	return (result);
}
