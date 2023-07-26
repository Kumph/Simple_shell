#include "main.h"
/**
 * _getenv - custom getenv
 * @name: parameter
 * Return: NULL
 */
char *_getenv(const char *name)
{
	size_t length = _strlen(name);
	char **env = environ;

	if (name == NULL)
	{
		return (NULL);
	}

	while (*env != NULL)
	{
		if (_strcmp(name, *env) == 0 && (*env)[length] == '=')
		{
			return (*env + length + 1);
		}
		env++;
	}
	return (NULL);
}
