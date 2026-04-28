#include <stdbool.h>
#include "ui.h"
#include "commands.h"

int main() {
    filled[0][0] = 3;
    filled[1][0] = 2;
    filled[0][1] = 2;
    filled[1][1] = 7;
    filled[0][2] = 8;
    filled[1][2] = 7;

    while (true) {
        render(10, 10);
        readcommands();
    }

    return 0;
}