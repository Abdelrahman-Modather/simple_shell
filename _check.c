#include "main.h"

/**
 * checkCommandValidity - Checks if a command is valid or not.
 *
 * @cmd: Pointer to a character array representing the command.
 *
 * Return: 0 (VALID)
 *         -1 (NOT VALID).
 */
int checkCommandValidity(char *cmd)
{
	struct stat fileInfo;

	/**
	 * Checking if the given command is NULL or NOT.
	 */
	if (cmd == NULL)
		return (-1);

	/**
	 * Checking if the given command is a directory or NOT.
	 */
	if (cmd[0] == '/')
	{
		/**
		 * If the directory was found, it returns 0.
		 * If the directory wasn't found, it returns -1.
		 */
		return (stat(cmd, &fileInfo));
	}
	else
	{
		/**
		 * The command is not a directory ...
		 * If the command was found, it returns 0.
		 * If the command wasn't found, it returns -1.
		 */
		return (findPath(cmd));
	}
}
