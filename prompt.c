#include "shellby.h"
#include "unistd.h"

int inter_shellby(int argc, char *argv[], char *env[])
{
	size_t line_size  = 0;
	char *buffer = NULL, *token = NULL;
	ssize_t line = 0;
	pid_t pid;
	int status;


	printf("shellby~$");
	/*loop that reads a line always*/
	while((line = getline(&buffer, &line_size, stdin)))
	{
		/*check end of file*/
		if (line == EOF)
			free(buffer);
		/* comands from prompt*/
		token = strtok(buffer, " ");
		
		/*create fork*/
		pid = fork();
		if (pid == -1)
			perror("Error:");
		if (pid == 0)
		{
			printf("forked succes pid = 0\n");
			/*commands NULL*/
			if (token == NULL)
				free(buffer);
			/*command EXIT*/
			else if (_strcmp(token, "exit"))
				free(token);
			/*command ENV*/
			else if(_strcmp(token, "env"))
				free(token);
				/*execv*/
			else
			execve(token,token, NULL);

		}
		/*everything free*/
		else
		{
			printf("forked pid not 0");
			/*wait for the child procces to finish*/
			wait(&status);
			if (token == NULL)
			{
				free(buffer);
				free(token);
			}
			else if (_strcmp(token, "exit"))
			{
				free(buffer);
				free(token);
			}
			else
			{
				free(buffer);
				free(token);
			}
		}
		/*reset line_size adn buffer*/
		line_size = 0;
		buffer = NULL;
		printf("shellby~$");
	}
	return (0);
}


/**
 * input_tokens - creates a array taht hold ponters to each token and allocates them
 * @str: the command from the terminal buffer
 * Return: array of pointer with tokens
 * */

char **input_tokens(char *str)
{
	char **argv;
	char argc;

}

/**
 * _strcmp - compares two strings for equality
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 if equal, 0 if not equal
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		++i;
	}

	return (1);
}
