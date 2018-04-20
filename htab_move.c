/*
 * Subor:      htab_move
 * Autor:      Tomas Kozar, xkozar02
 * Skola:      Vysoke uceni technicke v Brne
 * Fakulta:    Fakulta informacnich technologii, FIT
 * Datum:      20.04.2018
 */

#include "htab.h"

htab *htab_move(unsigned int newsize, htab *t2){
   if(t2 == NULL) return NULL;

   htab *t1 = htab_init(newsize);

   if(t1 == NULL) return NULL;

   int count = htab_bucket_count(*t2);
   for(int i = 0; i < count; i++){
      struct htab_item *t2current = t2 -> ptr[i];

      for(; t2current != NULL; t2current = t2current -> next){
         struct htab_item *t1current = htab_lookup_add(t1, t2current -> key);
         if(t1current != NULL)
            t1current ->data = t2current -> data;
      }
   }
   htab_clear(t2);
   return t1;
}