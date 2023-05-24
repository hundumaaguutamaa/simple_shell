#include "main.h"

/**
 * read_input - Read user and display prompts. 
 * @fd_check: Checks number of inputs. 
 *
 * Return: Input of user. 
 */

char *read_input(ssize_t *fd_check)
{
	char *_display = "$ ";
	char *_input = NULL;
	
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, _display, 2);
	}

	_input = _getline();
	if (_input == NULL)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	*fd_check = strlen(_input);

	switch (*fd_check)
	{
	case -1:
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(_input);
		exit(EXIT_SUCCESS);
	case 0:
		if (isatty(STDIN_FILENO))
		{
			free(_input);
			return (prompt_read(fd_check));
		}
	default:
		break;
	}

	_input[_strcspn(_input, "\n")] = '\0';
	return (_input);
}
