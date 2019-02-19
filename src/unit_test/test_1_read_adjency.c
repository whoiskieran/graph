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
  // fprintf(stdout,"\nargv[0]=%s\n",argv[0]);  
  if (read_adjency(&G,' ',IfileName)==-1){return log_error("function failed read_adjacency");}
  if (get_no_e(&G) !=no_e){return log_error("read_adjency returned wrong number of edges.");}
  if (get_no_v(&G) !=no_v){return log_error("read_adjency returned wrong number of verticies.");}
  write_adjency(&G,' ',OfileName); fprintf(stdout,"\n");
  
 // write_adjency(&G,' ',OfileName);    
  // write_incidence(&G,' ',OfileName);
  return 0;
}
