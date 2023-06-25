#include "shell.h"

void exec_command(char **argv, char **env)
{
    pid_t child;
    int status;
    char *path;
    char error[] = "No such file or directory\n";

    child = fork();
    if (child == -1) 
    {
        exit(EXIT_FAILURE);
    }
    if (child == 0) 
    {
        path = handle_path(argv[0]);
        if (path != NULL) {
            if (execve(path, argv, env) == -1) 
            {
                perror("execve");
            }
            free(path);
        } 
        else
        {
        write(STDERR_FILENO, argv[0], string_len(argv[0]));
        write(STDERR_FILENO, ": ", 2);
        write(STDERR_FILENO, error, string_len(error));
        exit(EXIT_FAILURE);
        }
    }
    wait(&status);
}