#include "main.h"

/**
 * splitString - Breaks a string into a set of tokens according to the delimiter
 * given and returns an array of these tokens.
 *
 * @inputString: Pointer to Character value, that holds the string to be split.
 * @delimiter: Pointer to a Constant Character value, that holds the delimiter
 * which the string is going to be split according to it.
 *
 * Return: Address of the two-dimensional array that holds the tokens (Success)
 *         NULL (Failure)
 */
char **splitString(char *inputString, const char *delimiter)
{
	int i, tokenCount = countTokens(inputString, delimiter);
	char *token = NULL;
	char *stringCopy = malloc(sizeof(char) * (_strlen(inputString) + 1));
	char **tokenArray = malloc(sizeof(char *) * tokenCount);

	if (stringCopy == NULL || tokenArray == NULL)
	{
		free(stringCopy);
		free(tokenArray);
		return (NULL);
	}

	_strcpy(stringCopy, inputString);
	token = strtok(stringCopy, delimiter);

	for (i = 0; token != NULL; i++)
	{
		tokenArray[i] = token;
		token = strtok(NULL, delimiter);
	}
	tokenArray[i] = NULL;
	return (tokenArray);
}

/**
 * countTokens - Counts the number of tokens in a string according to the
 * delimiters given.
 *
 * @inputString: Pointer to Character value, that represents the string that
 * contains the tokens.
 * @delimiter: Pointer to Constant Character value, that represents the delimiter
 * that the tokens are going to be counted according to.
 *
 * Return: Positive Number (Success)
 *         -1 (Failure)
 */
int countTokens(char *inputString, const char *delimiter)
{
	char *stringCopy, *token = NULL;
	int i;

	stringCopy = malloc(sizeof(char) * (_strlen(inputString) + 1));

	_strcpy(stringCopy, inputString);
	token = strtok(stringCopy, delimiter);

	/**
	 * Handling if the given string was NULL.
	 */
	if (token == NULL)
		return (0);
	else
	{
		/**
		 * Counting the number of tokens in the given string.
		 */
		for (i = 1; token != NULL; i++)
			token = strtok(NULL, delimiter);
	}
	free(token);
	free(stringCopy);
	return (i);
}
