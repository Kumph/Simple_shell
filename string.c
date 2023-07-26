#include "main.h"
/**
 * _strlen - Returns the length of a string.
 * @s: The string to get the length of.
 *
 * Return: The length of @str.
 */
int _strlen(const char *s)
{
	int length = 0;

	while (s[length] != '\0')
	{
		length++;
	}

	return (length);
}

/**
 * _strcpy - copies string pointed to by src including \0 to dest
 * @dest: destination of copied string
 * @src: source of string to be copied
 * Return: char
 */
char *_strcpy(char *dest, char *src)
{
	char *begn = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (begn);
}

/**
 * _strcat - function that concatenates two strings
 * @dest: destination of copied
 * @src: source of copied string
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int b, i;

	b = 0;
	i = 0;

	while (dest[b] != '\0')
	{
		b++;
	}


	while (src[i] != '\0')
	{
		dest[b] = src[i];
		b++;
		i++;
	}
	dest[b] = '\0';
	return (dest);
}

/**
 * _strcmp - compare two strings
 * @s1: string to compare to s2
 * @s2: string to concate to s1
 * Return: Same 0, Different s1 - s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 - *s2 != 0)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (0);
}
