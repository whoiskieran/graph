#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "graph.h"


int main(int argc, char *argv[]) {
  graph G;
  int no_e =6; int no_v=6;
  
  if (init_G(&G,no_e,no_v) !=0){return log_error("function init_G failed to create graph.");}
  if (G.no_e != no_e){return log_error("no_e != G.no_e");}
  if (G.no_v != no_v){return log_error("no_v != G.no_v");}
  
  return 0;
}
