// #include <stdio.h>
// #include <stdlib.h>

#include "options.h"
#include "presets.h"
#include "structure.h"


#define PRESETS_DIR "./presets/"

int main(int argc, char** argv) {
    // options opts;
    // get_options(&opts, argc, argv);

    // show_opts(&opts);
    
    preset_node* presets_head = NULL;

    if (load_presets(&presets, PRESETS_DIR) == false) {
        fprintf(stderr, "Error Loarding presets");
        exit(EXIT_FAILURE);
    }

    // select preset here
    // preset_t preset = ...
    if (build(&presets) == false) {
        fprintf(stderr, "Error Building starter project");
        exit(EXIT_FAILURE);
    }

    free_preset_list(presets_head);
    return EXIT_SUCCESS;
}
