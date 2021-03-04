#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "graph.h"

int main(int argc, char *argv[]) {
  graph G;
  graph G1;
  graph G2;  // G2 is fully connected 1 direction
  int no_e =3; int no_v=3;
  char output_str[512];  
  if (init_G(&G,no_e,no_v)==-1){return log_error("function init_G failed to create graph.");}
  if (init_G(&G1,no_e,no_v)==-1){return log_error("function init_G failed to create graph 1.");}
  if (init_G(&G2,6,no_v)==-1){return log_error("function init_G failed to create graph 2.");}
  
  
  for (int i=0;i < no_v;i++){   
    // The id of the vertix is irrelivent for this test.    
    if (add_v(&G,i,i)==-1){return log_error("G function add_v failed to add a vertix");}
    if (add_v(&G1,i,i)==-1){return log_error("G1 function add_v failed to add a vertix");}
    if (add_v(&G2,i,i)==-1){return log_error("G2 function add_v failed to add a vertix");}
  }
  // G is a triangel graph v0 connects to v1, v1 connects to v2, v2 connects to v0 
  // G1 is a triangle graph but only one direction.
  
  for (int i=0; i< no_v; i++){
    sprintf(output_str,"function add_e failed to add edge=%d start_vertix=%d end_vertix=%d",i,i,(i+1)); 
    if ((i+1)==no_v){
       if (add_e(&G,i, i, 0, 2, 17, 17,-1)==-1){return log_error(output_str);}
       if (add_e(&G1,i, i, 0, 1, 17, 0,-1)==-1){return log_error(output_str);}
       if (add_e(&G2,i, i, 0, 1, 17, 0,-1)==-1){return log_error(output_str);}
    } else {
      if (add_e(&G,i, i, (i+1), 2, 17, 17,-1)==-1){return log_error(output_str);}
      if (add_e(&G1,i, i, (i+1), 1, 17, 0,-1)==-1){return log_error(output_str);}
      if (add_e(&G2,i, i, (i+1), 1, 17, 0,-1)==-1){return log_error(output_str);}
    } // end if ((i+1)==no_v)   
  }
  // Add extra edges for g2.
  sprintf(output_str,"function add_e failed to add G2 3 v0,v0"); 
  if (add_e(&G2,3, 0, 0, 1, 17, 0,-1)==-1){return log_error(output_str);}  
  sprintf(output_str,"function add_e failed to add G2 4 v1,v1"); 
  if (add_e(&G2,4, 1, 1, 1, 17, 0,-1)==-1){return log_error(output_str);}  
  sprintf(output_str,"function add_e failed to add G2 4 v2,v2"); 
  if (add_e(&G2,5, 2, 2, 1, 17, 0,-1)==-1){return log_error(output_str);}  

  
  sprintf(output_str,"function edge_exists failed 0,1");   
  if (edge_exists(&G,0,1, no_e,2)==-1){return log_error(output_str);}
  sprintf(output_str,"function edge_exists failed 1,0");   
  if (edge_exists(&G,1,0, no_e,2)==-1){return log_error(output_str);}
  sprintf(output_str,"function edge_exists failed 1,2");   
  if (edge_exists(&G,1,2, no_e,2)==-1){return log_error(output_str);}
  sprintf(output_str,"function edge_exists failed 2,0");   
  if (edge_exists(&G,2,0, no_e,2)==-1){return log_error(output_str);}
  sprintf(output_str,"function edge_exists failed no edge exists between v5 and v0 v5 does not exist.");   
  if (edge_exists(&G,5,0, no_e,2)!=-1){return log_error(output_str);}
  sprintf(output_str,"function edge_exists failed no edge exists between v0 and v0.");   
  if (edge_exists(&G,0,0, no_e,2)!=-1){return log_error(output_str);}

  sprintf(output_str,"function edge_exists failed 0,1");   
  if (edge_exists(&G1,0,1, no_e,1)==-1){return log_error(output_str);}
  sprintf(output_str,"function edge_exists failed 1,2");   
  if (edge_exists(&G1,1,2, no_e,1)==-1){return log_error(output_str);}
  sprintf(output_str,"function edge_exists failed 2,0");   
  if (edge_exists(&G1,2,0, no_e,1)==-1){return log_error(output_str);}
  sprintf(output_str,"function edge_exists failed no edge exists between v5 and v0 v5 does not exist.");   
  if (edge_exists(&G1,5,0, no_e,1)!=-1){return log_error(output_str);}
  sprintf(output_str,"function edge_exists failed no edge exists between v0 and v0.");   
  if (edge_exists(&G1,0,0, no_e,1)!=-1){return log_error(output_str);}

  sprintf(output_str,"function edge_exists failed edge exists between v0 and v0.");   
  if (edge_exists(&G2,0,0,6,1)==-1){return log_error(output_str);}
  sprintf(output_str,"function edge_exists failed edge exists between v1 and v1.");   
  if (edge_exists(&G2,1,1,6,1)==-1){return log_error(output_str);}
  sprintf(output_str,"function edge_exists failed edge exists between v2 and v2.");   
  if (edge_exists(&G2,2,2,6,1)==-1){return log_error(output_str);}

  
  return 0;
}
