#include "presets.h"

bool load_presets(preset_node** presets_head, const char* config_file_path) {
    // open dir
    DIR* dir = opendir(config_file_path);
    if (dir == NULL) {
        fprintf(stderr, "Failed to open config directory");
        return false;
    }

    // for entry in dir read all lines to preset_t->entries
    struct dirent* entry = NULL;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') continue;
        printf("found entry: %s\n", entry->d_name);

        preset_t* preset = (preset_t*)malloc(sizeof(preset_t));
        get_preset(preset, entry, config_file_path);
        append_preset(presets_head, *preset);

        free(preset); // ? append struct copies data
    }

    closedir(dir);
    return true;
}

static char* get_preset_path(
    char* combined, const char* name, const char* config_file_path, const char* file_type
) {
    if (combined == NULL) {
        fprintf(stderr, "error allocating memory for file path");
        return false;
    }

    strcpy(combined, config_file_path);
    strcat(combined, name);
    strcat(combined, file_type); 
    printf("path: %s\n", combined);
}

static void get_preset_name(char** name, struct dirent* entry) {
    // get filename for language
    char buffer[MAX_PRESET_NAME_LENGTH];
    int deliminater_position = (strlen(entry->d_name) - FILE_TYPE_LENGTH);

    int required_size = strlen(entry->d_name) + 1;
    *name = (char*)malloc(required_size);

    strncpy(buffer, entry->d_name, deliminater_position);
    buffer[deliminater_position] = '\0';
    strcpy(*name, buffer);
}

static bool get_preset(preset_t* preset, struct dirent* entry, const char* config_file_path) {
    // show_preset(preset);
    char* name = NULL;
    get_preset_name(&name, entry);
    preset->lang = name;
    printf("name: %s\n", name);

    char* full_path = (char*)malloc(
        (strlen(config_file_path) + strlen(name) + FILE_TYPE_LENGTH + 1)
    );
    get_preset_path(full_path, name, config_file_path, ".cfg");

    FILE* file = fopen(full_path, "r");
    if (file == NULL) {
        fprintf(stderr, "PRESET FILE DOES NOT EXIST?\n");
        return false;
    }
    

    entry_vec_t entries;
    init_entry_vec(&entries);

    entry_t* config_line = NULL;
    
    char* line = NULL;
    size_t len = 0;
    ssize_t read = 0;
    while ((read = getline(&line, &len, file)) != -1) {
        printf("line: %s", line);
        
        config_line = (entry_t*)malloc(sizeof(entry_t));
        format_entry(&config_line, line);
        show_entry(config_line);
        // return to preset
        // add to an array of entries
        // need help here moving data from config line into array maybe via copy?
        // use a deep copy
        entry_t current_entry = {
            .name = config_line->name,
            .boilerplate = config_line->boilerplate,
        };
        add_entry(&entries, current_entry);

        free(config_line);
        config_line = NULL;
    }

    free(line);
    fclose(file);
    free(full_path);

    preset->entries = entries;
    return true;
}

static bool format_entry(entry_t** pair, char* line) {
    char* name = NULL;
    char* boilerplate = NULL;

    // Remove first character
    if (strlen(line) > 0) {
        memmove(line, line + 1, strlen(line));
    }

    // Remove 2 characters (newline and quote)
    int len = strlen(line);
    if (len > 0) {
        line[len - 2] = '\0';
    }

    const char* delimiter = "\", \"";
    char* split_point = strstr(line, delimiter);

    if (split_point == NULL) {
        // No delimiter: entire line is the name
        //! Dir
        name = line;
        boilerplate = NULL;
    } else {
        //! File
        // Split into name and boilerplate
        *split_point = '\0';
        boilerplate = split_point + strlen(delimiter);
        name = line;
    }

    (*pair)->name = strdup(name);
    if (boilerplate != NULL) {
        (*pair)->boilerplate = strdup(boilerplate);
    } else {
        (*pair)->boilerplate = NULL;
    }

    return true;
}