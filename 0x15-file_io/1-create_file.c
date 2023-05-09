#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

/**
 * create_file - creates a file with given filename and writes text_content to it
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, ret, len;

	if (filename == NULL)
		return (-1);

	/* Open the file with rw------- permissions, or create it if it doesn't exist */
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		len = strlen(text_content);
		ret = write(fd, text_content, len);
		if (ret == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

