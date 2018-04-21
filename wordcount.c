//
// Created by kozar on 18.04.2018.
//
#include <stdio.h>
#include "htab.h"
#include "io.h"

#define HTAB_ARR_SIZE 1000000000

void print_word(char *key, unsigned int *val){
   printf("%s %u\n", key, *val);
}

int main(){
   FILE *file = fopen("C:\\Users\\kozar\\CLionProjects\\HashMap\\Test", "r");

   htab *table = htab_init(HTAB_ARR_SIZE);

   char word[127];

   while(get_word(word, 127, file) != EOF){
      htab_lookup_add(table, word);
   }
   htab_lookup_add(table, word);

   htab_foreach(table, print_word);
   htab_free(table);
   return 0;
}