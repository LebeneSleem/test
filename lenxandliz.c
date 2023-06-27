#include "shell.h"

void command_prompt(char **env)
{
    char *input = NULL;
    /*size_t n = 0;
    ssize_t input;*/
    int a = 0;
    char *argv[Max_Arguments];

    while (1)
    {
        if (isatty(STDIN_FILENO))
        {
            write(STDOUT_FILENO, "simple_shell$  ", 15);
        }
        input = custom_getline();
        /***
        input = getline(&lineptr, &n, stdin);**/
        if (/**input*/input == NULL)
        {
            free(input);
            exit(EXIT_FAILURE);
        }
        while (input[a])
        {
            if (input[a] == '\n')
                input[a] = 0;
            a++;
        }
        handle_arguments(input, argv);
        exec_command(argv, env);
    }
    free(input);
}