#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define DEFAULT_LINE_SIZE 1024
#define DEFAULT_LINE_COUNT 10

void printTail(char tail[][DEFAULT_LINE_SIZE+1], int lineCount){
   for(int i = lineCount-1; i >= 0; i--){
      printf("%s", tail[i]);
      if(strchr(tail[i], '\n') == NULL)
         printf("\n");
   }
}

void pushTail(char tail[][DEFAULT_LINE_SIZE+1], int lineCount){
   for(int i = lineCount-1; i > 0; i--){
      memcpy(tail[i], tail[i-1], DEFAULT_LINE_SIZE+1);
   }
}

void loadTail(char tail[][DEFAULT_LINE_SIZE+1], int lineCount, FILE *file){
   char line[DEFAULT_LINE_SIZE+1];
   int firstExceed = 0, firstExcInLine = 0; // 0 == FALSE 1==TRUE
   while(fgets(line, DEFAULT_LINE_SIZE+1, (file==NULL) ? stdin : file)){
      if(firstExcInLine == 0) {
         pushTail(tail, lineCount);
         memcpy(tail[0], line, DEFAULT_LINE_SIZE + 1);
      }
      if(strchr(line, '\n') == NULL || firstExcInLine == 1){
         if(firstExceed == 0)
            perror("Line exceeds limit of number of character, continue reading only limit of chars from line");

         firstExceed = 1;
         firstExcInLine = 1;
         if(strchr(line, '\n') != NULL)
            firstExcInLine = 0;
      }
   }
}

int main(int argc, char **argv) {
   errno = 0;
   int lineCount = DEFAULT_LINE_COUNT;
   FILE *file = NULL;

   if(argc == 1)
      lineCount = DEFAULT_LINE_COUNT;
   else if(argc == 2){
      file = fopen(argv[1], "r");
      if(file == NULL){
         perror("File not opened. Exiting");
         exit(-1);
      }
   }
   else if((argc == 3 || argc == 4) && (!strcmp(argv[1], "-n"))){
      if(argc == 4){
         file = fopen(argv[3], "r");
         if(file == NULL){
            perror("File not opened. Exiting");
            exit(-1);
         }
      }

      char *ptr;
      lineCount = (int) strtol(argv[2], &ptr, 10);
      if ((ptr == argv[2]) || (*ptr != '\0') || lineCount < 0 || errno != 0) {
         perror("Wrong format of argument, program continues using default line count");
         lineCount = DEFAULT_LINE_COUNT;
      }
   }
   else
      perror("Wrong arguments entered, ending program");

   char tail[lineCount][DEFAULT_LINE_SIZE+1];

   loadTail(&tail[0], lineCount, file);
   printTail(&tail[0], lineCount);

   if(file != NULL)
      fclose(file);

   return 0;
}