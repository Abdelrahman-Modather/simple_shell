/**
 * main - Entry point of the shell program.
 *
 * @ac: Number of arguments.
 * @argv: Array of strings containing the arguments.
 *
 * Return: Always 0.
 */

#include "main.h"

int main(int ac, char **argv)
{
char *lptr = NULL, *lptr_nsk = NULL, char *prmt = "$ ", ssize_t lin_rga, int i;
const char *dl = " \n", int adadtok = 0, size_t s = 0, char *tkn, (void)ac;

	while (1)
	{
		printf("%s", prmt);
		lin_rga = getline(&lptr, &s, stdin);
		if (lin_rga == -1)
		{
			printf("end of file <ctrl+d>\n");
			return (-1);
			}
		lptr_nsk = malloc(sizeof(char) * lin_rga);
		if (lptr_nsk == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		strcpy(lptr_nsk, lptr);
		tkn = strtok(lptr, dl);
		while (tkn != NULL)
		{
			adadtok++;
			tkn = strtok(NULL, dl);
		}
		adadtok++;
		argv = malloc(sizeof(char *) * adadtok);
		tkn = strtok(lptr_nsk, dl);
		for (i = 0; tkn != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(tkn));
			strcpy(argv[i], tkn);
			tkn = strtok(NULL, dl);
		}
		argv[i] = NULL;
		execmd(argv);
	}
	free(lptr_nsk);
	free(lptr);
	return (0);
}
