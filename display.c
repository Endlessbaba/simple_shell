#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFSIZE 1024

/**
 * main - Entry point
 *
 * Return: Always 0(Success)
 */

int main(void)
{
char *prompt = "$ ";
char input[BUFSIZE];
char *argv[2];
int status;
pid_t pid = fork();
char **environ;

while (1)
{
printf("%s", prompt);
if (fgets(input, BUFSIZE, stdin) == NULL)
{
break;
}
input[strcspn(input, "\n")] = '\0';

argv[0] = input;
argv[1] = NULL;


if (pid < 0)
{
perror("fork() failed");
exit(1);
}
else if (pid == 0)
{
if (execve(argv[0], argv, environ) == -1)
{
perror("execve() failed");
exit(1);
}
exit(0);
}
else
{
while(wait(&status) != pid)
}
}

return (0);
}
