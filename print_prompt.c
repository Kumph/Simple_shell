#include "main.h"
/**
 * print_prompt - prints the prompt to the terminal
 */
void print_prompt(void)
{
	char *prompt = "S_shell$ ";
	int prompt_len = 9;

	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;

	if (flags.interactive)
	{
		write(STDOUT_FILENO, prompt, prompt_len);
	}
	fflush(stdout);
}
