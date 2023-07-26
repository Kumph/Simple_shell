#include "main.h"

/**
 * signal_handler - handles signals
 * @i: signal number
 */

void signal_handler(int i)
{
	(void)i;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "s_shell$ ", 9);
}
