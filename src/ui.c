#include <stdio.h>

int energy = 0;
int maxenergy = 0;

int sustain = 0;
int maxsustain = 0;

const char* acts[10] = {
    " ",
    "               Acts/Policies:",
    "1: National Environmental Policy Act (NEPA)",
    "2: Endangered Species Act (ESA)",
    "3: Clean Air Act (CAA)",
    "4: Clean Water Act (CWA)",
    "5: Safe Drinking Water Act (SDWA)",
    "6: Montreal Protocol",
    "7: Kyoto Protocol",
    "8: Paris Climate Accords"
};

void render(int rows, int columns) {
    printf("\e[1;1H\e[2J");

    printf(" ");
    for (int i = 0; i < columns; i++) {
        printf("   %c", i + 'a');
    }
    printf("\n");

    printf("  ");
    for (int i = 0; i < columns; i++) {
        printf("+---");
    }
    printf("+               Energy: %d/%d\n", energy, maxenergy);

    for (int i = 0; i < rows; i++) {
        if (i != 0) printf("  ");
        for (int j = 0; j < columns; j++) {
            if (i == 0) break;
            printf("+---");
        }

        if (i != 0) {
            if (2*i - 2 < 10) printf("+                              %s\n", acts[2*i - 2]);
            else printf("+\n");
        }

        printf("%d ", i);
        for (int j = 0; j < columns; j++) {
            printf("|   ");
        }

        if (i == 0) printf("|               Sustainability: %d/%d\n", sustain, maxsustain);
        else {
            if (2*i - 1 < 10) printf("|                              %s\n", acts[2*i - 1]);
            else printf("|\n");
        }
    }

    printf("  ");
    for (int i = 0; i < columns; i++) {
        printf("+---");
    }
    printf("+\n");
}