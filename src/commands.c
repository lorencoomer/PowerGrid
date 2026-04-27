#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int energy = 100;
int minenergy = 80;

int sustain = 0;
int minsustain = 0;

int money = 0;

char *input;
size_t input_size = 0;

char *text;

void say(const char* msg) {
    void *data = malloc(strlen(text) + strlen(input) + 20);
    input[strcspn(input, "\n")] = 0;
    snprintf(data, strlen(text) + strlen(input) + 20, "%s%s\n%s\n> ", text, input, msg);

    text = realloc(text, strlen(text) + strlen(input) + 20);

    strcpy(text, data);
    free(data);
}

void readcommands() {
    if(!text) {
        text = malloc(3);
        strcpy(text, "> ");
    }
    
    printf("%s", text);
    int read = getline(&input, &input_size, stdin);

    if (strcmp(input, "exit\n") == 0) {
        printf("\033[0;0H\033[J");
        
        exit(0);
    }
    else if (strcmp(input, "pass\n") == 0) {}
    else say("invalid command");
}