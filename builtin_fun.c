#include "main.h"
/**
 * exit_shell - Exits the shell.
 * @tokenzd_cmd: Command entered by user. 
 *
 * Return: Nothing 
 */
void exit_shell(char **tokenzd_cmd)
{
	char *shelln = NULL;
	char *line = NULL;
	char **cmd = NULL;
	int status = 0;
	int num_token = 0, arg;
	const char *error_message = "$:Arguments over count\n";

	while (tokenzd_cmd[num_token] != NULL) {
  num_token++;
}
	switch(num_token) {
  case 1:
    free_array(tokenzd_cmd);
    free(line);
    free(cmd);
    exit(status);
    break;
  case 2:
    arg = _atoi(tokenzd_cmd[1]);
    if (arg == -1) {
      write(STDERR_FILENO, shelln, strlen(shelln));
      write(STDERR_FILENO, ": 1: exit: error ", strlen(": 1: exit: error "));
      write(STDERR_FILENO, tokenzd_cmd[1], strlen(tokenzd_cmd[1]));
      write(STDERR_FILENO, "\n", 1);
      status = 2;
    } else {
      free(line);
      free(tokenzd_cmd);
      free(cmd);
      exit(arg);
    }
    break;
  default:
    write(STDERR_FILENO, error_message, strlen(error_message));
}

}

/**
 * exit_cmd - Handle exiting the command.
 * @user_input: User input.
 * @received_argv: Array of command arguments
 *
 */
void exit_cmd(char *user_input, char **received_argv)
{
	free(user_input);
	exit_shell(received_argv);
}

