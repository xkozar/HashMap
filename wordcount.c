//
// Created by kozar on 18.04.2018.
//
#include <stdio.h>
#include "htab.h"

int main(){
   htab *table = htab_init(3);
   htab_lookup_add(table, "nanana");
   htab_lookup_add(table, "nanana");
   htab_lookup_add(table, "nan1ana");
   htab_lookup_add(table, "nan2ana");
   htab_lookup_add(table, "nan3ana");
   htab_lookup_add(table, "na5nana");
   htab_lookup_add(table, "na4nana");
   htab_lookup_add(table, "nan6ana");
   htab_lookup_add(table, "nana7na");

   htab *table2 = htab_move(1, table);
   htab_remove(table2, "na4nana");
   htab_clear(table2);

   htab_free(table);
   htab_free(table2);

   printf("%d", sizeof(long));

   return 0;
}