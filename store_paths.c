#include "shellby.h"

/**
 * store_paths - looks for PATH in env and returns a newly allocated
 *               array of strings with all the directories in PATH.
 * Return: newly allocated array of strings with all the directories in PATH.
 */

char **store_paths(void)
{
	int i = 0;
	char *token = NULL, *path_c = NULL;
	char **paths = NULL;
	size_t path_sz = 0;

	i = 0;
	while (environ[i] != NULL)
	{
		if (_strncmp((const char *)environ[i], "PATH=", 5) == 0)
			break;
		i++;
	}
	if (environ[i] == NULL)
		return (NULL);

	path_c = malloc(_strlen(environ[i]));
	if (path_c == NULL)
		return (NULL);
	path_c = _strcpy(path_c, environ[i]);
	token = strtok(path_c, "=");
	i = 0;
	token = strtok(NULL, ":\n");
	while (token != NULL)
	{
		paths = _realloc(paths, path_sz, path_sz + sizeof(char *));
		if (paths == NULL)
		{
			free(path_c);
			return (NULL);
		}
		path_sz += sizeof(char *);
		paths[i] = token;
		token = strtok(NULL, ":\n");
		i++;
	}
	paths = _realloc(paths, path_sz, path_sz + sizeof(char *));
	if (paths == NULL)
	{
		free(path_c);
		return (NULL);
	}
	path_sz += sizeof(char *);
	paths[i] = NULL;
	return (paths);
}
