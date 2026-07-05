#include "structure.h"

#warning "ALL CREATED FILES CURRENTLY APPEAR IN <test/> PLEASE REMOVE FOR PRODUCTION"
bool make_file(const char* path, const char* name, const char* boilerplate) {
    char* fullpath;
    asprintf(&fullpath, "test/%s/%s", (path ? path : "."), name);

    FILE* file = fopen(fullpath, "w");
    if (file == NULL) {
        printf("Error creating file\n");
        return false;
    }

    if (boilerplate != NULL) {
        fprintf(file, boilerplate);
    }

    fclose(file);
    printf("file \"%s\" created successfully\n", fullpath);
    free(fullpath);
    return true;
}

#warning "ALL CREATED DIRECTORIES CURRENTLY APPEAR IN <test/> PLEASE REMOVE FOR PRODUCTION"
bool make_dir(const char* path, const char* name) {
    char* filepath = NULL;
    asprintf(&filepath, "test/%s/%s", (path ? path : "."), name);
    printf("makinf dir: %s\n", filepath);

    // check path exists

    if (CREATE_DIR(filepath) == -1) {
        printf("^ Error creating directory ^\n");
        free(filepath);
        return false;
    }

    free(filepath);
}
