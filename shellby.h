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
/*aux funcitons*/
int _strcmp(char *s1, char *s2);

#endif /*SHELLBY_H*/
