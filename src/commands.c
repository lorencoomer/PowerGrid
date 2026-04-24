#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[100];

void readcommands() {
    printf("> ");
    
    int read = scanf("%99s", input);

    if (read != 1 || strcmp(input, "exit") == 0) {
        printf("\e[1;1H\e[2J");
        exit(0);
    }
}