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

/**
 * Create Entry vector
 */
void init_entry_vec(entry_vec_t* v);

/**
 * Add entry to vector
 */
void add_entry(entry_vec_t* v, entry_t entry);

/**
 * get specific entry from vector by index
 */
entry_t get_entry(entry_vec_t* v, size_t i);

/**
 * Free all allocated memory inside the vector
 */
void free_entry_vec(entry_vec_t* v);

/**
 * return the size of a select entry vec
 */
size_t count_entries(entry_vec_t* v);

// preset_list = linked_list

typedef struct preset_node {
    preset_t preset;
    struct preset_node* next;
} preset_node;

/**
 * PRIVATE:
 * malloc a node for a preset and return the pointer to the memory
 */
static preset_node* create_preset_node(preset_t preset);

/**
 * add a new node to the linked list
 */
void append_preset(preset_node** head, preset_t preset);

/**
 * print the nodes in the list as languages they hold to stdout
 */
void print_list(preset_node* head);

/**
 * free every node in the presets linked list
 */
void free_preset_list(preset_node* head);

/**
 * return the total count of presets in the list
 */
size_t count_nodes(preset_node* head);

/**
 * print the specific preset from node to stdout
 */
void show_preset(preset_t* preset);

/**
 * print the specific entry from entry_list to stdout
 */
void show_entry(entry_t* entry);

#endif