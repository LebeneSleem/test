#include "shell.h"

void _env(char **env)
{
    int a;

    for (a = 0; env[a] != NULL; a++)
    {
        write(STDOUT_FILENO, env[a], string_len(env[a]));
        write(STDOUT_FILENO, "\n", 1);
    }
}
