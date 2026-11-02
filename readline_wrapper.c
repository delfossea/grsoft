#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

char *soft_readline(const char *prompt) {
    return readline(prompt);
}

void soft_add_history(const char *line) {
    if (line && line[0] != '\0') {
        add_history(line);
    }
}
