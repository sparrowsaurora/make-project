#include "structure.h"

/**
 * creats a file object
 */
bool make_file(const char* name, const char* boilerplate) {
    FILE* file = fopen(name, "w");
    if (file == NULL) {
        printf("Error creating file");
        return false;
    }

    if (boilerplate != NULL) {
        fprintf(file, boilerplate);
    }
    fclose(file);
    printf("file \"%s\" created successfully", name);
    return true;
}

/**
 * creats a directory object
 */
bool make_dir(const char* name) {
    char* filepath = NULL;
    size_t size = 0;
    CREATE_DIR(name);
}
