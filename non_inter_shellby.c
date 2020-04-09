#include "shellby.h"

/**
 * non_inter_shellby - non interactive simple shell run.
 * @paths: contains all the directories in the env variable PATH.
 * @argc: numer of input arguments.
 * @argv: NULL terminated array of input arguments.
 * @envp: NULL terminated array of environment variables.
 *
 * Return: 0 on success.
 */

int non_inter_shellby(char *paths[], int argc, char *argv[], char *envp[])
{
	char **commands = NULL;
	char *buffer = NULL, *token = NULL, heap_token = NULL;
	size_t size = 0, bytes = 0;
	pid_t child_pid;
	int status;

	if (argc > 1)
	{
		printf("argv[0] %s\n",argv[0]);
		printf("envp[0] %s\n",envp[0]);
		/*command from args*/
	}
	else
	{
		/*commands from pipe*/
		bytes = getline(&buffer, &size, stdin);
		while (bytes != -1)
		{
			if (*buffer != '\n')
			{
				token = strtok(buffer, " \n\t\r");
				if (_strcmp(token, "exit") == 0)
				{
					free (buffer);
					return (0);
				}
				/*should consider env?send it to execv?*/
				//heap_token = look_inPATH(&token, paths);
				//commands = input_tokens(token);
				child_pid = fork();
				if (child_pid == 0)
				{
					if (execve(commands[0], commands, NULL) == -1)
					{
						//perror("Error:");
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
	}

	return (0);
}
