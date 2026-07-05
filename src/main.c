// #include <stdio.h>
// #include <stdlib.h>

#include "options.h"
#include "structure.h"

int main(int argc, char** argv) {
    // options opts;
    // get_options(&opts, argc, argv);

    // show_opts(&opts);

    make_dir(NULL, "hi");
    // make_dir("i", "hi2");
    make_dir("hi", "hi3");
    make_file("hi/hi3", "stuff.txt", NULL);
    make_file("hi", "test.c", "some words");
    make_file(NULL, "hi.md", NULL);

    return EXIT_SUCCESS;
}
