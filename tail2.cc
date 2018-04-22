#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <queue>

#define DEFAULT_LINE_COUNT 10

using namespace std;


void loadTail(queue <string> &tail, ifstream &file, int lineCount){
   string line;
   if(file.is_open())
      while(getline(file, line)){
         tail.push(line);
         if(tail.size() > (unsigned int) lineCount) tail.pop();
      }
   else
      while(getline(cin, line)){
         tail.push(line);
         if(tail.size() > (unsigned int) lineCount) tail.pop();
      }
}

void printTail(queue <string> &tail){
   int x = tail.size();
   for(int i = 0; i < x; i++){
      cout << tail.front() << endl;
      tail.pop();
   }
}

int main(int argc, char *argv[]) {
   ios::sync_with_stdio(false);
   int lineCount = DEFAULT_LINE_COUNT;
   ifstream file;
   errno = 0;
   if(argc == 1)
      lineCount = DEFAULT_LINE_COUNT;
   else if(argc == 2){
      file.open(argv[1], fstream::in);
      if(!file.is_open()){
         perror("File not opened. Exiting");
         exit(-1);
      }
   }
   else if((argc == 3 || argc == 4) && ((strcmp(argv[1], "-n") == 0))){
      if(argc == 4){
         file.open(argv[3], fstream::in);
         if(!file.is_open()){
            perror("File not opened. Exiting");
            exit(-1);
         }
      }
      char *ptr;
      lineCount = (int) strtol(argv[2], &ptr, 10);
      if ((ptr == argv[2]) || (*ptr != '\0') || (errno != 0)) {
         perror("Wrong format of argument, program continues using default line count");
         lineCount = DEFAULT_LINE_COUNT;
      }
   }
   else{
      perror("Wrong arguments entered, ending program");
      exit(-1);
   }

   queue<string> tail;
   loadTail(tail, file, lineCount);
   printTail(tail);
   return 0;
}