#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "graph.h"


int main(int argc, char *argv[]) {
  graph G1,G2,G3;
  int no_e =3; int no_v=3;
  char output_str[512];  
  if (init_G(&G1,no_e,no_v)==-1){return log_error("function init_G failed to create graph. 1");}
  if (init_G(&G2,no_e,no_v)==-1){return log_error("function init_G failed to create graph. 2");}
  
  
  for (int i=0;i < no_v;i++){   
    // The id of the vertix is irrelivent for this test.    
    if (add_v(&G1,i,i)==-1){return log_error("function add_v failed to add a vertix G1");}
    if (add_v(&G2,i,i)==-1){return log_error("function add_v failed to add a vertix G2");}
  }
  // Create a triangel graph v0 connects to v1, v1 connects to v2, v2 connects to v0 
  for (int i=0; i< no_v; i++){
    sprintf(output_str,"function add_e failed to add edge=%d start_vertix=%d end_vertix=%d",i,i,(i+1)); 
    if ((i+1)==no_v){
       if (add_e(&G1,i, i, 0, 2, 17, 17,-1)==-1){return log_error(output_str);}
       if (add_e(&G2,i, i, 0, 2, 17, 17,-1)==-1){return log_error(output_str);}       
    } else {
      if (add_e(&G1,i, i, (i+1), 2, 17, 17,-1)==-1){return log_error(output_str);}
      if (add_e(&G2,i, i, (i+1), 2, 17, 17,-1)==-1){return log_error(output_str);}
    } // end if ((i+1)==no_v)   
  }
  /**
  * combine G1 and G2 producing G3
  * G3 will be joined on v0 first vertix of G1 and v5 last vertix of G2
  * direction = 2 and weight are both set to 0
  **/
  G3 = combine_g(&G1,&G2,0,2,2,0,0);
  fprintf(stderr,"\ng3.no_e=%ld\n",G3.no_e);  
  disp_graph(&G3,G3.no_e,G3.no_v);
  return 0;
}
