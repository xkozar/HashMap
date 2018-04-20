/*
 * Subor:      htab_find
 * Autor:      Tomas Kozar, xkozar02
 * Skola:      Vysoke uceni technicke v Brne
 * Fakulta:    Fakulta informacnich technologii, FIT
 * Datum:      20.04.2018
 */

#include "htab.h"

struct htab_item *htab_find(htab *t, char *key){
   if(t == NULL) return NULL;

   int index = htab_hash_function(key) % htab_bucket_count(*t);
   struct htab_item *current = t -> ptr[index];

   while(current != NULL){
      if(strcmp(current -> key, key) == 0) {
         return current;
      }

      current = current -> next;
   }

   return NULL;
}