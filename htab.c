/*
 * Subor:      htab
 * Autor:      Tomas Kozar, xkozar02
 * Skola:      Vysoke uceni technicke v Brne
 * Fakulta:    Fakulta informacnich technologii, FIT
 * Datum:      20.04.2018
 */

#include "htab.h"

struct tab{
    unsigned int size; //total number of items in table
    unsigned int arr_size; //number of pointers in table
    struct htab_item *ptr[];
};

