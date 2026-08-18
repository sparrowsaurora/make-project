#ifndef TYPES_H
#define TYPES_H

#include <stdlib.h>
#include <stdio.h> 

typedef struct {
    const char* name;
    const char* boilerplate;
} entry_t;

typedef struct preset_t {
    const char* lang;
    const entry_vec_t entries;
} preset_t;

// preset_list is now preset_node* head

// entries = vector

typedef struct {
    entry_t* data;
    size_t size;
    size_t capacity;
} entry_vec_t;

void init_entry_vec(entry_vec_t* v);

void add_entry(entry_vec_t* v, entry_t entry);

entry_t get_entry(entry_vec_t* v, size_t i);

void free_entry_vec(entry_vec_t* v);

// preset_list = linked_list

typedef struct {
    preset_t preset;
    struct preset_node* next;
} preset_node;

preset_node* create_preset_list(preset_t preset);

void append_preset(preset_node** head, preset_t preset);

void free_preset_list(preset_node* head);


#endif