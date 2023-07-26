#include "main.h"

/**
 * main - Simple unix commandline intepreter
 * @argc: arguments count
 * @argv: array of arguments
 * Return: 0
 */
int main(int __attribute__ ((unused)) argc, char **argv)
{
	char *input = NULL;
	ssize_t chars_read;
	size_t n = 0;
	int i = 0;

	signal(SIGINT, signal_handler);
	while (1)
	{
		print_prompt();
		chars_read = getline(&input, &n, stdin);
		if (chars_read == -1)
		{
			free(input);
			input = NULL;
			exit(0);
		}
		if (_strcmp(input, "exit") == 0)
		{
			free(input);
			exit(232);
		}
		if (_strcmp(input, "env") == 0)
		{
			for (i = 0; environ[i] != NULL; i++)
			{
				write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
				write(STDOUT_FILENO, "\n", 1);
			}
			free(environ[i]);
			environ = NULL;
		}
		input[_strlen(input) - 1] = '\0';
		parse_input(input, &argv);
		if (argv[0] != NULL)
			execute_command(argv);
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
		free(argv);
	}
	return (0);
}
