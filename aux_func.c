#include "shellby.h"  
/**
 * _strcmp - compares two strings for equality
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 if equal, 0 if not equal
 */
int _strcmp(const char *s1, const char *s2)

{
	unsigned int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		++i;
	}

	return (1);
}

/**
 * _strlen - finds the length of a string
 * @s: string to find the length 
 * Return: unsigned int length of the string
 */
unsigned int _strlen(const char *s)
{
	unsigned int counter = 0;

	while (s[counter] != '\0')
		++counter;

	return (counter);
}


/**
 * _strcpy - copies the string pointed to by src into dest
 * @dest: destination of the copy
 */
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
