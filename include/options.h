#ifndef OPTIONS_H
#define OPTIONS_H

#include <menu.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#define PROGRAM_NAME_ARG 1  // second argument is the name of the program

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 4
#define CHAR_Q 113

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
supported_langs_t get_language(void);

/*
 * to_string method for the supported_langs_t type
 */
const char* language_to_string(supported_langs_t lang);

/*
 * uses ncurses to ask if the user wants boilerplate code
 * true = boilerplate, false = none
 */
bool ask_boilerplate(void);

#endif
