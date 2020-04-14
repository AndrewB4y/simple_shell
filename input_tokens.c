#include "shellby.h"
/*#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>*/

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










