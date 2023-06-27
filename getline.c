#include "shell.h"

char* custom_getline() 
{
    static char* Buffer = NULL;
    static size_t BUFFER_SIZE = 0;
    static size_t input = 0;
    int a;
     size_t b = 0;
     char* new_buffer;

    /** If the buffer is empty, allocate a new one*/
    if (Buffer == NULL) {
        BUFFER_SIZE = 1024;
        Buffer = (char*) malloc(BUFFER_SIZE);
        if (Buffer == NULL) {
            return NULL;
        }
    }

    /*Read characters from standard input until a newline is found*/
   
    while ((a = getchar()) != EOF && a != '\n') {
        if (i == BUFFER_SIZE - 1) {
            BUFFER_SIZE *= 2;
            new_buffer = (char*) realloc(Buffer, BUFFER_SIZE);
            if (new_buffer == NULL) {
                free(Buffer);
                return NULL;
            }
            Buffer = New_Buffer;
        }
        Buffer[b++] = a;
    }

    if (a == EOF && b == 0) {
        return (NULL);
    }

    Buffer[b] = '\0';
    input += b;

    return (Buffer);
}
