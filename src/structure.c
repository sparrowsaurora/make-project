#include "structure.h"

#warning "ALL CREATED FILES CURRENTLY APPEAR IN <test/> PLEASE REMOVE FOR PRODUCTION"
static bool make_file(const char* path, const char* boilerplate) {
    char* fullpath = NULL;
    asprintf(&fullpath, "test/%s", path);

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
static bool make_dir(const char* path) {
    char* filepath = NULL;
    asprintf(&filepath, "test/%s", path);
    printf("making dir: %s\n", filepath);

    // check path exists

    if (CREATE_DIR(filepath) == -1) {
        printf("^ Error creating directory ^\n");
        free(filepath);
        return false;
    }

    free(filepath);
    return true;
}

static void router(const char* path, const char* boilerplate) {
    int len = strlen(path);
    char last_char;

    if (len > 0) {
        last_char = path[len - 1];
    } else {
        fprintf(stderr, "Path passed to helper does not have a known length");
        exit(EXIT_FAILURE);
    }

    if (last_char == '/') {
        // is dir
        // if has_boilerplate -> error
        if (boilerplate != NULL) {
            fprintf(stderr,
                    "calling \"make\" with a directory type path & boilerplate is not allowed");
            exit(EXIT_FAILURE);
        }

        // else make_dir
        if (make_dir(path) == false) {
            fprintf(stderr, "Error creating directory \"%s\"", path);
            exit(EXIT_FAILURE);
        }
        // to fix
    } else {
        if (make_file(path, boilerplate) == false) {
            fprintf(stderr, "Error creating file \"%s\"", path);
            exit(EXIT_FAILURE);
        }
    }
}

bool make_without_boilerplate(const char* path) { router(path, NULL); }
bool make_with_boilerplate(const char* path, const char* boilerplate) { router(path, boilerplate); }