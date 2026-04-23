#include <stdbool.h>
#include "ui.h"
#include "commands.h"

int main() {
    char* input;

    while (true) {
        makegrid(10, 10);
        readcommands(input);
    }

    return 0;
}