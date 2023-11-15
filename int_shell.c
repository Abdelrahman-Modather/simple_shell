#include "main.h"

/**
 * interactiveShell - Displays a prompt and waits for the user to type a
 * command.
 *
 * @programArguments: Pointer to string array, that represents arguments given to the
 * program.
 *
 * Return: Nothing.
 */
void interactiveShell(char **programArguments)
{
	char **commandToken = NULL, *inputLine = NULL, *userPrompt = "#cisfun$ ";
	size_t bufferSize;
	ssize_t bytesRead;

	write(1, userPrompt, _strlen(userPrompt));

	while ((bytesRead = getline(&inputLine, &bufferSize, stdin)) != -1)
	{
		commandToken = splitString(inputLine, " \"\n");

		forkShell(programArguments, commandToken, userPrompt, inputLine);
	}

	if (bytesRead == -1)
		write(1, "\n", 1);

	if (commandToken != NULL)
	{
		free(*commandToken);
		free(commandToken);
	}
	free(inputLine);
}

/**
 * nonInteractiveShell - Gets a set of commands from the user and executes
 * them when the shell level is at 0.
 *
 * @programArguments: Pointer to an array of pointers to strings, which represents the
 * arguments given to the program.
 *
 * Return: Nothing.
 */
void nonInteractiveShell(char **programArguments)
{
	int i = 0;
	char **commandToken, *inputLine = NULL;
	size_t bufferSize;
	ssize_t bytesRead;

	while ((bytesRead = getline(&inputLine, &bufferSize, stdin)) != -1)
	{
		commandToken = splitString(inputLine, " \"\n");

		if (*commandToken == NULL)
			exit(0);
		else
		{
			if (_strcmp(commandToken[0], "exit") == 0)
				terminateShell();
			else if (_strcmp(commandToken[0], "env") == 0)
				printEnvironmentVariables(NULL);
			else if (checkCommandValidity(commandToken[0]) == 0)
			{
				executeCommand(programArguments, commandToken, inputLine, NULL);
			}
			else
			{
				perror(programArguments[0]);
				exit(127);
			}
		}

		for (i = 0; commandToken[i] != NULL; i++)
			free(commandToken[i]);

		free(commandToken);
		commandToken = NULL;
	}
	free(inputLine);
}
