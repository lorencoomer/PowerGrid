#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "ui.h"

extern char grid[10][10];

int energy = 100;
int minenergy = 80;

int sustain = 0;
int minsustain = 0;

int money = 0;

int turn = 0;

char *input;
size_t input_size = 0;
char *full_input = NULL;

char *text;

const char* messages[12] = {
    "%c%d is polluting the river",
    "%c%d is cutting down trees",
    "%c%d is burning fossil fuels",
    "%c%d is claiming that they forgot to consider environmental impact",
    "residents near %c%d claim they've gotten sick from water pollution",
    "%c%d is cutting down trees near the habitat of the monarch butterfly",
    "%c%d is destroying habitats of the black bear",
    "%c%d is producing large amounts of ozone-depleting chemicals",
    "%c%d has not reported their carbon emissions in the past year",
    "%c%d has not reduced their carbon emissions from 2013 to 2020",
    "%c%d is destroying habitats of the bottlenose dolphin",
    "%c%d is destroying yellowstone national park",
};

int act_for_messages[12] = { 4, 0, 3, 1, 5, 2, 0, 6, 8, 7, 9, 16 };

int message;

char curr[2] = {0};

void say(const char* msg) {
    char *disp = full_input ? full_input : input;
    disp[strcspn(disp, "\n")] = 0;
    void *data = malloc(strlen(text) + strlen(disp) + strlen(msg) + 4);
    snprintf(data, strlen(text) + strlen(disp) + strlen(msg) + 4, "%s%s\n%s\n> ", text, disp, msg);

    text = realloc(text, strlen(text) + strlen(disp) + strlen(msg) + 4);

    strcpy(text, data);
    free(data);
}

void pass() {
    int r = rand() % filled_size;

    message = rand() % 12;

    curr[0] = filled[r].col + 'a';
    curr[1] = filled[r].row + '0';

    char* data = malloc(strlen(messages[message]) + 3);
    snprintf(data, strlen(messages[message]) + 3, messages[message], curr[0], curr[1] - '0');

    say(data);
    free(data);
}

static int energy_for_char(char c) {
    switch (c) {
        case 'O': return 20;
        case 'C': return 60;
        case 'N': return 120;
        case 'W': return 10;
        case 'S': return 15;
        case 'G': return 40;
        case 'H': return 100;
        default:  return 0;
    }
}

void calc_energy() {
    energy = 0;
    sustain = filled_sustainable_size;
    for (int i = 0; i < filled_size; i++)
        energy += energy_for_char(grid[filled[i].row][filled[i].col]);
    for (int i = 0; i < filled_sustainable_size; i++)
        energy += energy_for_char(grid[filled_sustainable[i].row][filled_sustainable[i].col]);
}

static void end_of_turn() {
    turn++;
    minenergy += 3 + turn / 10;

    calc_energy();

    if (energy < minenergy) {
        int drain = (minenergy - energy) * 10;
        money -= drain;
    }

    if (turn % 4 == 0) {
        PlantPos empty[100];
        int empty_count = 0;
        for (int r = 0; r < 10; r++)
            for (int c = 0; c < 10; c++)
                if (grid[r][c] == ' ')
                    empty[empty_count++] = (PlantPos){c, r};

        if (empty_count > 0 && filled_size < 100) {
            int idx = rand() % empty_count;
            PlantPos pos = empty[idx];

            char plant;
            if (turn < 20) plant = 'O';
            else if (turn < 50) plant = 'C';
            else plant = 'N';

            grid[pos.row][pos.col] = plant;
            filled[filled_size++] = pos;

            calc_energy();
        }
    }
}

void readcommands() {
    srand(time(NULL));

    calc_energy();

    if (!text) {
        text = malloc(3);
        strcpy(text, "> ");
    }

    printf("%s", text);
    int read = getline(&input, &input_size, stdin);

    if (full_input) free(full_input);
    full_input = strdup(input);

    char *token = strtok(input, " ");

    if (token == NULL) {
        say("invalid command");
        return;
    }

    if (strcmp(input, "exit\n") == 0) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        exit(0);
    }
    else if (strcmp(input, "pass\n") == 0) {
        if (filled_size == 0) {
            say("no unsustainable plants to report on");
            end_of_turn();
        }
        else pass();
        
        end_of_turn();
    }
    else if (strcmp(token, "sue") == 0) {
        token = strtok(NULL, " ");

        if (token == NULL || token[0] < 'a' || token[0] > 'j' || token[1] < '0' || token[1] > '9') {
            say("invalid command");
            return;
        }

        int plant_en = 20;
        if (curr[0] >= 'a' && curr[0] <= 'j' && curr[1] >= '0' && curr[1] <= '9')
            plant_en = energy_for_char(grid[curr[1] - '0'][curr[0] - 'a']);
        int win_amount  = plant_en * 300;
        int lose_amount = plant_en * 15 + 50;

        if (token[0] == curr[0] && token[1] == curr[1]) {
            token = strtok(NULL, " \n");

            if ((token == NULL || token[0] < '1' || token[0] > '8') && token[0] != '@') {
                say("invalid command");
                return;
            }

            if (token[0] - '0' == act_for_messages[message]) {
                char msg[64];
                snprintf(msg, sizeof(msg), "you win and gain $%d", win_amount);
                say(msg);
                money += win_amount;

                int col = curr[0] - 'a';
                int row = curr[1] - '0';
                grid[row][col] = ' ';
                for (int i = 0; i < filled_size; i++) {
                    if (filled[i].col == col && filled[i].row == row) {
                        for (int j = i; j < filled_size - 1; j++)
                            filled[j] = filled[j + 1];
                        filled_size--;
                        break;
                    }
                }
                calc_energy();
            }
            else {
                char msg[64];
                snprintf(msg, sizeof(msg), "you lose and pay $%d", lose_amount);
                say(msg);
                money -= lose_amount;
            }
        }
        else {
            char msg[64];
            snprintf(msg, sizeof(msg), "you lose and pay $%d", lose_amount);
            say(msg);
            money -= lose_amount;
        }
        end_of_turn();
    }
    else if (strcmp(token, "build") == 0) {
        token = strtok(NULL, " ");
        if (token == NULL || token[0] < 'a' || token[0] > 'j' || token[1] < '0' || token[1] > '9') {
            say("invalid command");
            return;
        }
        int col = token[0] - 'a';
        int row = token[1] - '0';

        token = strtok(NULL, " \n");
        if (token == NULL) {
            say("invalid command");
            return;
        }
        char plant = token[0];

        int cost;
        switch (plant) {
            case 'W': cost = 4000;  break;
            case 'S': cost = 5000;  break;
            case 'G': cost = 15000; break;
            case 'H': cost = 25000; break;
            default:
                say("invalid plant type");
                return;
        }

        if (grid[row][col] != ' ') {
            say("square is already occupied");
            return;
        }
        if (money < cost) {
            say("not enough money");
            return;
        }

        money -= cost;
        grid[row][col] = plant;
        filled_sustainable[filled_sustainable_size++] = (PlantPos){col, row};
        say("plant built");

        calc_energy();
        end_of_turn();
    }
    else say("invalid command");
}