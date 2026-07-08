#ifndef PRESETS_H
#define PRESETS_H

/*
    Creates language presets from config files

    WARNING: THIS FILE IS NOT CROSS PLATFORM (LINUX ONLY)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// file headers
#include <dirent.h>
#include <sys/types.h>

#define FILE_TYPE_LENGTH 4

typedef struct node;

typedef struct {
    preset_t data;
    node* next;
} node;

typedef struct {
    const char* name;
    const char* boilerplate;
} entry_t;

typedef struct {
    const char* lang;
    const entry_t* entries;  // * is an array here
} preset_t;

/**
 * Load presets from presets file
 *
 * presets -> a pointer to a a lists of heap allocated structs
 * config_dir_path -> string to the configs dir
 */
bool load_presets(preset_t** presets, const char* config_dir_path);

static bool get_preset(preset_t* preset, struct dirent* entry);

void show_preset(preset_t* preset);

make_presets_list()

#endif