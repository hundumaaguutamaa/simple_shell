#include "main.h"

/**
 * shell_setenv - Set a new environment variable. 
 * @args: Array of arguments. 
 * 
 *Return: 0 on success, -1 if fails. 
 */
int shell_senv(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		write(STDERR_FILENO, "Usage: setenv VARIABLE\n", 29);
		return (-1);
	}

	if (setenv(args[1], args[2], 1) == -1)
	{
		print_error(args, "Failed setting env't variable\n");
		return (-1);
	}

	return (0);
}

/**
 * _unsetenv - Removeenv't variable
 * @args: Array of arguments. 
 * Return: 0 on success, or -1 if fails. 
 */
int _unsetenv(char **args)
int handle_envc(char **args)
{
    char *value;
    int result = 0;

    switch (args[0][0])
    {
        case 'a':
            if (strcmp(args[0], "setenv") == 0)
            {
                if (args[1] == NULL || args[2] == NULL)
                    return (-1);
                if (shell_setenv(args) == -1)
                    print_error(args, "Failed to set environment variable\n");
                result = 1;
            }
            break;
        case 'b':
            if (strcmp(args[0], "unsetenv") == 0)
            {
                if (args[1] == NULL)
                {
                    write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 26);
                    return (-1);
                }
                if (unsetenv(args[1]) == -1)
                {
                    write(STDERR_FILENO, "Failed unset env't variable\n", 37);
                    return (-1);
                }
                shell_unsetenv(args);
                result = 1;
            }
            break;
        case 'c':
            if (strcmp(args[0], "echo") == 0)
            {
                if (args[1] == NULL)
                {
                    write(STDERR_FILENO, "Usage: echo VARIABLE\n", 21);
                    return (-1);
                }
                
