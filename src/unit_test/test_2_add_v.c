#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "graph.h"

/**
Test to ensure each vertix has a uique id.
If it allows 2 ertacies with the same id return anerror.
**/

int main(int argc, char *argv[]) {
  graph G;
  int no_e =10; int no_v=10;
    
  if (init_G(&G,no_e,no_v) !=0){return log_error("function init_G failed to create a graph");}
  
  for (int i=0;i < no_v;i++){
   // The id of the vertix is irrelivent for this test.
    if (add_v(&G,i,i)==-1){return log_error("function add_v failed to add a vertix");}
  }
  // This shuld fail as it is adding the same vertix twice.
  if (add_v(&G,0,0) !=-1){return log_error("function add_v failed it added a vertix with a non unique id");}
   
  return 0;
}
