#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "graph.h"

/**
* Test set and get_v_id with invalid vertix number to ensure it returns the correct id
**/

int main(int argc, char *argv[]) {
  graph G;
  int no_e =0; int no_v=0;
  char IfileName[1024];
  char OfileName[1024];
  int degree =0;
  int sum_degree =0;
  char msg[100];
    
  if (parse(argv, argc,&no_e,&no_v,IfileName,OfileName)==-1) {return log_error("function parse failed");}  
  if (read_adjency(&G,' ',IfileName)==-1){return log_error("function failed read_adjacency");}
  sprintf(msg,"read_adjency returned wrong number of edges. Edges is %ld it should be %d",get_no_e(&G),no_e);
  if (get_no_e(&G) !=no_e){return log_error(msg);}
  sprintf(msg,"read_adjency returned wrong number of verticies. Verticies is %ld it should be %d",get_no_v(&G),no_v);
  if (get_no_v(&G) !=no_v){return log_error(msg);}

  for (int i=0; i< no_v;i++){
    degree=get_degree(&G,i);
    sum_degree += degree;
    // if (degree !=2){return log_error("Degree incorrect");}
  }
  /**
  * The sum of the degrees is alwasy twice the number of edges
  * each edge has a start and end point 
  * the sum of degrees will therefore count each edge twice
  * Isn't math usefull!
  * I didn't discover this!
  **/
  if ((sum_degree/2) !=G.no_e){return log_error("sum of degrees is not twice no_e.");}

  for (int i=0; i< no_e; i++){
    sprintf(msg,"set_v_id returned error for edge %d ",i);
    if (set_v_id(&G,-1,i) !=-1){return log_error(msg);} 
    sprintf(msg,"get_v_id returned error for edge %d ",i);
    if(get_e_id(&G,-1) !=-1){return log_error(msg);}
  }

  return 0;
}
