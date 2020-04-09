#include "shellby.h"

int main(int argc, char *argv[], char *envp[])
{
	inter_shellby(argc, argv, envp);
	char **str =  "git push origin master";
	char **commands;
	commands = input_tokens(str);
	
}

