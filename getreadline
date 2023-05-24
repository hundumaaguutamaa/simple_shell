#include "main.h"

/**
 * _readline - Function to read line from input. 
 * keep position and number of char. 
 *
 * Return: Pointer if success, or NULL if fails. 
 */
char *_readline(void)
{
	static char buffer[BUFFER_SIZE];
	static int cpostn;
	static int size;
	char *line = NULL;
	ssize_t read_size = 0;

	while (1)
	{
		if (cpostn >= size)
		{
			cpostn = 0;
			size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (size <= 0)
				break;
		}
		while (cpostn < size)
		while (buffer[cpostn] != '\n')
{
    line = realloc(line, read_size + 1);
    if (!line)
        return (NULL);
    buffer[cpostn] == '\0' ? (line[read_size] = '\0') : (line[read_size] = buffer[cpostn]);
    read_size++;
    cpostn++;
}
	}
	if (line)
		line[read_size] = '\0';
	return (line);
}
