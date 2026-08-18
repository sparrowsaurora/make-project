#include "types.h"

void init_entry_vec(entry_vec_t* v) {
    v->size = 0;
    v->capacity = 4;
    v->data = malloc(v->capacity * sizeof(entry_t));
    if (v->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}

void add_entry(entry_vec_t* v, entry_t entry) {
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        entry_t *new_data = realloc(v->data, v->capacity * sizeof(entry_t));
        if (new_data == NULL) {
            fprintf(stderr, "Memory reallocation failed!\n");
            exit(1);
        }
        v->data = new_data;
    }
    // Insert the value and increment size
    v->data[v->size] = entry;
    v->size++;
}

entry_t get_entry(entry_vec_t* v, size_t i) {
    if (i >= v->size) {
        fprintf(stderr, "Index out of bounds!\n");
        exit(1);
    }
    return v->data[i];
}

void free_entry_vec(entry_vec_t* v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}



preset_node* create_preset_list(preset_t preset) {}

void append_preset(preset_node** head, preset_t preset) {}

void free_preset_list(preset_node* head) {}