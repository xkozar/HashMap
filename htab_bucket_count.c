/*
 * Subor:      htab_size.c
 * Autor:      Tomas Kozar, xkozar02
 * Skola:      Vysoke uceni technicke v Brne
 * Fakulta:    Fakulta informacnich technologii, FIT
 * Datum:      19.04.2018
 */

#include "htab.h"

unsigned int htab_bucket_count(htab t){
   return t.arr_size;
}
