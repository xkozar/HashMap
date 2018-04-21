/*
 * Subor:      io
 * Autor:      Tomas Kozar, xkozar02
 * Skola:      Vysoke uceni technicke v Brne
 * Fakulta:    Fakulta informacnich technologii, FIT
 * Datum:      21.04.2018
 */
#include "io.h"
#include <string.h>

int get_word(char *s, int max, FILE *f){
   if(f == NULL) return 0;

   char input_word[max];

   int c = getc(f);

   int count = 0; //Number of chars in input_word

   while(c != EOF){
      if(isspace(c)){
         if(count != 0){
            input_word[count] = '\0';
            strcpy(s, input_word);
            return count;
         }
      }
      else{
         if(count < max-1){
            input_word[count] = c;
            count ++;
         }
      }
      c = getc(f);
   }

   input_word[count] = '\0';
   strcpy(s, input_word);
   return c;


}
