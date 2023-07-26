#include "main.h"

/**
 * get_path - searches directories in PATH for cmd's executable file
 * @cmd: command whose executable file to look for in PATH
 * Return: path on sucess or NULL if not found
 */
char *get_path(char *cmd)
{
	char *path = _getenv("PATH"), *p, *p2 = NULL, *path_buffer;
	struct stat st;

	p2 = malloc(_strlen(path) + 1);
	if (p2 == NULL)
	{
		perror("Error: unable to allocate memory");
		return (NULL);
	}
	_strcpy(p2, path);
	p = _strtok(p2, ":");
	free(p2);
	while (p != NULL)
	{
		path_buffer = malloc((_strlen(p) + _strlen(cmd) + 2) * sizeof(char));
		if (path_buffer == NULL)
		{
			perror("Error: unable to allocate memory");
			return (NULL);
		}
		_strcpy(path_buffer, p);
		_strcat(path_buffer, "/");
		_strcat(path_buffer, cmd);
		if (stat(path_buffer, &st) == 0 && S_ISREG(st.st_mode))
		{
			char *result = malloc(_strlen(path_buffer) + 1);

			if (result == NULL)
			{
				free(path_buffer);
				return (NULL);
			}
			_strcpy(result, path_buffer);
			free(path_buffer);
			return (result);
			free(result);
		}
		p = _strtok(NULL, ":");
	}
	perror("Error: Command not found");
	return (NULL);
}
