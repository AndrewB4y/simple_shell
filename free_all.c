#include "shellby.h"
/**
 * free_all - function that frees allocated memory
 * @buffer: buffer
 * @commands: commands
 * @heap_token: heap_token
*/

void free_all(char *buffer, char **commands, char *heap_token)
{
	free(buffer);
	free(commands);
	free(heap_token);
}
