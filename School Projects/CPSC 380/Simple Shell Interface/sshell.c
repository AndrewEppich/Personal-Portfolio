#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 80

int main(void)
{

    char *args[MAX_LINE / 2 + 1];
    char input[MAX_LINE];
    int should_run = 1;

    pid_t pid;

    while (should_run)
    {
        printf("osh> ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            perror("fgets failed");
            continue;
        }

        input[strcspn(input, "\n")] = 0;

        char *token = strtok(input, " ");
        int num_args = 0;
        while (token != NULL && num_args < MAX_LINE / 2)
        {
            args[num_args++] = token;
            token = strtok(NULL, " ");
        }

        if (num_args > 0 && strcmp(args[0], "exit") == 0) {
            break;
        }

        args[num_args] = NULL;

        int background = 0;
        if (num_args > 0 && strcmp(args[num_args - 1], "&") == 0)
        {
            background = 1;
            args[num_args - 1] = NULL;
        }
            pid = fork();
            if (pid < 0)
            {
                perror("Fork Failed");
                return -1;
                exit(1);
            }
            else if (pid == 0)
            {
                execvp(args[0], args);
                perror("execvp failed");
                exit(1);
            }
            else
            {
                if (background == 0){
                wait(NULL);
                }
                else if (background == 1){
                    printf("Background process ID %d\n", pid);
                }
            }
    }
    return 0;
}