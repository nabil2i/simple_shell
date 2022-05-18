#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <dirent.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
/**
 * struct nodep - linked list of nodes
 * @path: string content of node
 * @next: pointer to next node
 *
 * Description: linked list of nodes used to get all PATH env variable routes
 */
typedef struct nodep
{
	char *path;
	struct nodep *next;
} nodep;
char **tokenizer(char *, char *, char **);
char *strconcat(char *, char *);
char *_getenv(char *, char **);
void get_path(char **, char **, char **);
nodep *tokenLinked(char string[], char *separator);
int chkBuiltin(char **, char **, char *);
int chkPath(char **, char **);
void execution(char **, char **);
int _strlen(char *);
char *_strdup(char *);
int _strcmp(char *, char *);
int _strncmp(char *, char *, unsigned int);
void exitpls(void);
void freezeLl(nodep *);
/* **********************************
 * **********************************
 * **********************************
 */
/* ENVIRONMENT */

extern char **environ;

/* STRUCTURES*/

/**
 * struct fmt - types of data and their function
 * @ltr: the type of data
 * @type: pointer to function for type
 */
typedef struct fmt
{
	char *ltr;
	int (*type)();
} fmt;

/* DECLARATION OF FUNCTIONS */

void _puts(char *str);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int parse(char *line, int num_tokens, char *argv[], int failcount);
int exe(char *line, char **ar, char *nln, char **arry, char **argv, int flcnt);
void myfree(char *line, char **ar, char *newline, char **array);
int _strncmp(char *s1, char *s2, int len);
int checkbltin(char *line, char **ar, char *newline, char **array);
int numcount(char *line);
int searchpath(char *p, char **tokens);
int findonpath(char **tokens);
void executepath(char *p, char **tokens);
int _printf(const char *format, ...);
int chkfmt(va_list *args, const char *format, int i);
int prchr(va_list *args);
int prstr(va_list *args);
int prdgt(va_list *args);
void getdigits(int n);
int _putchar(char c);
void changedir(char **ar);
#endif
