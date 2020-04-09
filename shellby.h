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
char *_getenv(const char *name);
int _strcmp(const char *s1, const char *s2);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strlen(const char *s);
char *concat(const char *str1, const char *str2);

char **store_paths(char **envp);
int inter_shellby(char *paths[], char *envp[]);
int non_inter_shellby(char *paths[], int argc, char *argv[], char *envp[]);
void free_str_arr(char **arr);
char *look_inPATH(char **token, char **paths);


#endif  /* _SHELLBY_H_ */
