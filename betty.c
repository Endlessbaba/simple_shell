#include <stdio.h>
#include "shell.h"

/**
 * print_name - prints a name
 * @name: the array that stores the name
 * @f: a function pointer
 * Return: Nothing
 */

void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
