#include "shellby.h"

/**
 * non_inter_shellby - non interactive simple shell run.
 * @argc: numer of input arguments.
 * @argv: NULL terminated array of input arguments.
 *
 * Return: 0 on success.
 */

int non_inter_shellby(int argc, char *argv[])
{
	char *args_temp[2] = {NULL, NULL};

	if (argc > 1)
	{
		/*file input*/
		args_temp[0] = argv[1];
		child_exe(args_temp, argv[0], 1);
	}
	else
	{
		/*commands from pipe*/
		non_inter_piped(argv[0]);
	}
	return (0);
}

/**
 * non_inter_piped - runs non interactive shell when input is piped.
 * @argv: name of the program.
 *
 * Return: 0 on success.
 */

int non_inter_piped(char *argv)
{
	char **cmnds = NULL, *buffer = NULL, *token = NULL;
	char *heap_token = NULL;
	size_t size = 0;
	pid_t child_pid;
	int status, error = 0, count = 1;

	while ((getline(&buffer, &size, stdin)) != -1)
	{
		if (*buffer != '\n')
		{
			token = strtok(buffer, " \n\t\r");
			if (_strcmp(token, "exit") == 0)
			{
				free(buffer);
				return (0);
			}
			heap_token = look_inPATH(&token);
			cmnds = input_tokens(token, buffer);
			child_pid = fork();
			if (child_pid == 0)
			{
				child_exe(cmnds, argv, count);
			}
			else
			{
				wait(&status);
				if (WIFEXITED(status))
				{
					error = WEXITSTATUS(status);
				}
			}
			free_all(buffer, cmnds, heap_token);
			size = 0;
		}
		count++;
	}
	free(buffer);
	return (error);
}
