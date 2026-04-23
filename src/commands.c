#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readcommands(char* input) {
    printf("> ");
    scanf("%s", input);

    if (strcmp(input, "exit") == 0) {
        printf("\e[1;1H\e[2J");
        exit(0);
    }
}