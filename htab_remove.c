/*
 * Subor:      htab_remove
 * Autor:      Tomas Kozar, xkozar02
 * Skola:      Vysoke uceni technicke v Brne
 * Fakulta:    Fakulta informacnich technologii, FIT
 * Datum:      20.04.2018
 */

#include "htab.h"

bool htab_remove(htab *t, char *key){
   if(t == NULL) return false;

   struct htab_item *item = htab_find(t, key);
   if(item == NULL) return false;

   unsigned int index = htab_hash_function(key) % htab_bucket_count(*t);

   if(t -> ptr[index] == item){
      t -> ptr[index] = item -> next;
      free(item -> key);
      free(item);
      t -> size--;
      return true;
   }
   for(struct htab_item *i = t -> ptr[index]; i -> next != NULL; i = i -> next){
      if(i -> next == item){
         i -> next = item -> next;
         free(item -> key);
         free(item);
         t -> size--;
         return true;
      }
      i -> next = item -> next;
   }
   return false;
}