#include "main.h"

/**
 * terminateShell - Exits the current process by sending a (SIGTERM) signal.
 *
 * Return: Nothing.
 */
void terminateShell(void)
{
	signal(SIGTERM, &terminationHandler);
	kill(getpid(), SIGTERM);
}

/**
 * terminationHandler - Handles the signal sent by the terminateShell function (SIGTERM)
 * signal by printing a newline character.
 *
 * @signalNumber: Integer value, represents the signal given to the function.
 *
 * Return: Nothing.
 */
void terminationHandler(int signalNumber)
{
	if (signalNumber == SIGTERM)
	{
		exit(0);
	}
}
