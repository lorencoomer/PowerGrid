#include <stdbool.h>
#include "ui.h"
#include "commands.h"

int main() {
    while (true) {
        makegrid(10, 10);
        readcommands();
    }

    return 0;
}