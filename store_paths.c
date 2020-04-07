#include "shellby.h"

/**
 * store_paths - looks for PATH in env and returns a newly allocated
 *               array of strings with all the directories in PATH.
 * @env: array of strings holding all the environment variables.
 *
 * Return: newly allocated array of strings with all the directories in PATH.
 */

char **store_paths(char **envp)
{
	int i = 0;
	char *token = NULL;
	char **paths = NULL, **envp_c = NULL;
	size_t path_sz = 0;

	envp_c = envp;
	if (envp_c == NULL)
		return (NULL);
	if (*envp_c == NULL)
		return (NULL);
	while (envp_c[i] != NULL)
	{
		token = strtok(envp_c[i], "=");
		if (_strcmp((const char *)token, "PATH") == 0)
			break;
		i++;
	}
	if (envp_c[i] == NULL)
		return (NULL);
	i = 0;
	token = strtok(NULL, ":\n");
	while (token != NULL)
	{
		paths = _realloc(paths, path_sz, path_sz + sizeof(char *));
		path_sz += sizeof(char *);
		paths[i] = token;
		token = strtok(NULL, ":\n");
		i++;
	}
	paths = _realloc(paths, path_sz, path_sz + sizeof(char *));
	path_sz += sizeof(char *);
	paths[i] = NULL;
	return (paths);
}
