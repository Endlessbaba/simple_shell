#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

/**
 * main - Entry Point
 *
 * Return: Always 0(Success)
 */

int main(void)
{
char input[MAX_INPUT_SIZE];
char *args[2];
int status;

while (1)
{
printf("> ");
fgets(input, MAX_INPUT_SIZE, stdin);
if (feof(stdin))
{
exit(0);
}
input[strcspn(input, "\n")] = '\0'; /* remove trailing newline */
args[0] = input;
args[1] = NULL;

pid_t pid = fork();

if (pid == 0)
{
execve(args[0], args, environ);
fprintf(stderr, "Error: command not found.\n");
exit(1);
}
else if (pid < 0)
{
fprintf(stderr, "Error: fork failed.\n");
exit(1);
}
else
{
wait(&status);
}
}

return (0);
}
