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
  
  if (parse(argv, argc,&no_e,&no_v,IfileName,OfileName)==-1) {return log_error("function parse failed");}
  if (read_adjency(&G,' ',IfileName)==-1){return log_error("function failed read_adjacency");}
//  disp_graph(&G,G.no_e,G.no_v);
  write_incidence(&G,' ',OfileName);
  return 0;
}
