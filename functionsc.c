#include "main.h"

/**
 * _errorprint - Print a string to the standard error
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */
int _errorprint(char *str)
{
	int a;

	if (!(str))
	{
		return (0);
	}
	for (a = 0; str[a]; a++)
	{
		write(2, &str[a], 1);
	}

	return (a);
}
/**
 * print_error - Prints message to the stdr. 
 * @av: The array. 
 * @errprt: The error message. 
 *
 */
void print_error(char **av, char *errprt)
{
	_errputs(_getenv("_"));
	_errputs(": 1: ");
	_errputs(av[0]);
	_errputs(": ");
	_errputs(err);
}

