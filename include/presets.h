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

//todo: put these values in a global config?
//! COMPILATION ONLY (user may not edit)
#define FILE_TYPE_LENGTH 4
#define MAX_PRESET_NAME_LENGTH 64
#define PRESETS_LIST_SIZE 16
#define MAX_ENTRIES 32

typedef struct {
    const char* name;
    const char* boilerplate;
} entry_t;

typedef struct {
    const char* lang;
    const entry_t* entries;  // * is an array here
} preset_t;

typedef preset_t presets_list[PRESETS_LIST_SIZE];


/**
 * Load presets from presets file
 *
 * presets -> a pointer to a a lists of heap allocated structs
 * config_dir_path -> string to the configs dir
 */
bool load_presets(presets_list* presets, const char* config_dir_path);

/**
 * PRIVATE:
 * With the entry load a preset into the nextopen slot in the presets array
 */
static bool get_preset(preset_t* preset, struct dirent* entry, const char* config_file_path);

void show_preset(preset_t* preset);

void show_entry(entry_t* entry);

/**
 * convert a line from a config file to be an entry type
 */
static bool format_config_line(entry_t** pair, char* line);

#endif