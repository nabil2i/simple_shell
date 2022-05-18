#include "main.h"

/**
 * exe - executes new processes
 * @line
 * Return: Success 0
 */
int exe(char **tokens)
{
	int status;
	pid_t child_pid;


	child_pid = fork();
	if (child_pid == 0)
	{
		if(execve(tokens[0], tokens, NULL) == -1)
		{
			printf("%s: not found\n", tokens[0]);
			_exit(-1);	
		
		}
	}
	else
	{
		waitpid(-1, &status, 0);
	}
	
	if (status == 0)
		errno = 0;
	if (status == 512)
		errno = 2;
	if (status == 65280)
		errno = 127;
	return (0);
}
