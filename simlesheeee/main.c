#include "main.h"

/**
 * main - Entry point of the shell program.
 *
 * @ac: Number of arguments.
 * @argv: Array of strings containing the arguments.
 *
 * Return: Always 0.
 */
int main(int ac, char **argv)
{
    char *lainepoiter = NULL, *lainepoiter_noskha = NULL;
    char *prmt = "the prmt is $ ";
    const char *delim = " \n";
    ssize_t lain_ragea;
    size_t s = 0;
    char *token;
    int i;
    (void)ac;
    int howmnytokenz = 0;

    while (1)
    {
        printf("%s", prmt);
        lain_ragea = getline(&lainepoiter, &s, stdin);
        if (lain_ragea == -1)
        {
            printf("end of file <ctrl+d>\n");
            return (-1);
        }

        // Allocate memory for the duplicate of the input string
        lainepoiter_noskha = malloc(sizeof(char) * lain_ragea);
        if (lainepoiter_noskha == NULL)
        {
            perror("tsh: memory allocation error");
            return (-1);
        }
        strcpy(lainepoiter_noskha, lainepoiter);

        // Count the number of tokens in the input string
        token = strtok(lainepoiter, delim);
        while (token != NULL)
        {
            howmnytokenz++;
            token = strtok(NULL, delim);
        }
        howmnytokenz++;

        // Allocate memory for the array of tokens (argv)
        argv = malloc(sizeof(char *) * howmnytokenz);

        // Tokenize the duplicated input string and fill the argv array
        token = strtok(lainepo
