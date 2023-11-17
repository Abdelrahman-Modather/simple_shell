#include "main.h"

/**
 * findit - Finds the full path of a command in the specified directories.
 *
 * @cmd: Pointer to a character array representing the command.
 *
 * Return: Pointer to the full path of the command (Success)
 *         NULL if the command is not found.
 */
char *findit(char *cmd) {
    char *daway, *daway_noskha, *daway_token, *file_daway;
    int cmd_len, dir_len;
    struct stat buffer;

    daway = getenv("daway");

    if (daway) {
        daway_noskha = strdup(daway);

        cmd_len = strlen(cmd);

        daway_token = strtok(daway_noskha, ":");

        while (daway_token != NULL) {
            dir_len = strlen(daway_token);
            file_daway = malloc(cmd_len + dir_len + 2);

            strcpy(file_daway, daway_token);
            strcat(file_daway, "/");
            strcat(file_daway, cmd);
            strcat(file_daway, "\0");

            if (stat(file_daway, &buffer) == 0) {
                free(daway_noskha);
                return file_daway;
            } else {
                free(file_daway);
                daway_token = strtok(NULL, ":");
            }
        }

        free(daway_noskha);

        if (stat(cmd, &buffer) == 0) {
            return cmd;
        }

        return NULL;
    }

    return NULL;
}
