#include "shell.h"

void handle_arguments(char *lineptr, char **argv)
{
    int b = 0;
    char *args, *lineptr_copy;

    lineptr_copy = _strdup(lineptr);

        args = strtok(lineptr_copy, " ");
        while (args != NULL)
        {
            argv[b] = _strdup(args);
            b++;
            args = strtok(NULL, " ");
        }
        argv[b] = NULL;

         if (string_cmp(argv[0], "exit") == 0)                               
                {                                                               
                        free(lineptr);                                                                                
                        exit(EXIT_SUCCESS);                                     
                 }           
}