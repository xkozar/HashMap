/*
 * Subor:      htab_free
 * Autor:      Tomas Kozar, xkozar02
 * Skola:      Vysoke uceni technicke v Brne
 * Fakulta:    Fakulta informacnich technologii, FIT
 * Datum:      20.04.2018
 */

#include "htab.h"

void htab_free(htab *t){
   if(t == NULL) return;

   htab_clear(t);
   free(t);
}
