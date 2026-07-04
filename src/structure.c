#include "structure.h"

bool make_file(const char* path, const char* name, const char* boilerplate) {
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

bool make_dir(const char* path, const char* name) {
    char* filepath = NULL;
    size_t size = 0;

    if (CREATE_DIR(name) == -1) {
        printf("Error creating directory");
        return false;
    }
}
