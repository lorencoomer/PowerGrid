#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "commands.h"

int main() {
    while (true) {
        render(10, 10);
        readcommands();

        if(money < 0) {
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif

            break;
        }
    }

    return 0;
}