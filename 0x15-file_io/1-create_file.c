/*
 * File: 1-create_file.c
 * Auth: Victoria E Iria
 * A function that creates a file.
 */

#include "main.h"
#include <stddef.h>

/**
 * create_file - create a new file and add some content.
 * @filename: name of the file to create.
 * @text_content: content of the text added to the new file.
 *
 * Return: Always 1 on scucess, -1 on Failure
 */

int create_file(const char *filename, char *text_content)
{
	int file_des, w, len;

	file_des = w = len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	file_des = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	w = write(file_des, text_content, len);

	if (file_des == -1 || w == -1)
		return (-1);

	close(file_des);

	return (1);
}
