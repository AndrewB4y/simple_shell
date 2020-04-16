#include "shellby.h"

/**
 * _strchr - function that locates a character in a string
 * @s: pointer to string
 * @c: character to be found
 *
 * Return: pointer to the 1st occurrence of c in s. Null if not found.
 */

char *_strchr(char *s, char c)
{
	for (; *s != '\0'; s++)
	{
		if (*s == c)
			return (s);
	}
	if (*s == c)
		return (s);

	return (NULL);
}
