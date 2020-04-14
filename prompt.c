#include "shellby.h"
/**
*inter_shellby - intercactve shell
*@argc: each token
*@argv: token array
*@env: environment vairables
*/
int inter_shellby(char *paths[], char *envp[])
{
	size_t line_size  = 0;
	char *buffer = NULL, *token = NULL, **commands = NULL;
	char *exit_command = "exit", *env_command = "env", heap_token = NULL;
        ssize_t line = 0;
	int i, j, k;
	pid_t child_pid;
	int status;
 	
	printf("shellby~$");
	while(line = getline(&buffer, &line_size, stdin))
	{
		/*check end of file*/
		if (line == EOF)
			free(buffer);
		 /*split the buffer in tokens to be allocate*/
		token = strtok(buffer, " \n\t\r");
		printf("el token es:%s\n",token);
		heap_token = look_inPATH(&token);
        commands = input_tokens(token);
		if (commands == NULL)
			 return (0);

		 /*exit when exit command is entered*/
		if ((_strcmp(exit_command, commands[0])) == 1)
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
			execve(commands[0], commands, NULL);
		}
		else if (child_pid == -1)
		{
			perror("Error:");
			printf("forked pid not 0");
		}
		else{	
			wait(&status); //entender bien el status
			free(heap_token);
			free_str_arr(commands);
		}

		free(commands);
		fee(buffer);
		line_size = 0;
		buffer = NULL;
		printf("shellby~$");
	 }
}
 
