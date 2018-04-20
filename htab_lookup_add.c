/*
 * Subor:      htab_lookup_add
 * Autor:      Tomas Kozar, xkozar02
 * Skola:      Vysoke uceni technicke v Brne
 * Fakulta:    Fakulta informacnich technologii, FIT
 * Datum:      20.04.2018
 */

#include "htab.h"

struct htab_item *htab_lookup_add(htab *t, char *key){
   if(t == NULL) return NULL;

   int index = htab_hash_function(key) % htab_bucket_count(*t);
   struct htab_item *previous = NULL;
   struct htab_item *current = t -> ptr[index];

   while(current != NULL){
      if(strcmp(current -> key, key) == 0) {
         current -> data++;
         return current;
      }

      previous = current;
      current = current -> next;
   }

   current = (struct htab_item *) malloc(sizeof(struct htab_item));
   if(current == NULL) return NULL;

   current -> key = (char *) malloc(sizeof(char) * (strlen(key)+1));
   if(current -> key == NULL){
      free(current);
      return NULL;
   }

   t -> size++;
   current -> data = 1;
   strcpy(current -> key, key);
   current -> next = NULL;
   if(t -> ptr[index] == NULL)
      t -> ptr[index] = current;
   else
      previous -> next = current;

   return current;
}