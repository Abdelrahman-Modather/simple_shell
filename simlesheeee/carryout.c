#include "main.h"

void execmd(char **argv){
    char *cmd = NULL, *usertcmd = NULL;

    if (argv){
        cmd = argv[0];
        usertcmd = findit(cmd);

        if (execve(usertcmd, argv, NULL) == -1)
        {
            perror("something went wrong:");
        }
    }
    
}
