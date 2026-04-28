#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "ui.h"

int energy = 100;
int minenergy = 80;

int sustain = 0;
int minsustain = 0;

int money = 0;

char *input;
size_t input_size = 0;

char *text;

const char* messages[10] = {
    "%c%d is polluting the river",
    "%c%d is cutting down trees",
    "%c%d is burning fossil fuels",
    "%c%d is claiming that they forgot to consider environmental impact",
    "residents near %c%d claim they've gotten sick from water pollution",
    "%c%d is cutting down trees near the habitat of the monarch butterfly",
    "%c%d is destroying habitats of the black bear",
    "%c%d is producing large amounts of ozone-depleting chemicals",
    "%c%d has not reported their carbon emissions in the past year",
    "%c%d has not reduced their carbon emissions from 2013 to 2020"
};

int message;

void say(const char* msg) {
    void *data = malloc(strlen(text) + strlen(input) + strlen(msg) + 4);
    input[strcspn(input, "\n")] = 0;
    snprintf(data, strlen(text) + strlen(input) + strlen(msg) + 4, "%s%s\n%s\n> ", text, input, msg);

    text = realloc(text, strlen(text) + strlen(input) + strlen(msg) + 4);

    strcpy(text, data);
    free(data);
}

void pass() {
    int r = rand() % filled_size;

    message = rand() % 10;

    char* data = malloc(strlen(messages[message]) + 3);
    snprintf(data, strlen(messages[message]) + 3, messages[message], filled[0][r] + 'a', filled[1][r]);

    say(data);
    free(data);
}

void readcommands() {
    srand(time(NULL));

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
    else if (strcmp(input, "pass\n") == 0) pass();
    else say("invalid command");
}