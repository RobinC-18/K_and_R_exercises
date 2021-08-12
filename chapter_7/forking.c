#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* Testing out how forking and exec works */

int main(int argc, char *argv[]) 
{
    int pid = fork();

    if (pid == 0)
    {
        char *args[] = { "lower", "HellOOOO", NULL };
        printf("I am the child process with id: %d\n", pid);
        execlp("echo", "echo", "testing testing", NULL);
    }
    else 
    {
        printf("I am the parent process with id: %d\n", pid);
    }
}