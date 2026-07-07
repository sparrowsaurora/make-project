#ifndef STRUCTURE_H
#define STRUCTURE_H
/**
 * function prototypes for assebling file structure
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// includes and definitions for multiplatform {CREATE_DIR} macro
#ifdef _WIN32
#include <direct.h>
#define CREATE_DIR(dir) _mkdir(dir)
#else
#include <sys/stat.h>  // Required for mkdir
#include <sys/types.h>
#define PERMISSION 0777  // octal notation
#define CREATE_DIR(dir) mkdir(dir, PERMISSION)
#endif

/**
 * creates a file object
 *
 * if ~ path = NULL
 * if no boilerplate = NULL
 */
static bool make_file(const char* path, const char* boilerplate);

/**
 * creates a directory object at a desired location {path}
 *
 * if ~ path = NULL
 */
static bool make_dir(const char* path);

/**
 * A helper function to route the make() macro to the make_file or make_dir
 *
 * this is needed as the macro can have 1 or 2 args passed and there can result in 3 options.
 */
static void router(const char* path, const char* boilerplate);

// function for macro with 1 param
bool make_without_boilerplate(const char* path);

// function for macro with 2 param
bool make_with_boilerplate(const char* path, const char* boilerplate);

#define GET_MACRO(_1, _2, NAME, ...) NAME
#define make(...) \
    GET_MACRO(__VA_ARGS__, make_with_boilerplate, make_without_boilerplate)(__VA_ARGS__)

#endif