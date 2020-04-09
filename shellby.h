#ifndef SHELLBY_H
#define SHELLBY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/*prompt*/
int inter_shellby(int argc, char *argv[], char *env[]);
int main(int argc, char *argv[], char *envp[]);
char **input_tokens(char *str);
void print_env(char *token, char **env);
/*aux funcitons*/
int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);


/* Structures and global variables */

extern char **environ;

/* Prototypes */
char *_getenv(const char *name);
//int _strcmp(const char *s1, const char *s2);
char **store_paths(char **envp);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif  /* _SHELLBY_H_ */
