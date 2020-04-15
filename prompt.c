#include "shellby.h"
/**
*inter_shellby - intercactve shell
* Return: 0 on success.
*/
int inter_shellby(void)
{
	size_t line_size  = 0;
	char *buffer = NULL, *token = NULL, **commands = NULL, *heap_token = NULL;
	ssize_t line = 0;
	int  status;
	pid_t child_pid;

	printf("shellby~$ ");
	while ((line = getline(&buffer, &line_size, stdin)))
	{
		if (line == EOF)/*check end of file*/
			free(buffer);
		if (*buffer == '\n')
		{
			write(STDOUT_FILENO, "shellby~$ ", 9);
			continue;
		}
		token = strtok(buffer, " \n\t\r");
		heap_token = look_inPATH(&token);
		commands = input_tokens(token, buffer);
		if (commands == NULL)
			return (0);
		if ((_strcmp("exit", commands[0])) == 0)
		{
			free_all(buffer, commands, NULL);
			exit(0);
		}
		child_pid = fork();
		if (child_pid == 0)
		{
			execve(commands[0], commands, environ);
			free_all(buffer, commands, heap_token);
			exit(1);
		}
		else if (child_pid == -1)
		{
			perror("Error:");
			exit(1);
		}
		else
		{
			wait(&status);
		}
		free_all(buffer, commands, heap_token);
		line_size = 0;
		buffer = NULL;
		printf("shellby~$ ");
	}
	return (0);
}
