
#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void shell_loop(void);
char *read_input(void);
char **parse_input(char *line);
int execute_command(char **args);

#endif /* HSH_H */
