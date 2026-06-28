#ifndef OPTIONS_H
#define OPTIONS_H

typedef enum {
    C,
    CPP,
} supported_langs_t;

/*
 * Gets the program name from the command line arguments
 */
const char* get_name(int argc, char** argv);

/*
 * uses ncurses to get the laguage from supported options
 * see supported_langs_t for details
 */
const supported_langs_t get_language(void);

/*
 * uses ncurses to ask if the user wants boilerplate code
 */
const size_t ask_boilerplate(void);

#endif
