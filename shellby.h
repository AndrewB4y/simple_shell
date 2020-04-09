#ifndef _SHELLBY_H_
#define _SHELLBY_H_

/* Libraries */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Structures and global variables */

extern char **environ;

/* Prototypes */
int main(int argc, char *argv[], char *envp[]);

/*prompt*/
int inter_shellby(char *paths[], char *envp[]);
char **input_tokens(char *str);
void print_env(char *token, char **env);
/*aux funcitons*/
int _strcmp(const char *s1,const  char *s2);
unsigned int _strlen(const char *s);
char *_strncpy(char *dest, char *src, int n);

char *_getenv(const char *name);

/*store paths*/
char **store_paths(char **envp);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *concat(const char *str1, const char *str2);

/*non_inter_shellby*/
int non_inter_shellby(char *paths[], int argc, char *argv[], char *envp[]);
void free_str_arr(char **arr);

/* look in PATH */
char *look_inPATH(char **token, char **paths);


#endif  /* _SHELLBY_H_ */
