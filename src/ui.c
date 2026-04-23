#include <stdio.h>

void makegrid(int rows, int columns) {
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
    printf("+\n");

    for (int i = 0; i < rows; i++) {
        if (i != 0) printf("  ");
        for (int j = 0; j < columns; j++) {
            if (i == 0) break;
            printf("+---");
        }
        if (i != 0) printf("+\n");

        printf("%d ", i);
        for (int j = 0; j < columns; j++) {
            printf("|   ");
        }
        printf("|\n");
    }

    printf("  ");
    for (int i = 0; i < columns; i++) {
        printf("+---");
    }
    printf("+\n");
}