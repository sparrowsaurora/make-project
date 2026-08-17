#include "presets.h"

bool load_presets(presets_list* presets, const char* config_file_path) {
    // open dir
    DIR* dir = opendir(config_file_path);

    // if null == fail
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

        free(preset); // ? might not need this here temp measure
    }

    closedir(dir);
    return true;
}

static bool get_preset(preset_t* preset, struct dirent* entry, const char* config_file_path) {
    // get filename for language
    char name[MAX_PRESET_NAME_LENGTH];
    int deliminater_position = (strlen(entry->d_name) - FILE_TYPE_LENGTH);
    strncpy(name, entry->d_name, deliminater_position);
    name[deliminater_position] = '\0';
    preset->lang = name;

    printf("name: %s\n", name);

    // show_preset(preset);

    // get entries {name, boilerplate}
    int required_size = strlen(config_file_path) + strlen(name) + 1;
    char* combined = (char*)malloc(required_size);

    if (combined == NULL) {
        fprintf(stderr, "error allocating memory for file path");
        return false;
    }

    strcpy(combined, config_file_path);
    strcat(combined, entry->d_name);

    printf("path: %s\n", combined);

    FILE* file = fopen(combined, "r");
    if (file == NULL) {
        fprintf(stderr, "PRESET FILE DOES NOT EXIST?");
        return false;
    }

    // entry_t* entries[MAX_ENTRIES];

    entry_t* config_line = NULL;
    
    char* line = NULL;
    size_t len = 0;
    ssize_t read = 0;
    short iter = 0;
    while ((read = getline(&line, &len, file)) != -1) {
        printf("line: %s", line);
        
        config_line = (entry_t*)malloc(sizeof(entry_t));
        format_config_line(&config_line, line);
        show_entry(config_line);
        // return to preset
        // add to an array of entries
        

        free(config_line);
        config_line = NULL;
        
        iter++;
    }
    free(line);
    fclose(file);
    free(combined);

    return true;
}

static bool format_config_line(entry_t** pair, char* line) {
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

    (*pair)->name = name;
    (*pair)->boilerplate = boilerplate;

    return true;
}

void show_preset(preset_t* preset) { printf("Langauge: %s\n", preset->lang); }

void show_entry(entry_t* entry) {
    printf(
            "{\n\tname: %s, \n\tboilerplate: %s\n}\n", 
            entry->name, 
            (entry->boilerplate ? entry->boilerplate : "NULL")
        );
}