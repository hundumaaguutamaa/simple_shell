#include "main.h"


/**
 * tokez - Split input command strings in to character. 
 * @t_user_input: pointer to user input.
 * @fd_check: size of input read.  
 *
 * @argv: Array of pointer to strings
 * Return: Array of pointer. 
 */

char **tokez(char *t_user_input, char **argv, ssize_t fd_check);
{
	char *userinput_copy, *parse_token;
	const char *delimiter;
	int token_count = 0, num = 0;
	int token_length;

	userinput_copy = malloc(sizeof(char) * fd_check);
	if (userinput_copy == NULL)
	{
		perror("Error: cannot allocate memory");
		return (NULL);
	}

	parse_token = strtok(t_user_input, delimiter);

	while (parse_token != NULL)
	{
		token_count++;
		parse_token = strtok(NULL, delimiter);
	}
	token_count++;


	argv = malloc(sizeof(char *) * token_count);
	parse_token = strtok(userinput_copy, delimiter);
	for (num = 0; parse_token != NULL; num++)
	{
		token_length = s_len(parse_token);
		argv[num] = malloc(sizeof(char) * token_length + 1);
		argv[num][token_length] = '\0';
		s_copy(argv[num], parse_token);
		parse_token = strtok(NULL, delimiter);
	}
	
	delimiter = " \n";

	argv[num] = NULL;
	free(userinput_copy);
	return (argv);
}
