#ifndef MAIN_H
#define MAIN_H



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stddef.h>
#include <limits.h>


#define MAX_ARGS 10
#define BUFFER_SIZE 1024

extern char **environ;
char *_readline(void)
void handle_exit(char *user_input, char **receive_argv);

int shell_setenv(char **args);
int _unsetenv(char **args)
int handle_envc(char **args)


char *get_path(char *first_command);

char *accept_user_input(void);

int main(int ac, char **argv);
void (*get_command(char *cmd))(void);

char *read_input(ssize_t *fd_check)
int execute_cmd(char **entered_argv);
char **tokez(char *t_user_input, char **argv, ssize_t fd_check);


int s_len(char *string);
void s_copy(char *to, char *from);
void s_cat(char *text_add, char *text);

char **handle_path(void);
int check_ifCommand_exist(char *string);
char **split_string(char *string);

void print_error(char **av, char *errprt)
int _errorprint(char *str)


void exit_shell(char **tokenzd_cmd)
void execute_cmd(char **command, int command_type);
int determine_command_type(char *command);

char *_strchr(char *s, char c);
int _strcspn(char *s, char *charset);
int _strcmp(char *s, char *c);


#endif

