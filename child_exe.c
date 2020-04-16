#include "shellby.h"

/**
 * child_exe - executes a command in a child process.
 * @cmnds: NULL terminated pointer array to the command and flags if there are
 * @argv: string holding the name of the current executable.
 * @count: a counting of errors so far.
 *
 * Return: void.
 */

void child_exe(char **cmnds, char *argv, int count)
{
	if (execve(cmnds[0], cmnds, environ) == -1)
	{
		write(STDERR_FILENO, argv, _strlen(argv));
		write(STDERR_FILENO, ": ", 2);
		print_number(count);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, cmnds[0], _strlen(cmnds[0]));
		write(STDERR_FILENO, ": not found\n", 12);
		exit(EXIT_FAILURE);
	}
}

/**
 * print_number - prints an integer
 * @n: input number to be printed
 *
 * Return: void
 */

void print_number(int n)
{
	int res = n, fact = 1;
	char digit = '0';

	while (res / 10)
	{
		fact *= 10;
		res /= 10;
	}
	while (fact)
	{
		res = n / fact;
		digit = res + '0';
		write(STDERR_FILENO, &digit, 1);
		n = n - (res * fact);
		fact /= 10;
	}
}
