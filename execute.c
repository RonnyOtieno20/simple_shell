
#include "hsh.h"

/**
 * execute_command - Executes the command provided by the user
 * @args: Null-terminated list of arguments (including command)
 *
 * Return: 1 if the shell should continue running, 0 to terminate
 */

int execute_command(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
	{
		/* An empty command was entered */
		return (1);
	}

	if (strcmp(args[0], "exit") == 0)
	{
		/* Handle the "exit" command */
		return (0); /* Signal to terminate the shell loop */
	}

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execve(args[0], args, NULL) == -1)
		{
			perror("hsh");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		/* Error forking */
		perror("hsh");
	}
	else
	{
		/* Parent process */
		waitpid(pid, &status, WUNTRACED);
	}

	return (1);
}
