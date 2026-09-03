#ifndef OPTIONS_H
#define OPTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROGRAM_NAME_ARG 1  // second argument is the name of the program

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

typedef enum {
    C,
    CPP,
} supported_langs_t;

typedef struct {
    const char* name;
    supported_langs_t lang;
    bool wants_boilerplate;
} options;

/**
 * Gets the program name from the command line arguments
 */
const char* get_name(int argc, char** argv);

/**
 * uses ncurses to get the laguage from supported options
 * see supported_langs_t for details
 */
supported_langs_t get_language(void);

/**
 * to_string method for the supported_langs_t type
 */
const char* language_to_string(supported_langs_t lang);

/**
 * uses ncurses to ask if the user wants boilerplate code
 * true = boilerplate, false = none
 */
bool ask_boilerplate(void);

/**
 * check if the user's index one parameter is "--help"
 */
bool check_help_command(int* argc, char*** argv);

/**
 * print the help message
 */
void print_help();

/**
 * Populate Options with name, language, boilerplate
 * if user enters a help command return false
 */
bool get_options(options* opts_pointer, int argc, char** argv);

/**
 * print options to stdout in a clean format
 */
void show_opts(options* opts);



#endif
