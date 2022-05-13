#include "main.h"

/**
 * entry point of the shell
 * @argc: arguments count
 * @arfv: arguments list
 *
 * Return: Always 0 on success
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	size_t buffersize = 32;
	char *lineptr;
	char **cmdtokens;
	int interactivity, charactersread;

	signal(SIGINT, SIG_IGN);
	interactivity = isatty(STDIN_FILENO);

	if(!interactivity) /* uninteractive mode */
	{
		while(getline(&lineptr, &buffersize, stdin) > 0)
		{
			cmdtokens = tokenizer(lineptr);
			lineptr = NULL;
			exe(cmdtokens);
		}
		free(lineptr);
		return (0);
	}

	while (interactivity) /* interactive mode */
	{
		if (interactivity == 1)
		{
			write(1, "($) ", 4);
			charactersread = getline(&lineptr, &buffersize, stdin);
			
			if (charactersread < 0)
			{
				free(lineptr);
				write(1, "\n", 1);
				return (0);
			}

			cmdtokens = tokenizer(lineptr);
			lineptr = NULL;
			exe(cmdtokens);
		}
	
	}
	return (0);
}