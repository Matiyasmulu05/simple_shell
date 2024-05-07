#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void handle_error(char *message, char *buffer);
void execute_command(char *buffer);

int main(void)
{
    char *buffer = NULL;
    size_t bufsize = BUFFER_SIZE;
    ssize_t characters_read;
    pid_t pid;
    int status;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if (buffer == NULL)
    {
        perror("malloc error");
        return (EXIT_FAILURE);
    }

    while (1)
    {
        printf("$ ");
        characters_read = getline(&buffer, &bufsize, stdin);
        if (characters_read == -1)
        {
            if (errno == EINVAL || errno == ENOMEM)
                handle_error("getline error", buffer);
        }
        if (characters_read > 0 && buffer[characters_read - 1] == '\n')
            buffer[characters_read - 1] = '\0';

        execute_command(buffer);
    }

    free(buffer);
    return (EXIT_SUCCESS);
}

void handle_error(char *message, char *buffer)
{
    perror(message);
    free(buffer);
    exit(EXIT_FAILURE);
}

void execute_command(char *buffer)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0)
        handle_error("fork error", buffer);

    if (pid == 0)
    {
        if (execve(buffer, NULL, NULL) == -1)
            handle_error("execve error", buffer);
    }
    else
    {
        wait(&status);
    }
}

