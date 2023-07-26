#include "main.h"
/**
 * builtin_cd - builtin_cd
 * @dir: parametr
 * Return: 0
 */
int builtin_cd(char *dir)
{
	char cwd[1024];

	if (dir == NULL)
	{
		dir = _getenv("HOME");
		if (dir == NULL)
		{
			write(STDERR_FILENO, "cd: No home directory found\n", 27);
			return (1);
		}
	}
	else if (_strcmp(dir, "-") == 0)
	{
		dir = _getenv("OLDPWD");
		if (dir == NULL)
		{
			write(STDERR_FILENO, "cd: No previous directory found\n", 31);
			return (1);
		}
		write(STDOUT_FILENO, dir, _strlen(dir));
		write(STDOUT_FILENO, "\n", 1);
		return (0);
	}
	if (chdir(dir) != 0)
	{
		perror("cd");
		return (1);
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		setenv("PWD", cwd, 1);
	}
	else
	{
		perror("cd");
		return (1);
	}
	return (0);
}
