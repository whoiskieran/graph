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
  int degree =0;
  int sum_degree =0;
  char msg[1024];
  long *bridge_list;
  FILE* fd;
  
  if (parse(argv, argc,&no_e,&no_v,IfileName,OfileName)==-1) {return log_error("function parse failed");}  
  if (read_adjency(&G,' ',IfileName)==-1){return log_error("function failed read_adjacency");}
  sprintf(msg,"find_first_bridge returned wrong number of edges. Edges is %ld it should be %d",get_no_e(&G),no_e);
  if (get_no_e(&G) !=no_e){return log_error(msg);}
  sprintf(msg,"find_first_bridge returned wrong number of verticies. Verticies is %ld it should be %d",get_no_v(&G),no_v);
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
  
  long b_size;
  bridge_list = find_first_bridge_e(&G,0,G.no_v);
  b_size = bridge_list[0];
  
  sprintf(msg,"function find_first_bridge Failed to Open File Name %s",OfileName);
  if (strcmp(OfileName,"")==0){ fd=stdout;}
  else {
     fclose(stdout);
     if ((fd=fopen(OfileName,"w"))==NULL){return log_error(msg);}
  }
     
  for (long i =1; i <= b_size; i++){
    fprintf(fd,"%ld,",bridge_list[i]);
  }
  
  return 0;
}
