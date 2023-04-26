#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

/**
 * main - Entry point
 *
 * Return: exit success if successful.
 */

int main(void)
{
char *line = NULL;
size_t line_size = 0;

while (1)
{
printf("$ ");
if (getline(&line, &line_size, stdin) == -1)
{
if (errno == 0)
{

printf("\n");
break;
}
perror("getline");
exit(EXIT_FAILURE);
}


line[strcspn(line, "\n")] = '\0';


if (execlp(line, line, NULL) == -1)
{
fprintf(stderr, "Error: Command not found: %s\n", line);
}
}

free(line);
exit(EXIT_SUCCESS);
}
