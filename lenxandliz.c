#include "shell.h"

void command_prompt(char **env)
{
    char *lineptr = NULL;
    /*size_t n = 0;
    ssize_t input;*/
    int a;
    char *argv[Max_Arguments];

    while (1)
    {
        if (isatty(STDIN_FILENO))
        {
            write(STDOUT_FILENO, "simple_shell$  ", 15);
        }
        lineptr = my_getline();
        /***
        input = getline(&lineptr, &n, stdin);**/
        if (/**input*/lineptr == NULL)
        {
            free(lineptr);
            exit(EXIT_FAILURE);
        }
        a = 0;
        while (lineptr[a])
        {
            if (lineptr[a] == '\n')
                lineptr[a] = 0;
            a++;
        }
        handle_arguments(lineptr, argv);
        exec_command(argv, env);
    }
    free(lineptr);
}