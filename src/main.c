// #include <stdio.h>
// #include <stdlib.h>

#include "options.h"
#include "structure.h"

int main(int argc, char** argv) {
    options opts;
    get_options(&opts, argc, argv);

    show_opts(&opts);

    return EXIT_SUCCESS;
}
