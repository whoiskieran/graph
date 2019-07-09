#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "graph.h"

/**
* Test on find the edges 
* check if there are any edges only.
* these tests are run against the adjacency matrix files
* which all have edges so if the number of edges returned is 0
* throw an error.
**/

int main(int argc, char *argv[]) {
  graph G;
  int no_e =0; int no_v=0;
  char IfileName[1024];
  char OfileName[1024];
  int degree =0;
  int sum_degree =0;
  char msg[100];
  long *edge_list;
    
  if (parse(argv, argc,&no_e,&no_v,IfileName,OfileName)==-1) {return log_error("function parse failed");}  
  if (read_adjency(&G,' ',IfileName)==-1){return log_error("function failed read_adjacency");}
  sprintf(msg,"read_adjency returned wrong number of edges. Edges is %ld it should be %d",get_no_e(&G),no_e);
  if (get_no_e(&G) !=no_e){return log_error(msg);}
  sprintf(msg,"read_adjency returned wrong number of verticies. Verticies is %ld it should be %d",get_no_v(&G),no_v);
  if (get_no_v(&G) !=no_v){return log_error(msg);}
  for (int i=0; i< no_v;i++){
    degree=get_degree(&G,i);
    sum_degree += degree;
  }
  
  /**
  * The sum of the degrees is alwasy twice the number of edges
  * each edge has a start and end point 
  * the sum of degrees will therefore count each edge twice
  * Isn't math usefull!
  * I didn't discover this!
  **/
  
  if ((sum_degree/2) !=G.no_e){return log_error("sum of degrees is not twice no_e.");}

  /**
  * the graph
  * search for vertix 2
  * start at edges 2
  * search both directions.
  * returns number of elements in edge_list[0] and then the list of edges themsleves.
  **/
  
  long e_size;
  edge_list = find_edges(&G,2,2,2);
  e_size = edge_list[0];
  degree=get_degree(&G,2);
  if (e_size ==0){return log_error("number of edges is 0");}
  sprintf(msg,"degree=%d != size=%ld",degree,e_size);
  if (degree != e_size){return log_error(msg);} 
  return 0;
}
