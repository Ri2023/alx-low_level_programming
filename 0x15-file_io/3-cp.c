/*
 * File: 3-cp.c
 * Auth: Victoria E Iria
 * A  program that copies the content of a file to another file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

static ssize_t read_file(char *filename, char **buffer, int fildes);
static void write_copy(char *filename, int fildes, char *buffer, int len);

/**
 * main - this function copies the content of one file to another
 * @argc: This counts number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 1 on success, exit otherwise
 */

int main(int argc, char *argv[])
{
	int fildes_a, fildes_b, nrd_len, close_des;
	char *buffer, *file_from, *file_to;

	buffer = NULL;
	nrd_len = 1;
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	file_from = argv[1];
	file_to = argv[2];
	fildes_a = open(file_from, O_RDONLY);
	fildes_b = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while (nrd_len > 0)
	{
	/* this reads the text from origin file */
	nrd_len = read_file(file_from, &buffer, fildes_a);
	if (!nrd_len)
		break;
	/* this Writes the buffer to destination */
	write_copy(file_to, fildes_b, buffer, nrd_len);
	}

	free(buffer);
	close_des = close(fildes_a);
	if (close_des < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fildes_a);
		exit(100);
	}
	close_des = close(fildes_b);
	if (close_des < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fildes_b);
		exit(100);
	}
	return (0);
}
/**
 * read_file - A function that read a file into a buffer
 * @filename: file to read from
 * @buffer: pointer to a pointer of a buffer.
 * @fildes: file descriptors
 *
 * Return: the current size of the buffer.
 */
static ssize_t read_file(char *filename, char **buffer, int fildes)
{
	int nrd_len;

	if (fildes < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	if (!(*buffer))
		*buffer = malloc(sizeof(char) * BUFSIZ);
	if (!(*buffer))
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	nrd_len = read(fildes, *buffer, BUFSIZ);
	if (nrd_len < 0)
	{
		free(*buffer);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	return (nrd_len);
}

/**
 * write_copy - write the buffer to a file.
 * @filename: name of the file for contents in buffer
 * @fildes: file descriptors for the @filename
 * @buffer: A pointer to a buffer
 * @len: current size of the buffer.
 */
static void write_copy(char *filename, int fildes, char *buffer, int len)
{
	if (fildes < 0 || !buffer)
	{
		free(buffer);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
	if (write(fildes, buffer, len) < 0)
	{
		free(buffer);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
}


