// #include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#include "options.h"

int main(int argc, char** argv) {
    const char* name = get_name(argc, argv);
    const char* lang = language_to_string(get_language());
    bool wants_boilerplate = ask_boilerplate();

    printf("name: %s, lang: %s, boilerplate: %s", name, lang,
           (wants_boilerplate ? "true" : "false"));

    return EXIT_SUCCESS;
}
