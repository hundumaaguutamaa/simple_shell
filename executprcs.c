#include "main.h"

/**
 * execute_command - execute entered command. 
 * @entered_argv: array to pointer of strings entered.
 * Return: status of the process. 
 */


int execute_cmd(char **entered_argv);
{
	char *initial_command, char *last_command;
	int pid_status;
	pid_t ppid_process;
	
	initial_command = NULL;
	last_command = NULL;
	ppid_process = -1;
	initial_command = entered_argv[0];
 	last_command = get_path(initial_command);

	switch (access(last_command, X_OK) != -1 && entered_argv) {
    case 1:
        ppid_process = fork();
        if (ppid_process == -1) {
            print_error(entered_argv, "No Command\n");
        } else if (ppid_process == 0) {
            if (execve(last_command, entered_argv, NULL) == -1) {
                print_error(entered_argv, "No Command\n");
            }
        } else {
            if (waitpid(ppid_process, &pid_status, 0) == -1) {
                print_error(entered_argv, "No Command\n");
            }
        }
        return (0);
    default:
        break;
}
	return (1);
}
