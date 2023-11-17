#include "main.h"

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
        printf ("%s", prmt);
        lain_ragea = getline(&lainepoiter, &s, stdin);
        if (lain_ragea == -1)
        {
            printf("end of file <ctrl+d>\n");
            return (-1);
        }

        lainepoiter_noskha = malloc(sizeof(char) * lain_ragea);
        if (lainepoiter_noskha == NULL)
        {
            perror("tsh: memory allocation error");
            return (-1);
        }
        strcpy(lainepoiter_noskha, lainepoiter);

        token = strtok(lainepoiter, delim);

        while (token != NULL)
        {
            howmnytokenz++;
            token = strtok(NULL, delim);
        }
        howmnytokenz++;

        argv = malloc(sizeof(char *) * howmnytokenz);

        token = strtok(lainepoiter_noskha, delim);

        for (i = 0; token != NULL; i++)
        {
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);

            token = strtok(NULL, delim);
        }
        argv[i] = NULL;

        execmd(argv);
    }

    free(lainepoiter_noskha);
    free(lainepoiter);

    return (0);
}
