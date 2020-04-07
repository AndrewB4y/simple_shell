#include "shellby.h"

/**
 * _strcmp - compares two strings
 * @s1: pointer to first string to be compared
 * @s2: pointer to second string to be compared
 *
 * Return: integer difference between the first different char
 */

int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] != '\0' || s2[i] != '\0')
		return (s1[i] - s2[i]);

	return (0);
}
