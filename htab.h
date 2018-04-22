#ifndef HTAB_H
#define HTAB_H

#include <stdbool.h>
#include <stddef.h>
#include <malloc.h>
#include <string.h>

#define MAX_KEY_SIZE 127

typedef struct htab_item{
    char *key;
    unsigned int data; //count
    struct htab_item *next;
}htab_item;

typedef struct tab {
   unsigned int size; //total number of items in table
   unsigned int arr_size; //number of pointers in table
   struct htab_item *ptr[];
}htab;

/**
 * Initializes hash table
 * @param size size of pointer array
 * @return initialized hash table, if init failed returns NULL
 */
htab *htab_init(unsigned int size);

/**
 * Copies content of hash table into another one. Copied hash table is cleared
 * @param newsize size of new hash table
 * @param t2 hash table to be copied
 * @return copy of hash table, if error ocured -> NULL
 */
htab *htab_move(unsigned int newsize, htab *t2);

/**
 * Return number of items
 * @param t hash table
 * @return number of items
 */
unsigned int htab_size(htab t);

/**
 * Return number of pointers
 * @param t hash table
 * @return size of pointer array
 */
unsigned int htab_bucket_count(htab t);

/**
 * Looks for item in hash table. If item is not found, it will be created
 * @param t hash table
 * @param key
 * @return returns pointer to item
 */
struct htab_item *htab_lookup_add(htab *t, char *key);

/**
 * Looks for item in hash table.
 * @param t
 * @param key
 * @return pointer to item. If item is not found -> NULL
 */
struct htab_item *htab_find(htab *t, char *key);

/**
 * Calls function on all elements of hash table
 * @param func function pointer of function which will be used
 */
void htab_foreach(htab *t, void (*func)(char *, unsigned int *));

/**
 * Look up and deletion of item
 * @param t hash table'
 * @param key
 * @return true if removed succesfuly, false if key was not found
 */
bool htab_remove(htab *t, char *key);

/**
 * Clears all items from hash table
 * @param t hash table to be cleared
 */
void htab_clear(htab *t);


/**
 * Deconstructor. Frees table pointer
 * @param t table to be deconstructed
 */
void htab_free(htab *t);

/**
 * Hash function for generating idexes. To get index, use modulo arr_size of returned value
 * @param str key for hashing
 * @return hash
 */
unsigned int htab_hash_function(const char *str);

#endif