#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * append_text_to_file - Appends text to the end of a file
 * @filename: The name of the file
 * @text_content: The NULL-terminated string to add at the end of the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	FILE *file;
	int ret = 1;
	size_t text_len;

	if (filename == NULL)
		return (-1);

	file = fopen(filename, "a");
	if (file == NULL)
		return (-1);

	if (text_content == NULL)
		goto close_file;

	text_len = strlen(text_content);
	if (fwrite(text_content, 1, text_len, file) != text_len)
		ret = -1;

close_file:
	if (fclose(file) != 0)
		ret = -1;

	return (ret);
}

