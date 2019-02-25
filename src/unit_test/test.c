#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
// #include "graph.h"


int main(int argc, char *argv[]) {
  int i=0; int j=0; int s=3;
  long **e;
  e = (long **) calloc(s, sizeof(long));
  for (i=0; i < s; i++){
    e[i]=(long*) calloc(s, sizeof(long));
    for (j=0; j < s; j++){e[i][j]=-1;}
  }
  
  for (i=0; i < s; i++){
    for (j=0; j < s; j++){
      fprintf(stdout,"\ne[%d][%d]=%ld",i,j,e[i][j]);
    }
  }
  s=4;
  e = (long **) realloc(e,s*sizeof(long));
  
  for (i =0; i<s; i++){
    e[i] = (long *) realloc(e[i],s*sizeof(long));
  }
  fprintf(stdout,"\n#####");  
  for (i=0; i < s; i++){
    for (j=0; j < s; j++){
      fprintf(stdout,"\ne[%d][%d]=%ld",i,j,e[i][j]);
    }
  }
  fprintf(stdout,"\n");
  return 0;
}
