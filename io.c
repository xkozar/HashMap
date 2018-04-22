/*
 * Subor:      io
 * Autor:      Tomas Kozar, xkozar02
 * Skola:      Vysoke uceni technicke v Brne
 * Fakulta:    Fakulta informacnich technologii, FIT
 * Datum:      21.04.2018
 */
#include "io.h"
#include <string.h>
#include <stdbool.h>

int get_word(char *s, int max, FILE *f){
   static bool first_longer = true;
   if(f == NULL) return EOF;

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
         if(count < max){
            input_word[count] = c;
            count ++;
         }
         else if(first_longer == true){
            perror("Key is too long, shortening it to fit max size.");
            first_longer = false;
         }
      }
      c = getc(f);
   }

   if(count != 0){
      input_word[count] = '\0';
      strcpy(s, input_word);
   }
   return c;


}
