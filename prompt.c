#include "shellby.h"

/**
* inter_shellby - intercactve shell
*
* Return: 0 on success.
*/

int inter_shellby(void)
{
	size_t line_size  = 0;
	ssize_t line = 0;
	char *buffer = NULL;
	int error = 0, count = 1;

	write(STDOUT_FILENO, "shellby~$ ", 10);
	while ((line = getline(&buffer, &line_size, stdin)))
	{
		if (line == EOF)/*check end of file*/
		{
			free(buffer);
			write(STDOUT_FILENO, "\n", 1);
			exit(0);
		}
		if (*buffer == '\n')
		{
			write(STDOUT_FILENO, "shellby~$ ", 10);
			count++;
			continue;
		}

		error = process_line(&buffer, &line_size, &count);
	}
	return (error);
}

/**
 * process_line - interpretates line obtained by getline.
 * @buffer: double pointer to the buffer obtained from getline.
 * @line_size: pointer to the size of the buffer.
 * @count: count of the number of lines executed in the shellby.
 *
 * Return: error status which should be 0 if everything went ok.
 */

int process_line(char **buffer, size_t *line_size, int *count)
{
	char *token = NULL, **commands = NULL;
	char *token_o = NULL, *heap_token = NULL;
	int  status, error = 0;
	pid_t child_pid;

	token = strtok(*buffer, " \n\t\r");
	if (token != NULL)
	{
		token_o = token;
		heap_token = look_inPATH(&token);
		commands = input_tokens(token, *buffer);
		if (commands == NULL)
			return (0);
		if ((_strcmp("exit", commands[0])) == 0)
		{
			free_all(*buffer, commands, NULL);
			exit(0);
		}
		child_pid = fork();
		if (child_pid == 0)
		{
			child_exe(commands, token_o, *count);
		}
		else if (child_pid == -1)
		{
			perror("Error");
			exit(1);
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				error = WEXITSTATUS(status);
		}
		free_all(*buffer, commands, heap_token);
		*line_size = 0;
		*buffer = NULL;
	}
	(*count)++;
	write(STDOUT_FILENO, "shellby~$ ", 10);

	return (error);
}
