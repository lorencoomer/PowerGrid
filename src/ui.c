#include <stdio.h>
#include <stdlib.h>
#include "commands.h"

const char* acts[11] = {
    " ",
    "               Acts/Policies:                                 Sustainable Power Plants:",
    "1: National Environmental Policy Act (NEPA)          W: Windmill Farm ($2,000 for 10 energy)",
    "2: Endangered Species Act (ESA)                      S: Solar Panel Farm ($3,000 for 15 energy)",
    "3: Clean Air Act (CAA)                               G: Geothermal Plant ($6,000 for 40 energy)",
    "4: Clean Water Act (CWA)                             H: Hydroelectric Plant ($10,000 for 100 energy)",
    "5: Safe Drinking Water Act (SDWA)",
    "6: Montreal Protocol                                   Unsustainable Power Plants:",
    "7: Kyoto Protocol                                    O: Oil Power Plant (20 energy)",
    "8: Paris Climate Accords                             C: Coal Power Plant (60 energy)",
    "                                                     N: Nuclear Power Plant (120 energy)"
};

char grid[10][10] = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
};

void render(int rows, int columns) {
    printf("\033[0;0H\033[J");

    printf(" ");
    for (int i = 0; i < columns; i++) {
        printf("   %c", i + 'a');
    }
    printf("\n");

    printf("  ");
    for (int i = 0; i < columns; i++) {
        printf("+---");
    }
    printf("+          Energy: %d/%d\n", energy, maxenergy);

    for (int i = 0; i < rows; i++) {
        if (i != 0) printf("  ");
        for (int j = 0; j < columns; j++) {
            if (i == 0) break;
            printf("+---");
        }

        if (i >= 2) {
            if (2*i - 3 < 11) printf("+                        %s\n", acts[2*i - 3]);
            else printf("+\n");
        }
        else if (i == 1) {
            printf("+          Money: $%d\n", money);
        }

        printf("%d ", i);
        for (int j = 0; j < columns; j++) {
            printf("| %c ", grid[i][j]);
        }

        if (i == 0) printf("|          Sustainability: %d/%d\n", sustain, maxsustain);
        else {
            if (2*i - 2 < 11) printf("|                        %s\n", acts[2*i - 2]);
            else printf("|\n");
        }
    }

    printf("  ");
    for (int i = 0; i < columns; i++) {
        printf("+---");
    }
    printf("+\n");
}