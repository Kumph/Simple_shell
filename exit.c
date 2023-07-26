#include "main.h"

/**
 * handle_exit - handles exit status
 * @input: parameter
 */
void handle_exit(char *input)
{
	int exit_status;
	char *exit_status_arg = _strtok(input, " ");

	exit_status_arg = _strtok(NULL, " ");
	exit_status = 0;
	if (exit_status_arg != NULL)
		exit_status = _atoi(exit_status_arg);
	exit(exit_status);
}
