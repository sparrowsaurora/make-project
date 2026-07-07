// #include <stdio.h>
// #include <stdlib.h>

#include "options.h"
#include "structure.h"

int main(int argc, char** argv) {
    // options opts;
    // get_options(&opts, argc, argv);

    // show_opts(&opts);

    make("dir_test/");
    make("file.txt", "boilerplate");
    make("dir_test/test_file.md", NULL);
    make("dir_test/test_file2.md", "boo");

    return EXIT_SUCCESS;
}
