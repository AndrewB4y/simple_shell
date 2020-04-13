#include "shellby.h"

/**
 * _strncmp - compares two strings up to n bytes.
 * @s1: pointer to first string to be compared on its first n bytes.
 * @s2: pointer to second string to be compared on its first n bytes.
 * @n: number of bytes to be compared.
 *
 * Return: difference between the first different char, 0 if equal.
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == n)
		return (0);

	if (s1[i] != '\0' || s2[i] != '\0')
		return (s1[i] - s2[i]);

	return (0);
}
