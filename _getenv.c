#include "main.h"

/**
 * getEnvironmentVariable - Gets the given environment variable from the set of
 * environment variables.
 *
 * @variableName: Pointer to a character value, which represents the
 * name of the environment variable to be searched for.
 *
 * Return: Address of the environment variable value.
 *         NULL if the environment variable is not found.
 */
char *getEnvironmentVariable(char *variableName)
{
	int index, variableNameLength = _strlen(variableName) + 1;
	char *token, *envVar = malloc(sizeof(char) * variableNameLength);

	if (variableName == NULL)
	{
		free(envVar);
		return (NULL);
	}

	_strcpy(envVar, variableName);

	for (index = 0; environ[index] != NULL; index++)
	{
		token = strtok(environ[index], "=");

		if (_strcmp(token, envVar) == 0)
		{
			token = strtok(NULL, "=");
			free(envVar);
			return (&environ[index][variableNameLength]);
		}
	}
	free(envVar);
	return (NULL);
}
