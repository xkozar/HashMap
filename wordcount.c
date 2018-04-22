//
// Created by kozar on 18.04.2018.
//
#include <stdio.h>
#include "htab.h"
#include "io.h"

#define HTAB_ARR_SIZE 10000

void print_word(char *key, unsigned int *val){
   printf("%s\t%u\n", key, *val);
}

int main(){
   //FILE *f = fopen("C:\\Users\\kozar\\CLionProjects\\HashMap\\Test", "r");

   htab *table = htab_init(HTAB_ARR_SIZE);
   if(table == NULL){
      perror("Table not allocated. Exiting.");
      return -1;
   }
   char word[MAX_KEY_SIZE + 1] = {'\0',};
   while(get_word(word, MAX_KEY_SIZE, stdin) != EOF){
      if(htab_lookup_add(table, word) == NULL){
         perror("Item in table not allocated. Exiting.");
         htab_free(table);
         return -1;
      }
      word[0] = '\0';
   }
   if(word[0] != '\0')
      if(htab_lookup_add(table, word) == NULL){
         perror("Item in table not allocated. Exiting.");
         htab_free(table);
         return -1;
      }
   htab_foreach(table, print_word);
   htab_free(table);
   return 0;
}