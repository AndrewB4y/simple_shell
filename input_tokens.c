
//#include "shellby.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>


void free_all_double_ptr(char **d_ptr);
int _strcmp(const char *s1, const char *s2);
void free_str_arr(char **arr);
char **input_tokens(char *token);
unsigned int _strlen(const char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strcpy(char *dest, char *src);

int main(void)
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
/*		pid = fork();
		if (pid == -1)
			perror("Error");
		if(pid == 0)
		{
		
		}
*/

		free(commands);
		fee(buffer);
		line_size = 0;
		buffer = NULL;
		printf("shellby~$");
	 }
}


char **input_tokens(char *token)
{
	
	char **cmnds = NULL;
	size_t c_size = 0;
	int i = 0;
	
	if(token == NULL)
		free(token);
	while (token != NULL)
	{
		cmnds = _realloc(cmnds, c_size, c_size + sizeof(char *));
		if (cmnds == NULL)
		{
			return (0);
			free(cmnds);
		}
		
		c_size += sizeof(char *);
		cmnds[i] = token;	
		token = strtok(NULL, " \n\t\r");
		printf("next token:%s\n",token);
		i++;
	}

	cmnds = _realloc(cmnds, c_size, c_size + sizeof(char *));
	if (cmnds == NULL)
	{	free(cmnds);
		return (NULL);
		
	}
	c_size += sizeof(char *);
	cmnds[i] = NULL;
	
	return (cmnds);
}




unsigned int _strlen(const char *s)
{
	unsigned int counter = 0;

	while (s[counter] != '\0')
		++counter;
	return (counter);
}



char *_strcpy(char *dest,  char *src)
{
	int i = 0;

	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		++i;
	}
	*(dest + i) = *(src + i);
	return (dest);
}



void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *nptr = NULL;
	char *optr = ptr;
	unsigned int i;

	if (old_size == new_size)
		return (optr);

	if (optr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(optr);
		return (NULL);
	}

	nptr = malloc(new_size);
	if (nptr == NULL)
		return (NULL);

	for (i = 0; i < old_size && i < new_size; i++)
		nptr[i] = optr[i];

	free(optr);
	return (nptr);
}


void free_str_arr(char **arr)
  {
          int i;
 
          if (arr == NULL)
                  return;
 
          if (*arr == NULL)
                  return;
 
          i = 0;
          while (arr[i] != NULL)
          {
                  free(arr[i]);
                  i++;
          }
          free(arr);
  }



int _strcmp(const char *s1, const char *s2)

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


void free_all_double_ptr(char **d_ptr)
{
	unsigned int i = 0;

	if (d_ptr == NULL)
		return;

	while (d_ptr[i])
	{
		free(d_ptr[i]);
		++i;
	}

	if (d_ptr[i] == NULL)
		free(d_ptr[i]);

	free(d_ptr);
}
