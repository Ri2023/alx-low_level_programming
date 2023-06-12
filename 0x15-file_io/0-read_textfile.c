/*
 * File: 0-read_textfile.c
 * Auth: Victoria E Iria
 * This is a function that reads a text file and
 *       prints it to the POSIX standard output.
 */

#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * read_textfile - fuction that reads a text file
 *            and print it to the POSIX stdout
 * @filename: A pointer to the name of the file.
 * @letters: The max  number of letters to print
 * Return: number of letters read and printed
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fildes, rd, wt;
	char *buff;

	if (!filename)
		return (0);

	fildes = open(filename, O_RDONLY);

	if (fildes == -1)
		return (0);

	buff = malloc(sizeof(char) * (letters));
	if (!buff)
		return (0);

	rd = read(fildes, buff, letters);
	wt = write(STDOUT_FILENO, buff, rd);

	close(fildes);

	free(buff);

	return (wt);
}
