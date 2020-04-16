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
#include <errno.h>

/* Structures and global variables */

extern char **environ;

/* Prototypes */

/*prompt*/
int inter_shellby(void);
char **input_tokens(char *token, char *buffer);
void print_env();
int process_line(char **buffer, size_t *line_size, int *count);

/*aux functions*/
int _strcmp(const char *s1, const  char *s2);
int _strncmp(const char *s1, const  char *s2, size_t n);
unsigned int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
void free_all(char *buffer, char **commands, char *heap_token);
int check_built_ins(char *buffer, char *token);

/*store paths*/
char **store_paths(void);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *concat(const char *str1, const char *str2);

/*non_inter_shellby*/
int non_inter_shellby(int argc, char *argv[]);
int non_inter_piped(char *argv);
void child_exe(char **cmnds, char *argv, int count);
void print_number(int n);

/* look in PATH */
char *look_inPATH(char **token);
char *_strchr(char *s, char c);


#endif  /* _SHELLBY_H_ */
