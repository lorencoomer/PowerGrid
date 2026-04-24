#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[100];
char *text;

void say(const char* msg) {
    void *data = malloc(strlen(text) + strlen(input) + 20);
    snprintf(data, strlen(text) + strlen(input) + 20, "%s%s\n%s\n> ", text, input, msg);

    free(text);
    text = malloc(strlen(text) + strlen(input) + 20);

    strcpy(text, data);
    free(data);
}

void readcommands() {
    if(!text) {
        text = malloc(3);
        strcpy(text, "> ");
    }

    printf("%s", text);
    
    int read = scanf("%99s", input);

    if (read != 1 || strcmp(input, "exit") == 0) {
        printf("\033[0;0H\033[J");
        
        exit(0);
    }
    else if (strcmp(input, "pass") == 0) {}
    else say("invalid command");
}