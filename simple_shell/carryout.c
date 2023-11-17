#include "main.h"

/**
 * execmd - Executes a command.
 *
 * @argv: Pointer to an array of pointers to character values representing
 *        the command and its arguments.
 *
 * Return: Nothing.
 */

void execmd(char **argv)
{
	char *cmd = NULL, *usertcmd = NULL;

	if (argv)
	{
		cmd = argv[0];
		usertcmd = findit(cmd);

		if (execve(usertcmd, argv, NULL) == -1)
		{
			perror("something went wrong:");
		}
	}

}
