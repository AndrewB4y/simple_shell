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
	if (argc > 1)
	{
		printf("Undefined Non-interactive\n");
		printf("argv[0] %s\n", argv[0]);
		printf("envp[0] %s\n", envp[0]);
		/*command from args*/
	}
	else
	{
		/*commands from pipe*/
		non_inter_piped();
	}
	return (0);
}

/**
 * non_inter_piped - runs non interactive shell when input is piped.
 *
 * Return: 0 on success.
 */

int non_inter_piped(void)
{
	char **commands = NULL;
	char *buffer = NULL, *token = NULL, heap_token = NULL;
	size_t size = 0, bytes = 0;
	pid_t child_pid;
	int status;

	bytes = getline(&buffer, &size, stdin);
	while (bytes != -1)
	{
		if (*buffer != '\n')
		{
			token = strtok(buffer, " \n\t\r");
			if (_strcmp(token, "exit") == 0)
			{
				free(buffer);
				return (0);
			}
			heap_token = look_inPATH(&token, paths);
			commands = input_tokens(token);
			child_pid = fork();
			if (child_pid == 0)
			{
				if (execve(commands[0], commands, NULL) == -1)
				{
					perror("Error:");
				}
			}
			else
			{
				wait(&status);
				free(heap_token);
				free_str_arr(commands);
			}
		}
		bytes = getline(&buffer, &size, stdin);
	}
	return (0);
}
