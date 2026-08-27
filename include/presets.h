#ifndef PRESETS_H
#define PRESETS_H

/*
    Creates language presets from config files

    WARNING: THIS FILE IS NOT CROSS PLATFORM (LINUX ONLY)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

// file headers
#include <dirent.h>
#include <sys/types.h>

//todo: put these values in a global config?
//! COMPILATION ONLY (user may not edit)
#define FILE_TYPE_LENGTH 4
#define MAX_PRESET_NAME_LENGTH 64
#define BOILERPLATE_IS_NULL "NULL"


/**
 * Load presets from presets file
 *
 * presets -> a pointer to a a lists of heap allocated structs
 * config_dir_path -> string to the configs dir
 */
bool load_presets(preset_node* presets_head, const char* config_dir_path);

/**
 * PRIVATE:
 * With the entry load a preset into the nextopen slot in the presets array
 */
static bool get_preset(
    preset_t* preset, struct dirent* entry, const char* config_file_path
);

static void get_preset_name(char** name, struct dirent* entry);

static char* get_preset_path(
    char* combined, const char* name, const char* config_file_path, const char* file_type
);

void show_preset(preset_t* preset);

void show_entry(entry_t* entry);

/**
 * convert a line from a config file to be an entry type
 */
static bool format_entry(entry_t** pair, char* line);

#endif