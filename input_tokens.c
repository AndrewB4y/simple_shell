 //#include "shellby.h"
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 #include <sys/types.h>
 
 
 char **input_tokens(char *token);
 unsigned int _strlen(char *s);
 void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
 char *_strcpy(char *dest, char *src);
 
 int main(void)
  {
          size_t line_size  = 0;
          char *buffer = NULL, *token = NULL, **commands, *str;
          ssize_t line = 0;
          int i;
 
          printf("shellby~$");
          while((line = getline(&buffer, &line_size, stdin)))
          {
                  token = strtok(buffer, " ");
                  if (token == NULL)
                          free(token);
                  printf("el token es:%s\n",token);
                  commands = input_tokens(token);
                  if (commands == NULL)
                  {
                          return (0);
                          free(commands);
                          free(token);
                  }
                  printf("command:");
                  for (i = 0; commands[i] != NULL ;i++)
                  {
                         printf("%s", commands[i]);
                         printf(" ");
 
                  }
 
          }
  }
 
 
 char **input_tokens(char *token)
 {
 
         char **cmnds = NULL;
         size_t c_size = 0;
         int i = 0;
         unsigned int token_len = 0;
 
         token_len = _strlen(token);
 
         while (token != NULL)
         {
                 cmnds = _realloc(cmnds, c_size, c_size + sizeof(char *));
                 if (cmnds == NULL)
                 {
                         return (0);
                         free(cmnds);
                 }
                 c_size += sizeof(char *);
                 cmnds[i] = malloc(token_len);
                 cmnds[i] = _strcpy(cmnds[i], token);
                 token = strtok(NULL, " \n\t\r");
                 printf("next token:%s\n",token);
                 i++;
         }
         cmnds = _realloc(cmnds, c_size, c_size + sizeof(char *));
         if (cmnds == NULL)
         {       return (NULL);
                 free(cmnds);
         }
         c_size += sizeof(char *);
         //cmnds[i] = NULL;
         return (cmnds);
         free(cmnds);
         free(token);
 }
 
 
 
 
 unsigned int _strlen(char *s)
 {
         unsigned int counter = 0;
 
         while (s[counter] != '\0')
                 ++counter;
 
         return (counter);
 }
 
 
 
 char *_strcpy(char *dest, char *src)
 {
         int i = 0;

        while (*(src + i) != '\0')
        {
               *(dest + i) = *(src + i);
                ++i;
        }
        *(dest + i) = *(src + i);
 
        return (dest);
}



void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
        char *nptr = NULL;
        char *optr = ptr;
        unsigned int i;

        if (old_size == new_size)
                return (optr);

        if (optr == NULL)
                return (malloc(new_size));

        if (new_size == 0)
        {
                free(optr);
		}
}
