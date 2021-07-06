#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "graph.h"

/**
* Rotate the verticies id use the verticies to find cycles 
*
**/

long rotate_v(graph *G,long steps, FILE *fd,long no_v);


int main(int argc, char *argv[]) {
  graph G;
  int no_e =0; int no_v=0;
  char IfileName[1024];
  char OfileName[1024];
  int degree =0;
  int sum_degree =0;
  char msg[100];
  FILE *fd;
      
  if (parse(argv, argc,&no_e,&no_v,IfileName,OfileName)==-1) {return log_error("function parse failed");}  
  if (read_adjency(&G,' ',IfileName)==-1){return log_error("function failed read_adjacency");}
  sprintf(msg,"read_adjency returned wrong number of edges. Edges is %ld it should be %d",get_no_e(&G),no_e);
  if (get_no_e(&G) !=no_e){return log_error(msg);}
  sprintf(msg,"read_adjency returned wrong number of verticies. Verticies is %ld it should be %d",get_no_v(&G),no_v);
  if (get_no_v(&G) !=no_v){return log_error(msg);}

  for (int i=0; i< no_v;i++){
    degree=get_degree(&G,i);
    sum_degree += degree;
    // if (degree !=2){return log_error("Degree incorrect");}
  }
  /**
  * The sum of the degrees is alwasy twice the number of edges
  * each edge has a start and end point 
  * the sum of degrees will therefore count each edge twice
  * Isn't math usefull!
  * I didn't discover this!
  **/
  if ((sum_degree/2) !=get_no_e(&G)){return log_error("sum of degrees is not twice no_e.");}

  for (long i=0; i< no_v; i++){
    sprintf(msg,"set_v_id returned error for vertix %ld ",i);
    if (set_v_id(&G,i,i) ==-1){return log_error(msg);} 
    sprintf(msg,"get_v_id returned error for vertix %ld ",i);
    if(get_v_id(&G,i)==-1){return log_error(msg);}
  }


  sprintf(msg,"function Failed to Open File Name %s",OfileName);
  if (strcmp(OfileName,"")==0){ fd=stdout;}
  else {
     fclose(stdout);
     if ((fd=fopen(OfileName,"w"))==NULL){return log_error(msg);}
  }
  
  long result =-1;
  result = rotate_v(&G,no_v, fd, no_v);

  fclose(fd);

  return result;
}

long rotate_v(graph *G,long steps, FILE *fd,long no_v){

  /**
  * No need to use the get_v_pos_by_id here as the id and the positions
  * in sync.
  **/
  
  long * adj_list;
  long id =0;
  long v_pos =0;
  long h =0;
  char msg[100];

 
  fprintf(fd,"Step %ld of %ld - This is the non-rotated graph \n",h,steps);
  for (long i=0; i < no_v; i++){
    adj_list = get_adj_lst(G,i);
    fprintf(fd,"%ld",i);
    for (long j=1;j <= adj_list[0]; j++) {fprintf(fd,",%ld",adj_list[j]);} 
    fprintf(fd,"\n");
  } // end for i
  
  // h=1 because step 0 has alrady been done and printed to the file.
  for (h=1; h < steps; h++){
    fprintf(fd,"Step %ld\n",h);
    // rotate all the id's
    for (long i=0; i < no_v; i++){
      id = get_v_id(G,i);
      id = ((id==(no_v-1)) ? 0 : id+1);
      sprintf(msg,"set_v_id returned error for vertix %ld when setting id to %ld",i,id);
      if (set_v_id(G,i,id) ==-1){return log_error(msg);}
    }
    
    for (long i=0; i< no_v; i++){
      id = get_v_id(G,i);
      v_pos = get_v_pos_by_id(G,id,0,no_v);
      adj_list = get_adj_lst(G,v_pos);
      fprintf(fd,"%ld",id);
      
      /**
      * use the vertix numbers in the adjacncy list get the id's
      * pritn these id's as the verti will be adjacent to the vertix with
      * the incremented id's
      * if for exmple v0(id=0) and v1(id=1) are adjacent and 
      * their id's are incremented. v0(id=1) and v1(id=2) 
      * are still adjacent as no edges have been moved.
      * they have the same degree but the id's have changed.
      * this is rotating the id's as the id's will cycle
      * once the h loop is done all id's will be rotated 
      * in a triangle graph v0(id=0) will be v0(id=2)
      * one more rotation would set it to v0(id=0) again.
      **/
      
      for (long j=1;j <= adj_list[0]; j++) {
        id = get_v_id(G,adj_list[j]);
        // v_pos =  get_v_pos_by_id(G,id,0,no_v);
        fprintf(fd,",%ld",id);
      } // end for j
      fprintf(fd,"\n"); 
    } // end for i
  } // end for h
  
  return 0;
}

