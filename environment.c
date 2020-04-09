#include "shellby.h"
/**
 * env_out - frees the buffer and commands we created from the
 * getline function, prints the env, 
 * @token: pointer to first token
 * @env: environment variables from your login
 * Return: void
 */
void print_env(char *token, char **env)
{
	free(token);
	unsigned int  i, length;

	/*print env*/
	i = 0;
	while (environ[i])
	{
		/*env len*/
		length = _strlen(environ[i]);
		/*print env*/
		printf("%s",environ[i]);
		i++;
	}

}
