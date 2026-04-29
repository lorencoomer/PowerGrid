#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ui.h"
#include "commands.h"

const char* acts[12] = {
    " ",
    "               Acts/Policies:                                 Sustainable Power Plants:",
    "1: National Environmental Policy Act (NEPA)          W: Windmill Farm ($4,000 for 10 energy)",
    "2: Endangered Species Act (ESA)                      S: Solar Panel Farm ($5,000 for 15 energy)",
    "3: Clean Air Act (CAA)                               G: Geothermal Plant ($15,000 for 40 energy)",
    "4: Clean Water Act (CWA)                             H: Hydroelectric Plant ($25,000 for 100 energy)",
    "5: Safe Drinking Water Act (SDWA)",
    "6: Montreal Protocol                                   Unsustainable Power Plants:",
    "7: Kyoto Protocol                                    O: Oil Power Plant (20 energy)",
    "8: Paris Climate Accords                             C: Coal Power Plant (60 energy)",
    "9: Marine Mammal Protection Act                      N: Nuclear Power Plant (120 energy)",
    "@: Yellow Stone National Park Protection Act"
};

char grid[10][10] = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', 'C', ' ', ' ', ' ', ' ', ' ', 'O', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
};

PlantPos filled[100] = {{3, 2}, {2, 7}, {8, 7}};
int filled_size = 3;

PlantPos filled_sustainable[100];
int filled_sustainable_size = 0;

void render(int rows, int columns) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    printf(" ");
    for (int i = 0; i < columns; i++) {
        printf("   %c", i + 'a');
    }
    printf("\n");

    printf("  ");
    for (int i = 0; i < columns; i++) {
        printf("+---");
    }

    if (energy >= minenergy) printf("+          Energy: %d/%d\n", energy, minenergy);
    else printf("+\033[31m          Energy: %d/%d\033[0m\n", energy, minenergy);

    for (int i = 0; i < rows; i++) {
        if (i != 0) printf("  ");
        for (int j = 0; j < columns; j++) {
            if (i == 0) break;
            printf("+---");
        }

        if (i >= 2) {
            if (2*i - 3 < 12) printf("+                        %s\n", acts[2*i - 3]);
            else printf("+\n");
        }
        else if (i == 1) {
            printf("+          Money: $%d\n", money);
        }

        printf("%d ", i);
        for (int j = 0; j < columns; j++) {
            printf("| %c ", grid[i][j]);
        }

        if (i == 0) {
           if (sustain >= minsustain) printf("|          Sustainability: %d/%d\n", sustain, minsustain);
           else printf("|\033[31m          Sustainability: %d/%d\033[0m\n", sustain, minsustain);
        }
        else {
            if (2*i - 2 < 12) printf("|                        %s\n", acts[2*i - 2]);
            else printf("|\n");
        }
    }

    printf("  ");
    for (int i = 0; i < columns; i++) {
        printf("+---");
    }
    printf("+\n");
}