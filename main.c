#include "main.h"

/**
 * runShell - Runs the shell.
 *
 * @argumentCount: Integer value, represents the number of arguments given to the
 * program.
 *
 * @argumentValues: Pointer to an array of character values, represents the arguments
 * given to the program.
 *
 * Return: 0 (Success).
 */
int runShell(__attribute__((unused)) int argumentCount, char **argumentValues)
{
	int terminalStatus = isatty(0);

	if (terminalStatus != 1)
	{
		nonInteractiveShell(argumentValues);
	}
	else
	{
		interactiveShell(argumentValues);
	}
	return (0);
}
