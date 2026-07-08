#include "presets.h"

bool load_presets(preset_t** presets, const char* config_file_path) {
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
        preset_t* preset = malloc(sizeof(preset_t));
        get_preset(preset, entry);
        show_preset(preset);
    }

    closedir(dir);
    return true;
}

static bool get_preset(preset_t* preset, struct dirent* entry) {
    int file_name_len = strlen(entry->d_name);

    char name[64];
    strncpy(name, 0, (file_name_len - FILE_TYPE_LENGTH));
    preset->lang = name;
    // free(name);
    return true;
}

void show_preset(preset_t* preset) { printf("Langauge: %s\n", preset->lang); }
