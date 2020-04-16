#include "shellby.h"

/**
 * look_inPATH - looks in paths for a function to be valid.
 * @token: token to be looked in the PATH directories.
 *
 * Return: if token is found in PATH return a newly allocated
 *         string with PATH_found/token. NULL if not found.
 */

char *look_inPATH(char **token)
{
	int file_stat, i;
	struct stat file_info;
	char *full_path = NULL, *temp = NULL;
	char **paths = NULL;

	if (_strchr(*token, '/') != 0)
		return (NULL);
	paths = store_paths();
	if (paths == NULL)
		return (NULL);
	i = 0;
	while (paths[i] != NULL)
	{
		full_path = concat(paths[i], "/");

		temp = full_path;
		full_path = concat(full_path, *token);

		free(temp);
		file_stat = stat(full_path, &file_info);
		if (file_stat == 0)
			break;

		free(full_path);
		i++;
	}
	if (paths[i] == NULL)
	{
		free(paths[0] - 5);
		free(paths);
		return (NULL);
	}
	*token = full_path;
	free(paths[0] - 5);
	free(paths);
	return (full_path);
}
