#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "graph.h"


int main(int argc, char *argv[]) {
  graph G;
  int no_e =0; int no_v=0;
  char IfileName[1024];
  char OfileName[1024];
  char msg[100];
    
  if (parse(argv, argc,&no_e,&no_v,IfileName,OfileName)==-1) {return log_error("function parse failed");}  
  if (read_adjency(&G,' ',IfileName)==-1){return log_error("function failed read_adjacency");}
//  disp_graph(&G,G.no_e,G.no_v);
  sprintf(msg,"read_adjency returned wrong number of edges. Edges is %ld it should be %d",get_no_e(&G),no_e);
  if (get_no_e(&G) !=no_e){return log_error(msg);}
  sprintf(msg,"read_adjency returned wrong number of verticies. Verticies is %ld it should be %d",get_no_v(&G),no_v);
  if (get_no_v(&G) !=no_v){return log_error(msg);}
  write_adjency(&G,' ',OfileName);
  
  return 0;
}
