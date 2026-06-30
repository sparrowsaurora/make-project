#include "options.h"

const char* choices[] = {"C", "C++"};

const char* get_name(int argc, char** argv) {
    // if no first arg or more than 1 arg -> usage message -> exit
    if (argc != (PROGRAM_NAME_ARG + 1)) {
        printf("usage msg\n");
        exit(EXIT_FAILURE);
    }
    // return first arg
    return argv[PROGRAM_NAME_ARG];
}

supported_langs_t get_language(void) {
    int choice_count = ARRAY_SIZE(choices);
    for (int i = 0; i < (choice_count); ++i) {
        printf("%d\t%s\n", (i + 1), choices[i]);
    }

    char* line = NULL;
    size_t size = 0;
    int option;
    do {
        printf("Select your language using their index. >> ");
        getline(&line, &size, stdin);
        option = atoi(line);
        // add more guards
    } while (option < 1 || option > choice_count);
    // while option is less than 0 or more than choice count redo loop, else exit
    /// check for is aphabetical, or is symbolic
    free(line);

    // render window to use up and down arrows to see different options?
    const supported_langs_t lang = (supported_langs_t)(option - 1);
    return lang;
}

const char* language_to_string(supported_langs_t lang) { return choices[(int)lang]; }

bool ask_boilerplate(void) {
    // render window to use up and down arrows to see different options?
    char* buffer = NULL;
    size_t size = 0;

    while (true) {
        printf("should boilerplate be added to files? >> ");
        if (getline(&buffer, &size, stdin) == -1) {
            // error out
        }
        // add more guards
        // if N variant: no
        if (buffer[0] == 'n' || buffer[0] == 'N') {
            free(buffer);
            return false;
        }
        // if Y variant || enter: yes
        if (buffer[0] == 'y' || buffer[0] == 'Y') {
            free(buffer);
            return true;
        }

        // else ask again
    }
    // while option is less than 0 or more than choice
}
