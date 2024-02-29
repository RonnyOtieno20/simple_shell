
#include "hsh.h"

/**
 * shell_loop - Main loop for the shell
 *
 * Description: Displays prompt and waits for user input.
 * Parses the input and executes commands.
 */
void shell_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("#cisfun$ ");
		line = read_input();
		args = parse_input(line);
		status = execute_command(args);

		free(line);
		free(args);
	} while (status);
}
