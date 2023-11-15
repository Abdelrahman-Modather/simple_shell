#include "main.h"

/**
 * printEnvironmentVariables - Prints all the environment variables of a shell.
 *
 * @customPrompt: Pointer to a character value, represents the custom prompt message.
 *
 * Return: Nothing.
 */

void printEnvironmentVariables(char *customPrompt)
{
	int index = 0;
	char *variableValue;

	for (index = 0; environ[index] != NULL; index++)
	{
		variableValue = getEnvironmentVariable(environ[index]);
		if (variableValue == NULL)
			variableValue = "";

		write(1, environ[index], _strlen(environ[index]));
		write(1, "=", 1);
		write(1, variableValue, _strlen(variableValue));
		write(1, "\n", 1);
	}

	if (customPrompt != NULL)
		write(1, customPrompt, _strlen(customPrompt));
}
