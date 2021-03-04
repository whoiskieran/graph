#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "graph.h"
/**
*
* Test 1 use adjency matrix
* Test 1 use 1 direction only
*
**/
int main(int argc, char *argv[]) {
  graph G;
  int no_e =3; int no_v=3; int distance=0;
  char output_str[512];  
  if (init_G(&G,no_e,no_v)==-1){return log_error("function init_G failed to create graph.");}
  
  for (int i=0;i < no_v;i++){   
    // The id of the vertix is irrelivent for this test.    
    if (add_v(&G,i,i)==-1){return log_error("function add_v failed to add a vertix");}
  }
  // Create a triangel graph v0 connects to v1, v1 connects to v2, v2 connects to v0 
  for (int i=0; i< no_v; i++){
    sprintf(output_str,"function add_e failed to add edge=%d start_vertix=%d end_vertix=%d",i,i,(i+1)); 
    if ((i+1)==no_v){
       if (add_e(&G,i, i, 0, 1, 17, 17,-1)==-1){return log_error(output_str);}
    } else {
      if (add_e(&G,i, i, (i+1), 1, 17, 17,-1)==-1){return log_error(output_str);}
    } // end if ((i+1)==no_v)   
  }
  if (set_adj(&G,true)!=true){return log_error("function set_adj failed");}
    
  for (int i=0; i< (no_v-1); i++){
  /**
  * The distance between these should be 0 as they are adjacent
  **/
    distance = v_distance(&G,i,(i+1));
    sprintf(output_str,"\nGet Distance between vertix %d,%d is %d \n",i,(i+1),distance);
    if (distance !=0){return log_error(output_str);}
  }
  return 0;
}
