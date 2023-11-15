#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int checkCommandValidity(char *cmd);
void terminateShell(void);
void terminationHandler(int signalNumber);
char *getEnvironmentVariable(char *variableName);
void printEnvironmentVariables(char *customPrompt);
void executeCommand(char **programArguments, char **commandToken, char *commandLine, char *messagePrompt);
void forkShell(char **programArguments, char **commandToken, char *messagePrompt, char *commandLine);
void interactiveShell(char **programArguments);
void nonInteractiveShell(char **programArguments);
int runShell(__attribute__((unused)) int argumentCount, char **argumentValues);
int handlePath(char **commandTokens);
int findPath(char *commandName);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char **splitString(char *inputString, const char *delimiter);
int countTokens(char *inputString, const char *delimiter);

#endif