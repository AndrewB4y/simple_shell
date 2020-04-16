#include "shellby.h"
/**
 * free_all - function that frees allocated memory
 * @buffer: buffer
 * @commands: commands
 * @heap_token: heap_token
*/

void free_all(char *buffer, char **commands, char *heap_token)
{
	if (buffer != NULL)
	{
		free(buffer);
		buffer = NULL;
	}
	if (commands != NULL)
	{
		free(commands);
		commands = NULL;
	}
	if (heap_token != NULL)
	{
		free(heap_token);
		heap_token = NULL;
	}
}
