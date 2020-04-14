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

/*prompt*/
int inter_shellby(void);
char **input_tokens(char *token);
void print_env(char *token, char **env);
/*aux functions*/
int _strcmp(const char *s1, const  char *s2);
int _strncmp(const char *s1, const  char *s2, size_t n);
unsigned int _strlen(const char *s);
char *_strcpy(char *dest, char *src);

/*store paths*/
char **store_paths(void);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *concat(const char *str1, const char *str2);

/*non_inter_shellby*/
int non_inter_shellby(int argc, char *argv[]);
int non_inter_piped(void);
void free_str_arr(char **arr);

/* look in PATH */
char *look_inPATH(char **token);


#endif  /* _SHELLBY_H_ */
