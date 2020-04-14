#include "shellby.h"
/**
 * input_tokens - creates a array taht hold ponters to each token and allocates them
 * @str: the command from the terminal buffer
 * Return: array of pointer with tokens
**/

char **input_tokens(char *str)
{
         /* if (argc < 2)
             return (0);
         token = argv[1];*/
         printf("%s",str);
         char **cmnds = NULL;
         size_t c_size = 0;
         int i = 0;
         unsigned int token_len = 0;
 
         token_len = _strlen(str);
 
         while (str != NULL)
         {
                 cmnds = _realloc(cmnds, c_size, c_size + sizeof(char *));
                 if (cmnds == NULL)
                         return (NULL);
                 c_size += sizeof(char *);
                 cmnds[i] = malloc(token_len);
                 cmnds[i] = _strcpy(cmnds[i], str);
                 str = strtok(NULL, " \n\t\r");
                 printf("%s",str);
                 i++;
         }
         cmnds = _realloc(cmnds, c_size, c_size + sizeof(char *));
         if (cmnds == NULL)
                 return (NULL);
         c_size += sizeof(char *);
         cmnds[i] = NULL;
         return (cmnds);
}
