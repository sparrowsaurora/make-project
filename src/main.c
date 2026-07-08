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

    preset_t** presets = NULL;  // pointer to array of presets
    if (load_presets(presets, PRESETS_DIR) == false) {
        fprintf(stderr, "Error Loarding presets");
        exit(EXIT_FAILURE);
    }

    free(presets);
    return EXIT_SUCCESS;
}
