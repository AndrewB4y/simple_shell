#include "shellby.h"
/**
*inter_shellby - intercactve shell
*
* Return: 0 on success.
*/
int inter_shellby(void)
{
	size_t line_size  = 0;
	char *buffer = NULL, *token = NULL, **commands = NULL;
	char *exit_command = "exit", *heap_token = NULL;
        ssize_t line = 0;
	int i;
	pid_t child_pid;
	int status;

	printf("shellby~$ ");
	while((line = getline(&buffer, &line_size, stdin)))
	{
		/*check end of file*/
		if (line == EOF)
			free(buffer);
		if (*buffer == '\n')
		{
			/*write(STDOUT_FILENO, "\n", 1);*/
			write(STDOUT_FILENO, "shellby~$ ", 9);
			continue;
		}
		 /*split the buffer in tokens to be allocate*/
		token = strtok(buffer, " \n\t\r");
		printf("el token es:%s\n",token);
		heap_token = look_inPATH(&token);
		commands = input_tokens(token, buffer);
		if (commands == NULL)
			 return (0);

		 /*exit when exit command is entered*/
		if ((_strcmp(exit_command, commands[0])) == 0)
		{
			printf("se tecleo exit\n");
                        free(buffer);
			free(commands);
			exit(0);
		}

		 /*print commmands*/
		printf("command:");
		for (i = 0; commands[i] != NULL ;i++)
		{
			printf("%s", commands[i]);
			printf(" ");
		}
		printf("\n");


		/*create a new process using fork()*/
		child_pid = fork();
		if (child_pid == 0)
		{
			printf("forked succes pid = 0\n");
			execve(commands[0], commands, environ);
			free(heap_token);
			free(commands);
			free(buffer);
			exit(1);
		}
		else if (child_pid == -1)
		{
			perror("Error:");
			printf("forked pid not 0");
			exit(1);
		}
		else{
			wait(&status);
		}

		free(heap_token);
		free(commands);
		free(buffer);
		line_size = 0;
		buffer = NULL;
		printf("shellby~$ ");
	 }
	return (0);
}
