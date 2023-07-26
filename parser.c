
#include "main.h"

/**
 * parse_input - parses input by calling strtok then assigning toks to argv
 * @input: user input
 * @args: variable to which we will store tokens as input args
 */
void parse_input(char *input, char ***args)
{
	int token_count = 0, inputlen = 0, i;
	char *token;
	char *input_copy;
	char *delim;

	inputlen = _strlen(input);
	input_copy = malloc(sizeof(char) * (inputlen + 1));
	if (input_copy == NULL)
	{
		perror("Error");
		free(input_copy);
		exit(1);
	}

	_strcpy(input_copy, input);

	delim = " ";

	token = _strtok(input, delim);

	while (token)
	{
		token = _strtok(NULL, delim);
		token_count++;
	}

	*args = malloc(sizeof(char *) * (token_count + 1));

	token = _strtok(input_copy, delim);

	for (i = 0; token != NULL; i++)
	{
		(*args)[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		_strcpy((*args)[i], token);
		token = _strtok(NULL, delim);
	}
	(*args)[i] = NULL;
	free(input_copy);
}
