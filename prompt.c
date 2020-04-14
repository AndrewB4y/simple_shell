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
	char *buffer = NULL, *token = NULL, **commands;
	ssize_t line = 0;
	pid_t child_pid;
	int status;

	//show prompt
	printf("shellby~$");

	/*loop that reads a line always*/
	while((line = getline(&buffer, &line_size, stdin)))
	{
		/*check end of file*/
		if (line == EOF)
			free(buffer);
	
		/*first token to search local, exit and env*/
		token = strtok(buffer, " ");
		if (token != NULL)
		{
			/*command EXIT*/
			if (_strcmp(token, "exit"))
			{
				free(token);
				exit(EXIT_SUCCESS);
			}
			/*command ENV*/
			else if(_strcmp(token, "env"))
				print_env(token, envp);	
		}
		
		/*array of tokens*/
		commands = input_tokens(token);
		/*create fork*/
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
			free(buffer);
			free(token);
		}
		
		/*reset line_size adn buffer*/
		line_size = 0;
		buffer = NULL;
		printf("shellby~$");
	}
	return (0);
}
 
