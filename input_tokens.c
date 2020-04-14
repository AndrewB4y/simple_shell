#include "shellby.h"

/**
 * input_tokens - finds and allocates tokens in a buffer.
 * @token: first token to be allocated.
 * @buffer: buffer to continue the tokenize.
 *
 * Return: address of allocated pointers, NULL if fails.
 */

char **input_tokens(char *token, char *buffer)
{
	char **cmnds = NULL;
	size_t c_size = 0;
	int i = 0, last = 0;

	cmnds = _realloc(cmnds, c_size, c_size + sizeof(char *));
	if (cmnds == NULL)
	{
		free(cmnds);
		return (NULL);
	}
	c_size += sizeof(char *);
	cmnds[i++] = token;
	last = _strlen(buffer) + 1;
	token = strtok(buffer + last, " \n\t\r");
	while (token != NULL)
	{
		printf("Token %d: %s\n", i, token);
		cmnds = _realloc(cmnds, c_size, c_size + sizeof(char *));
		if (cmnds == NULL)
		{
			free(cmnds);
			return (NULL);
		}
		c_size += sizeof(char *);
		cmnds[i] = token;
		token = strtok(NULL, " \n\t\r");
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
