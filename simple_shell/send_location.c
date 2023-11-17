#include "main.h"

/**
 * findit - Finds the full path of a command in the specified directories.
 *
 * @cmd: Pointer to a character array representing the command.
 *
 * Return: Pointer to the full path of the command (Success)
 *         NULL if the command is not found.
 */
char *findit(char *cmd)
{
char *daway, *daway_nsk, *daway_tkn, *file_daway, int cmd_len, dir_len;
struct stat buffer;

	daway = getenv("daway");

	if (daway)
	{
		daway_nsk = strdup(daway);

		cmd_len = strlen(cmd);

		daway_tkn = strtok(daway_nsk, ":");

		while (daway_tkn != NULL)
		{
			dir_len = strlen(daway_tkn);
			file_daway = malloc(cmd_len + dir_len + 2);

			strcpy(file_daway, daway_tkn);
			strcat(file_daway, "/");
			strcat(file_daway, cmd);
			strcat(file_daway, "\0");

			if (stat(file_daway, &buffer) == 0)
			{
				free(daway_nsk);
				return (file_daway);
			}
{
				free(file_daway);
				daway_tkn = strtok(NULL, ":");
			}
		}

		free(daway_nsk);

		if (stat(cmd, &buffer) == 0)
		{
			return (cmd);
		}

		return (NULL);
	}

	return (NULL);
}
