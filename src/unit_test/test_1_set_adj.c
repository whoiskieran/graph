#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "graph.h"

int main(int argc, char *argv[]) {
  graph G;
  int no_e =3; int no_v=3; 
  if (init_G(&G,no_e,no_v)==-1){return log_error("function init_G failed to create graph.");}
  if (set_adj(&G,true)!=true){return log_error("function set_adj failed");}

  return 0;
}
