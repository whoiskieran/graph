#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "graph.h"

/**
* Test get_v_id to ensure it returns the correct id
**/

int main(int argc, char *argv[]) {
  graph G;
  int no_e =0; int no_v=0;
  char IfileName[1024];
  char OfileName[1024];
  int degree =0;
  int sum_degree =0;
  char msg[100];
    
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
  if ((sum_degree/2) !=G.no_e){return log_error("sum of degrees is not twice no_e.");}

  for (long i=0; i< no_v; i++){
    sprintf(msg,"set_v_id returned error for vertix %ld ",i);
    if (set_v_id(&G,i,i) ==-1){return log_error(msg);} 
    sprintf(msg,"get_v_id returned error for vertix %ld ",i);
    if(get_v_id(&G,i)==-1){return log_error(msg);}
  }
  
  long strt_pos =0;
  long end_pos = 0;
  long id=0;

  /**
  * Test 1 set strt pos -1
  * Should return -2 invalid strt_pos 
  **/
  
  strt_pos =-8; 
  end_pos = get_no_v(&G);
  id=0;

  sprintf(msg,"TEST_1 get_v_pos_by_id should have returned -2 ");
  if(get_v_pos_by_id(&G,id,strt_pos,end_pos) !=-2){return log_error(msg);}
   
  /**
  * Test 2 set end_pos -1
  * Should return -3 invalid end_pos 
  **/
  
  strt_pos =0; 
  end_pos = -8; 
  id=0;

  sprintf(msg,"TEST_2 get_v_pos_by_id should have returned -3 ");
  if(get_v_pos_by_id(&G,id,strt_pos,end_pos) !=-3){return log_error(msg);}
    
  /**
  * Test 3 set strt_pos grater than end_pos
  * Should return -2 invalid strt_pos 
  **/
  
  strt_pos = 2; 
  end_pos = 1; 
  id=0;

  sprintf(msg,"TEST_3 get_v_pos_by_id should have returned -2 ");
  if(get_v_pos_by_id(&G,id,strt_pos,end_pos) !=-2){return log_error(msg);}

  /**
  * Test 4 set strt_pos grater than no_v
  * Should return -2 invalid strt_pos 
  **/
  
  strt_pos = get_no_v(&G) + 2; 
  end_pos = get_no_v(&G); 
  id=0;

  sprintf(msg,"TEST_4 get_v_pos_by_id should have returned -2 ");
  if(get_v_pos_by_id(&G,id,strt_pos,end_pos) !=-2){return log_error(msg);}

  /**
  * Test 5 set end_pos grater than no_v
  * Should return -3 invalid end_pos 
  **/
  
  strt_pos = 0; 
  end_pos = get_no_v(&G)+2; 
  id=0;

  sprintf(msg,"TEST_5 get_v_pos_by_id should have returned -2 ");
  if(get_v_pos_by_id(&G,id,strt_pos,end_pos) !=-3){return log_error(msg);}


/**
  * Test 6 set id to non-existant number in the graph
  * Should return -1 not found
**/  
  
  strt_pos = 0;
  end_pos = get_no_v(&G); 
  id=get_no_v(&G)+200;

  sprintf(msg,"TEST_6 get_v_pos_by_id should have returned -1 ");
  if(get_v_pos_by_id(&G,id,strt_pos,end_pos) !=-1){return log_error(msg);}

/**
  * Test 7 set id to valid id number in the graph
  * Should return id also should execute fast test to do this
**/  
  
  strt_pos = 0;
  end_pos = get_no_v(&G); 
  id=1; // every test graph has moer than 2 nodes so 0 and 1 will be valid id's

  sprintf(msg,"TEST_7 get_v_pos_by_id should have returned %ld ",id);
  if(get_v_pos_by_id(&G,id,strt_pos,end_pos) !=id){return log_error(msg);}

/**
  * Test 8 set id to valid id number in the graph
  * this is a non seuqncial graph with non-unique id's
  * the first number node in the array will be returned.
**/  
  
  strt_pos = 0;
  end_pos = get_no_v(&G); 
  id=200; 

  for (long i=0; i< no_v; i++){
    sprintf(msg,"set_v_id returned error for vertix %ld ",i);
    if (set_v_id(&G,i,200) ==-1){return log_error(msg);} 
    sprintf(msg,"get_v_id returned error for vertix %ld ",i);
    if(get_v_id(&G,i)==-1){return log_error(msg);}
  }  

  sprintf(msg,"TEST_8 get_v_pos_by_id should have returned 0 ");
  if(get_v_pos_by_id(&G,id,strt_pos,end_pos) ==-1){return log_error(msg);}

  return 0;
}
