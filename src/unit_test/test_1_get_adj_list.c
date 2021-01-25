#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "graph.h"


int main(int argc, char *argv[]) {
  graph G;
  int no_e =10; int no_v=10;
  long * adj_list;
  char output_msg[1024];     
  if (init_G(&G,no_e,no_v) !=0){return log_error("function init_G failed to create a graph");}
  
  for (int i=0;i < no_v;i++){
   // The id of the vertix is irrelivent for this test.
    if (add_v(&G,i,i)==-1){return log_error("function add_v failed to add a vertix");}
  }
  
  for (int i=0;i < no_v;i++){
    adj_list = get_adj_lst(&G,i);
    if (adj_list[0] !=0){
      sprintf(output_msg,"failed to get 0 adjacent vertices for %d",i);
      return log_error(output_msg);
    }
  }
  return 0;
}
