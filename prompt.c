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
	char *exit_command = "exit", *env_command = "env";
        ssize_t line = 0;
	int i, j, k;
 	
	printf("shellby~$");
	while(line = getline(&buffer, &line_size, stdin))
	{
		/*check end of file*/
		if (line == EOF)
			free(buffer);
		 /*split the buffer in tokens to be allocate*/
		token = strtok(buffer, " \n\t\r");
		printf("el token es:%s\n",token);
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
		/*pid = fork();
		if (pid == -1)
			perror("Error");
		if(pid == 0)
		{
		
		}*/

		free(commands);
		fee(buffer);
		line_size = 0;
		buffer = NULL;
		printf("shellby~$");
	 }
}
 
