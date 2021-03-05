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
    if (add_v(&G,i,i)==-1){return log_error("function add_v failed to add a vertix");}
  }
  // The id's will be unique so if -1 is not returned then the function is incorrect.
  if (v_has_uniq_id(&G) !=-1){log_error("function v_has_uniq_id failed it found non unique id's when there are none");}
  return 0;
}
