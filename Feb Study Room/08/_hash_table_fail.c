#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    int key;
    int value;
} Entry;

typedef struct {
    Entry* entries;
    size_t capacity;
    size_t length;
} NumberContainers;

#define INITIAL_CAPACITY 16

NumberContainers* numberContainersCreate() {
    NumberContainers* table = (NumberContainers*)malloc(sizeof(NumberContainers));
    if (table == NULL) { return NULL; }

    table->length = 0;
    table->capacity = INITIAL_CAPACITY;
    table->entries = calloc(table->capacity, sizeof(NumberContainers));
    if (table->entries == NULL) { free(table); return NULL; }

    for (size_t i = 0; i < table->capacity; i++) {
        table->entries[i].key = -1;
    }
    return table;
}

void numberContainersChange(NumberContainers* obj, int index, int number) {
    if (obj == NULL || index < 0) { return; }
    if (obj->length * 10 / obj->capacity >= 7) { resize(obj); };

    uint64_t hash = hash_key(index);
    size_t i = 0;
    size_t position = (size_t)(hash % obj->capacity);

    while (obj->entries[position].key != -1) {
        if (obj->entries[position].key == index) {
            obj->entries[position].value = number; return; }

        i++;
        position = (position + i * i) % obj->capacity;
        if (index >= obj->capacity) { return; }
    }
    obj->entries[position].key = index;
    obj->entries[position].value = number;
    obj->length++;
}

int numberContainersFind(NumberContainers* obj, int number) {
    if (obj == NULL) { return -1; }
    
    uint64_t hash = hash_key(number);
    size_t index = (size_t)(hash & (obj->capacity));
    size_t i = 0;

    while (obj->entries[index].key != -1) {
        if (obj->entries[index].key == number) { return obj->entries[index].value; }
        i++;

        index = (index + i * i) % obj->capacity;
        if (index >= obj->capacity) { break; }
    }
    return -1;
}

void numberContainersFree(NumberContainers* obj) {
    free(obj->entries);
    free(obj);
}

void resize(NumberContainers* obj) {
    size_t new_capacity = obj->capacity * 2;
    Entry* new_entries = calloc(new_capacity, sizeof(Entry));
    if (new_entries == NULL) {return; }

    for (size_t i = 0; i < obj->capacity; i++) {
        if (obj->entries[i].key != 1) {
            uint64_t hash = hash_key(obj->entries[i].key);
            size_t new_index = hash % new_capacity;

            while (new_entries[new_index].key != -1) {
                new_index = (new_index + 1) % new_capacity;
            }
            new_entries[new_index] = obj->entries[i];
        }
    }
    free(obj->entries);
    obj->entries = new_entries;
    obj->capacity = new_capacity;
}