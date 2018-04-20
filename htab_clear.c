/*
 * Subor:      htab_clear
 * Autor:      Tomas Kozar, xkozar02
 * Skola:      Vysoke uceni technicke v Brne
 * Fakulta:    Fakulta informacnich technologii, FIT
 * Datum:      20.04.2018
 */

#include "htab.h"

void htab_clear(htab *t){
   if(t == NULL) return;

   int count = htab_bucket_count(*t);
   for(int i = 0; i < count; i++){
      struct htab_item *current = t -> ptr[i];//na5nana
      struct htab_item tmp;
      for(; current != NULL; current = tmp.next){
         tmp = *current;
         htab_remove(t, current -> key);
      }
   }
}
