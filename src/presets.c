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
        printf("%s\n", entry->d_name);
        preset_t* preset = (preset_t*)malloc(sizeof(preset_t));
        get_preset(preset, entry, config_file_path);
        free(preset);
    }

    closedir(dir);
    return true;
}

static bool get_preset(preset_t* preset, struct dirent* entry, const char* config_file_path) {
    // get filename for language
    char name[MAX_PRESET_NAME_LENGTH];
    short deliminater_position = (strlen(entry->d_name) - FILE_TYPE_LENGTH);
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

    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, file)) != -1) {
        printf("%s", line);
    }
    free(line);
    fclose(file);
    free(combined);

    return true;
}

void show_preset(preset_t* preset) { printf("Langauge: %s\n", preset->lang); }
