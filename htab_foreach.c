/*
 * Subor:      htab_foreach
 * Autor:      Tomas Kozar, xkozar02
 * Skola:      Vysoke uceni technicke v Brne
 * Fakulta:    Fakulta informacnich technologii, FIT
 * Datum:      20.04.2018
 */

#include "htab.h"

void htab_foreach(htab *t, void (*func)(char *, unsigned int *)){
   int count = htab_bucket_count(*t);
   for(int i = 0; i < count; i++){
      struct htab_item *current = t -> ptr[i];

      for(; current != NULL; current = current -> next){
         func(current -> key, &(current -> data));
      }
   }
}

