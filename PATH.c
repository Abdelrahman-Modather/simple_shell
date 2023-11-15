#include "main.h"

/**
 * handlePath - Searches for the right path of the first command given by
 * the user in the prompt and executes it (with respect to arguments provided if
 * any) once the command is found.
 *
 * @commandTokens: Pointer to an array of pointers to character values, which
 * represents the set of arguments beside the command.
 *
 * Return: 0 (Success)
 *         -1 (FAILURE).
 */
int handlePath(char **commandTokens)
{
	char *currentDirectory, *pathValue = getEnvironmentVariable("PATH");
	char **pathDirectories;
	int commandLength, directoryLength, i = 0;
	struct stat buffer;

	pathValue = strtok(pathValue, "=");
	pathDirectories = splitString(pathValue, ":");
	commandLength = _strlen(commandTokens[0]) + 2;

	while (pathDirectories[i] != NULL)
	{

		directoryLength = _strlen(pathDirectories[i]) + commandLength;
		currentDirectory = malloc(sizeof(char) * directoryLength);

		_strcpy(currentDirectory, pathDirectories[i]);
		currentDirectory = _strcat(currentDirectory, "/");
		currentDirectory = _strcat(currentDirectory, commandTokens[0]);

		if (stat(currentDirectory, &buffer) == 0)
		{
			execve(currentDirectory, commandTokens, environ);
			free(currentDirectory);
			return (0);
		}
		free(currentDirectory);
		i++;
	}
	free(*pathDirectories);
	free(pathDirectories);
	return (-1);
}

/**
 * findPath - Tells you if the command is valid or not.
 *
 * @commandName: Pointer to Character value, represents the name of the command.
 *
 * Return: 0 (FOUND)
 *         -1 (NOT FOUND)
 */
int findPath(char *commandName)
{
	char *currentDirectory, *pathValue = getEnvironmentVariable("PATH");
	char **pathDirectories;
	int commandLength, directoryLength, i = 0;
	struct stat buffer;

	pathValue = strtok(pathValue, "=");
	pathDirectories = splitString(pathValue, ":");
	commandLength = _strlen(commandName) + 2;

	while (pathDirectories[i] != NULL)
	{

		directoryLength = _strlen(pathDirectories[i]) + commandLength;
		currentDirectory = malloc(sizeof(char) * directoryLength);

		if (currentDirectory == NULL)
			return (-1);

		_strcpy(currentDirectory, pathDirectories[i]);
		currentDirectory = _strcat(currentDirectory, "/");
		currentDirectory = _strcat(currentDirectory, commandName);

		if (stat(currentDirectory, &buffer) == 0)
		{
			free(currentDirectory);
			return (0);
		}
		free(currentDirectory);
		i++;
	}
	free(*pathDirectories);
	free(pathDirectories);
	return (-1);
}
