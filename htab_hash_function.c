/*
 * Subor:      htab_hash_function.c
 * Autor:      Tomas Kozar, xkozar02
 * Skola:      Vysoke uceni technicke v Brne
 * Fakulta:    Fakulta informacnich technologii, FIT
 * Datum:      20.04.2018
 */

#include "htab.h"

unsigned int htab_hash_function(const char *str) {
   unsigned int h=0;     // 32bit
   const unsigned char *p;
   for(p=(const unsigned char*)str; *p!='\0'; p++)
      h = 65599*h + *p;
   return h;
}