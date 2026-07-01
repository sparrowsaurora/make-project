#ifndef STRUCTURE_H
#define STRUCTURE_H
/**
 * function prototypes for assebling file structure
 */

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <direct.h>
#define CREATE_DIR(dir) _mkdir(dir)
#else
#include <sys/stat.h>  // Required for mkdir
#include <sys/types.h>
#define PERMISSION 0755  // octal notation
#define CREATE_DIR(dir) mkdir(dir, PERMISSION)
#endif

/**
 * creats a file object
 */
bool make_file(const char* name, const char* boilerplate);

/**
 * creats a directory object
 */
bool make_dir(const char* name);

#endif