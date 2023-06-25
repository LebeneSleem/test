#include "shell.h"

int main(int ac, char **av, char **env)
{
    
    (void)av;
    
    if (ac == 1)
    command_prompt(env);
    return (0);
}