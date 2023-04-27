#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>

#define MAX_INPUT_SIZE 1024
#define BUFSIZE 1024

int largest_number(int a, int b, int c);

int main (void);

#endif
