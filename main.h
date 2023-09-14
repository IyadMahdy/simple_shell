#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include <sys/wait.h>

extern char **environ;

void get_toks(char *str, char **arr, char *delim);
int exit_handler(char **args, char *pname);
void print_env(void);

#endif
