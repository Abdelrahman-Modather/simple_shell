#include "main.h"

/**
 * executeCommand - Executes a command.
 *
 * @programArguments: Pointer to an array of pointers to character values,
 * represents the arguments given to the main program.
 * @commandToken: Pointer to an array of pointers to character values,
 * represents the first command from the user input.
 * @commandLine: Pointer to a character value, represents the full line of command
 * that the user enters when prompted.
 * @messagePrompt: Pointer to a character value, represents the message that appears
 * for each prompt in the command line.
 *
 * Return: Nothing.
 */
void executeCommand(char **programArguments, char **commandToken, char *commandLine, char *messagePrompt)
{
	int processId, status;

	processId = fork();
	if (processId == 0)
	{
		if (*commandToken == NULL)
			exit(0);
		else if (commandToken[0][0] != '/')
		{
			if (handlePath(commandToken) == -1)
			{
				printf("In fork.c\n");
				perror(programArguments[0]);
				exit(127);
			}
			exit(0);
		}
		else if (execve(commandToken[0], commandToken, environ) == -1)
		{
			free(*commandToken);
			free(commandToken);
			free(commandLine);
			perror(programArguments[0]);
			exit(127);
		}
	}
	else if (processId > 0)
	{
		wait(&status);
		if (messagePrompt != NULL)
			write(1, messagePrompt, _strlen(messagePrompt));
	}
}

/**
 * forkShell - Decides to execute a command or not.
 *
 * @programArguments: Pointer to an array of pointers to strings,
 * represents the arguments passed to the main function.
 * @commandToken: Pointer to an array of pointers to strings,
 * represents the array of split tokens.
 * @messagePrompt: Pointer to a character value, represents the message of the prompt.
 * @commandLine: Pointer to a character value, represents the command line entry of the user.
 *
 * Return: Nothing.
 */
void forkShell(char **programArguments, char **commandToken, char *messagePrompt, char *commandLine)
{
	if (*commandToken == NULL)
		write(1, messagePrompt, _strlen(messagePrompt));
	else
	{
		if (_strcmp(commandToken[0], "exit") == 0)
		{
			free(*commandToken);
			free(commandToken);
			free(commandLine);
			terminateShell();
		}
		else if (_strcmp(commandToken[0], "env") == 0)
			printEnvironmentVariables(messagePrompt);
		else if (checkCommandValidity(commandToken[0]) == 0)
			executeCommand(programArguments, commandToken, commandLine, messagePrompt);
		else
		{
			perror(programArguments[0]);
			write(1, messagePrompt, _strlen(messagePrompt));
		}
	}
}
