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

// Preset list

static preset_node* create_preset_node(preset_t value) {
    preset_node* newNode = (preset_node*)malloc(sizeof(preset_node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); 
    }
    newNode->preset = value;
    newNode->next = NULL;
    return newNode;
}

void append_preset(preset_node** head, preset_t preset) {
    preset_node* newNode = create_preset_node(preset);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    preset_node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void print_list(preset_node* head) {
    preset_node* current = head;
    while (current != NULL) {
        printf("%s -> ", current->preset.lang);
        current = current->next;
    }
    printf("NULL\n");
}

void free_preset_list(preset_node* head) {
    preset_node* current = head;
    preset_node* nextNode;
    
    while (current != NULL) {
        nextNode = current->next;
        free_entry_vec(&current->preset.entries);
        free(current);
        current = nextNode;
    }
}