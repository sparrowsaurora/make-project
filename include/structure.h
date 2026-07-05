#ifndef STRUCTURE_H
#define STRUCTURE_H
/**
 * function prototypes for assebling file structure
 */

#include <stdio.h>
#include <stdlib.h>

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

// possibly change so i can make files via the path alone, and dirs by leaving the end with a /

/**
 * creates a file object
 *
 * if ~ path = NULL
 * if no boilerplate = NULL
 */
bool make_file(const char* path, const char* name, const char* boilerplate);

/**
 * creates a directory object at a desired location {path}
 *
 * if ~ path = NULL
 */
bool make_dir(const char* path, const char* name);

#endif