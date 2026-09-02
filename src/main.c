#include "options.h"
#include "presets.h"
#include "structure.h"

#define ENV_PRESETS_DIR_NAME "MP_PRESETS_DIR"

const char* getPresetsDir() {
    // check env
    const char* presetsDir = getenv(ENV_PRESETS_DIR_NAME);
    if (!presetsDir) {
        fprintf(stderr, "\"MP_PRESETS_DIR\" is not defined as an environment variable");
        exit(EXIT_FAILURE);
    }
    return presetsDir;
}



int main(int argc, char** argv) {
    const char* PRESETS_DIR = getPresetsDir();

    // add manual

    // options opts;
    // get_options(&opts, argc, argv);

    // show_opts(&opts);
    
    preset_node* presets_head = NULL;
    if (false == load_presets(&presets_head, PRESETS_DIR)) {
        fprintf(stderr, "Error Loarding presets");
        exit(EXIT_FAILURE);
    }

    printf("presets loaded\n");

    print_list(presets_head);

    // select preset here
    preset_t* preset = &presets_head->next->preset;
    show_preset(preset);

    if (false == build(preset)) {
        fprintf(stderr, "Error Building starter project");
        exit(EXIT_FAILURE);
    }

    printf("success\n");

    free_preset_list(presets_head);
    return EXIT_SUCCESS;
}
