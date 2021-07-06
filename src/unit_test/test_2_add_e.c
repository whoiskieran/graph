#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "graph.h"
/**
* This code tests the dynamic allocation of memory
* when a new edge is added after init process 
* this new edge is grater than the current edge no.
**/

int main(int argc, char *argv[]) {
  graph G;
  int no_e =3; int no_v=3;
  char output_str[512];  
  
  if (init_G(&G,no_e,no_v)==-1){return log_error("function init_G failed to create graph.");}
  set_adj(&G,true);
  
  for (int i=0;i < no_v;i++){   
    // The id of the vertix is irrelivent for this test.    
    if (add_v(&G,i,i)==-1){return log_error("function add_v failed to add a vertix");}
  }
  // Create a triangel graph v0 connects to v1, v1 connects to v2, v2 connects to v0 
  for (int i=0; i< no_v; i++){
    sprintf(output_str,"function add_e failed to add edge=%d start_vertix=%d end_vertix=%d",i,i,(i+1)); 
    if ((i+1)==no_v){
      if (add_e(&G,i, i, 0, 2, 17, 17, -1)==-1){return log_error(output_str);}
    } else {
      if (add_e(&G,i, i, (i+1), 2, 17, 17, -1)==-1){return log_error(output_str);}
    } // end if ((i+1)==no_v)   
  }
  // Make a self referencing node 
  // the test here is the edge number is grater than the original No edges.
  disp_graph(&G,no_e,no_v);
  fprintf(stdout,"\n");
  if (add_e(&G,3, 1, 1, 2, 17, 17,-1)==-1){return log_error(output_str);} 
  no_e++;
  disp_graph(&G,no_e,no_v);
  fprintf(stdout,"\n");
  return 0;
}
