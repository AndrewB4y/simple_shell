#include "shellby.h"
/**
 * input_tokens - creates a array taht hold ponters to each token and allocates them
 * @str: the command from the terminal buffer
 * Return: array of pointer with tokens
**/

char **input_tokens(char *str)
{
         char **commands;
          char *token;
          int i = 1, j;
  
       /*   if (argc < 2)
             return (0);
          buffer=  argv[1];*/
          printf("text %s\n", str);
          token = strtok(str, " \n"); // git\0push origin master
          commands = malloc(sizeof(char *));
          if (commands == NULL)
                  return (NULL);
  
         printf("commands%s\n",token);
          while(commands != NULL)
          {
                  commands = _realloc(commands, sizeof(char *), sizeof(char *) * i);
                  for (j = 0 ; token[j] != '\0' ; j++)
                  {
                          commands[i] = malloc(sizeof(_strlen(token[j])));
                          printf("token = %s\n",commands[i]);
                  }   
                      
                  i++;
          }
  
          free(token);
          free(commands);
          token = strtok(NULL, " \n");
  }
