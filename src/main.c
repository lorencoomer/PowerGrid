#include <stdbool.h>
#include "ui.h"
#include "commands.h"

int main() {
    while (true) {
        render(10, 10);
        readcommands();
    }

    return 0;
}