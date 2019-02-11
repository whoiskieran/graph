#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "graph.h"


int main(int argc, char *argv[]) {
  graph G;
  int no_e =0; int no_v=0; int i,j;
  char * IfileName[1024];
  char * OfileName[1024];
  
  if (parse(argv, argc,&no_e,&no_v,IfileName,OfileName)==-1) {return 0;}
  
  if (init_G(&G,no_e,no_v)==-1){}
  
  if (add_v(&G,0,0)==-1){}
  if (add_v(&G,1,1)==-1){}
  if (add_v(&G,2,2)==-1){}
  if (add_v(&G,3,3)==-1){}
  if (add_v(&G,4,4)==-1){}
  if (add_v(&G,5,5)==-1){}
  
  // Add connections
  if (add_e(&G,0, 0, 1, 1, 0, 0)==-1){}
  if (add_e(&G,1, 1, 2, 1, 0, 0)==-1){}
  if (add_e(&G,2, 2, 3, 1, 0, 0)==-1){}
  if (add_e(&G,3, 3, 4, 1, 0, 0)==-1){}
  // if (add_e(&G,2, 2, 0, 2, 0, 0)==-1){}
  // self referencing node.
  // if (add_e(&G,3, 0, 0, 1, 0, 0)==-1){}
  // if (add_e(&G,4, 1, 1, 1, 0, 0)==-1){}
  // if (add_e(&G,5, 2, 2, 1, 0, 0)==-1){}
  write_adjency(&G,' ',OfileName);
  // if (move_e(&G, 3, 1, 1, 1, 0, 0)==-1){}
  fprintf(stdout,"\nDegree of 2 is %d\n",get_degree(&G,2));
  fprintf(stdout,"\nDegree of 5 is %d\n",get_degree(&G,5));
  fprintf(stdout,"\nDegree of 4 is %d\n",get_degree(&G,4));
  fprintf(stdout,"\nDistance 0,5=%d\n",v_distance(&G,0,5));
  fprintf(stdout,"\nDistance 1,4=%d\n",v_distance(&G,1,4));
  fprintf(stdout,"\nDistance 2,4=%d\n",v_distance(&G,2,4));
  fprintf(stdout,"\nDistance 3,4=%d\n",v_distance(&G,3,4));
  fprintf(stdout,"\nDistance 4,4=%d\n",v_distance(&G,4,4));
  fprintf(stdout,"\nIsConnected = %d\n",G.is_connected);
  fprintf(stdout, "\nGraph Created!\n");
  write_incidence(&G,' ',OfileName);
  return 0;
}
