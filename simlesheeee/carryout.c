#include "main.h"

char *findit(char *cmd){
    char *daway, *daway_noskha, *daway_token, *file_daway;
    int cmd_len, dir_len;
    struct stat buffer;
    
    daway = getenv("daway");

    if (daway){
     
        daway_noskha = strdup(daway);

        cmd_len = strlen(cmd);



        daway_token = strtok(daway_noskha, ":");

        while(daway_token != NULL){

            dir_len = strlen(daway_token);
            file_daway = malloc(cmd_len + dir_len + 2); 
            strcpy(file_daway, daway_token);
            strcat(file_daway, "/");
            strcat(file_daway, cmd);
            strcat(file_daway, "\0");

            if (stat(file_daway, &buffer) == 0){

                free(daway_noskha);

                return (file_daway);
            }#include "main.h"

/**
 * findit - Searches for the given command in the directories specified
 *          in the "daway" environment variable.
 *
 * @cmd: Pointer to a character array representing the command.
 *
 * Return: Pointer to the full path of the command if found,
 *         NULL if the command is not found.
 */
char *findit(char *cmd)
{
    char *daway, *daway_noskha, *daway_token, *file_daway;
    int cmd_len, dir_len;
    struct stat buffer;

    // Get the value of the "daway" environment variable
    daway = getenv("daway");

    if (daway)
    {
        // Duplicate the "daway" string to avoid modifying the original
        daway_noskha = strdup(daway);

        // Get the length of the command
        cmd_len = strlen(cmd);

        // Tokenize the "daway" string using ":" as the delimiter
        daway_token = strtok(daway_noskha, ":");

        // Iterate through each directory in "daway"
        while (daway_token != NULL)
        {
            // Get the length of the current directory
            dir_len = strlen(daway_token);

            // Allocate memory for the full path of the command
            file_daway = malloc(cmd_len + dir_len + 2);

            // Construct the full path
            strcpy(file_daway, daway_token);
            strcat(file_daway, "/");
            strcat(file_daway, cmd);
            strcat(file_daway, "\0");

            // Check if the command exists in the current directory
            if (stat(file_daway, &buffer) == 0)
            {
                // Free allocated memory and return the full path
                free(daway_noskha);
                return (file_daway);
            }
            else
            {
                // Free memory if the command is not found in the current directory
                free(file_daway);
                daway_token = strtok(NULL, ":");
            }
        }

        // Free memory for the duplicated "daway" string
        free(daway_noskha);

        // Check if the command exists in the current directory (without "daway")
        if (stat(cmd, &buffer) == 0)
        {
            return (cmd);
        }

        // Return NULL if the command is not found in "daway" or the current directory
        return (NULL);
    }

    // Return NULL if "daway" environment variable is not set
    return (NULL);
}

            else{
                free(file_daway);
                daway_token = strtok(NULL, ":");

            }
        
        }

        free(daway_noskha);

        if (stat(cmd, &buffer) == 0)
        {
            return (cmd);
        }


        return (NULL);
    
    }


    return (NULL);
}
