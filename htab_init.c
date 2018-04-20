/*
 * Subor:      htab_init.c
 * Autor:      Tomas Kozar, xkozar02
 * Skola:      Vysoke uceni technicke v Brne
 * Fakulta:    Fakulta informacnich technologii, FIT
 * Datum:      19.4.2018
 */

#include "htab.h"

htab *htab_init(unsigned int size){
   htab *hash_table = NULL;

   hash_table = (htab *) malloc(sizeof(htab) + sizeof(struct htab_item *) * size);

   if(hash_table == NULL)
      return NULL;

   hash_table -> arr_size = size;
   hash_table -> size = 0;

   for(int i = 0; i < size; i++)
      hash_table -> ptr[i] = NULL;

   return hash_table;
}
