#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

#define Max_Arguments 50
#define BUFFER_SIZE 1024
#define PATH_MAX 1024

void handle_arguments(char *lineptr, char **argv);
void command_prompt(char **env);
void exec_command(char **argv, char **env);
int main(int ac, char **av, char **env);
char* handle_path(char* command);
int string_len(char *string);
void _env(char **env);
char *string_cpy(char *dest, char *src);
int string_cmp(char *s1, char *s2);
char *_strdup(char *str);
char* custom_getline();

#endif