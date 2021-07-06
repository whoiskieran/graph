#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "graph.h"

int main(int argc, char *argv[]) {
  int no_e =0; int no_v=0;
  char IfileName[1024];
  char OfileName[1024];
  
  if(parse(argv, argc,&no_e,&no_v,IfileName,OfileName)==-1){return log_error("parse function returned -1");}
  if(argc < 2){return log_error("function parse no arguments wrong");}
  if(no_e ==0){return log_error("function parse no edges is  wrong");}
  if(no_v ==0){return log_error("function parse no verticies is wrong");}
  if(strcmp(IfileName,"input.txt") !=0){return log_error("function parse input file is wrong");}      
  if(strcmp(OfileName,"output.txt") !=0){return log_error("function parse output file is wrong");}      
  
  return 0;
}
