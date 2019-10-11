#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "graph.h"

int get_args(char* argv[], int argc,int *size, char * IfileName, char * OfileName);

int main(int argc, char *argv[]) {
//  graph G;
  int i=0; int j=0; int size=0; int c1=1; int c2=1;
  long counter = 0;
  char IfileName[1024];  
  char OfileName[1024];
  long **ptr_arr_v;
  
  ptr_arr_v = (long **) calloc(1, sizeof(long));
  ptr_arr_v[0] = (long *) calloc(4, sizeof(long));
  // ptr_arr_v = (long **) realloc(ptr_arr_v, counter *sizeof(long));  
  if (get_args(argv, argc,&size,IfileName,OfileName)==-1) {return log_error("function parse failed");}   

  for(i=0; i<=size; i++){
    for (j=0; j<=size;j++){
      if (i != j){ // Prevent self references.      
        for ((c1=(j+1)); c1 <= size; c1++){
          if (c1 != i){ // Prevent self references.
            for (c2=(c1+1); c2 <= size; c2++){
              if ((c2 != c1) && (c2 != i) && (c2 != j)) {
                fprintf(stdout,"V%d %d,%d,%d\n",i,j,c1,c2);
                counter++;
                ptr_arr_v = (long **) realloc(ptr_arr_v, counter  *sizeof(long));
                ptr_arr_v[counter] = (long *) malloc(4 * sizeof(long));;
                ptr_arr_v[(counter)][0] = i;
                ptr_arr_v[(counter)][1] = j;
                ptr_arr_v[(counter)][2] = c1;
                ptr_arr_v[(counter)][3] = c2;
                fprintf(stderr,"\nCounter=%ld",counter);
                if (size /2 == counter){
                 /**
                   * Start getting degree after this point
                   * At the half way point there vertices start to have a degree of 3.
                   * No point adding a vertix which has already been aded.
                   * Also save the expense of getting the degree before we need it.
                 **/
                 
                }
              }
            } // end for c2
          } // end if c1 != i
        } // end for c1 
      } // end if i != j
    } // end for j
  } // end for i
    
  return 0;
}

int get_args(char* argv[], int argc,int *size, char * IfileName, char * OfileName){  
  char ch;  
  extern char* optarg;  
  if (argc<2){return -1;}  
  while ( (ch = getopt(argc, argv, "S:I:O:?:"))!=-1 ) {    
    switch(ch) {
      case 'S': *size=atoi(optarg); break;     
      case 'I': strncpy(IfileName, optarg, 254); break;      
      case 'O': strncpy(OfileName, optarg, 254); break;      
      default: return -1;    
    } // End switch  
  } // End While  
  return 0;
}