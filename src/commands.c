#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[100];

void readcommands() {
    printf("> ");
    
    int read = scanf("%99s", input);

    if (read != 1 || strcmp(input, "exit") == 0) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        
        exit(0);
    }
    else if (strcmp(input, "pass") == 0) {
        printf("\033[A\033[2K\r");
    }
    else {
        printf("invalid command\n");
    }
}