/*
 * File: 2-append_text_to_file.c
 * Auth: Victoria E Iria
 * A function that appends text at the end of a file.
 */

#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: Name of the file.
 * @text_content: The content to add to the file.
 *
 * Return: 1 if the function is succeful, or -1 if not
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fildes, wt, len;

	fildes = wt = len = 0;
	if (!filename)
		return (-1);

	else if (!text_content || !text_content[0])
		return (1);

	fildes = open(filename, O_WRONLY | O_APPEND);
	if (fildes < 0)
		return (-1);

	while (text_content[len])
		len++;

	wt = write(fildes, text_content, len);
	if (wt < 0)
		return (-1);

	close(fildes);
	return (1);
}

