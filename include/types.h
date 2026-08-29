#ifndef TYPES_H
#define TYPES_H

#include <stdlib.h>
#include <stdio.h> 

#define BOILERPLATE_IS_NULL "NULL"

typedef struct {
    char* name;
    char* boilerplate;
} entry_t;

typedef struct {
    entry_t* data;
    size_t size;
    size_t capacity;
} entry_vec_t;

// entries = vector
typedef struct preset_t {
    char* lang;
    entry_vec_t entries;
} preset_t;

void init_entry_vec(entry_vec_t* v);

void add_entry(entry_vec_t* v, entry_t entry);

entry_t get_entry(entry_vec_t* v, size_t i);

void free_entry_vec(entry_vec_t* v);

// return the size of a select entry vec
size_t count_entries(entry_vec_t* v);

// preset_list = linked_list

typedef struct preset_node {
    preset_t preset;
    struct preset_node* next;
} preset_node;

static preset_node* create_preset_node(preset_t preset);

void append_preset(preset_node** head, preset_t preset);

void print_list(preset_node* head);

void free_preset_list(preset_node* head);

// return the total count of presets in the list
size_t count_nodes(preset_node* head);

void show_preset(preset_t* preset);

void show_entry(entry_t* entry);

#endif