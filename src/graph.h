

int E_ATTRIB_SIZE = 5; // This is a constant;

typedef struct graph {
  long *v; 
/**
* vertix this number will be used as an external ID.
* this also can be used to store a sub graph.
* if a 10,000 vertix graph is created the v[] will go from 0 to 9999.
* if the graph is broken up into 2 equally sized sub graphs second v[] will start at 4,998
* a dupoicate node will be needed in most cases and most likely more than one duplicate. 
**/
  long **v_adj; // Matrix Rows & Cols are Verticies
  long **v_incidents; //Matrix Rows are Verticies and Cols are Edges
  long **e; 
  long no_e;
  long no_v;
/**
* edges have a start and end point Example edge from node 1 to 2 is {1,2}
* e[dynamic][0] = start cordinate = vertix id
* e[dynamic][1] = end cordinate = vertix id
* e[dynamic][2] = direction 1 one direction 2 both directions
* e[dynamic][3] = foreword edge weight 0 no weight 1..n whatever you want.
* e[dynamic][4] = backowrd edge weight (only applicable to bio directional graphs) -0 no weight 1..n whatever you want.
* when creating sub graphs edges have to be removed.
* will have to look hard at creating subgraphs.
**/

  long *v_degree; // Number of edges a vertex has if odd then affects Uleir path.
  long *cycles;  // list of node id's which are involved in a cycle.
  bool connected; // boolean
  int g_type;
 // Each type has a number
  bool is_bypartheid;
  bool is_connected;
  bool is_simple; // No loops or multiple edges
//  graph_data *gd;
} graph;
/**
 * @Author Kieran O'Sullivan
 * 
 * 
 */

int set_connected(graph *G, int start_v, int end_v){
  if (start_v ==-1){G->is_connected = false; }
  else if (G->v_adj[start_v][end_v]==1) {G->is_connected = true;}
  else { G->is_connected = false;}
  return 0;
}


/**
 * Showing how the command line must be used.
 * 
*/
 
int usage(){
    fprintf(stderr,"Use it properly!");
    return -1;
}

/**
 * Parse the command line arguments. 
*/

int parse(char* argv[], int argc,int *no_e, int *no_v, char * IfileName, char * OfileName){
  char ch;
  extern char* optarg;
  
  if (argc<2){return usage();}
  
  while ( (ch = getopt(argc, argv, "E:V:I:O:?:"))!=-1 ) {
    switch(ch) {
	  case 'E': *no_e=atoi(optarg); break;
	  case 'V': *no_v=atoi(optarg); break;
	  case 'I': strncpy(IfileName, optarg, 254); break;
	  case 'O': strncpy(OfileName, optarg, 254); break;
	  default: return usage(); 
    } // End switch
  } // End While
  return 0;
}

int add_v(graph *G, long insert_v,int v_id){
/*
realloc() will have to be used here.
https://www.tutorialspoint.com/c_standard_library/c_function_realloc.htm
*/

    // don't insert vertices in bigger than no_v
    if (insert_v >= G->no_v){return -1;}
    // do I want to make verticies id's unique
    for (int i=0; i>insert_v; i++){
        if(G->v[i]==v_id){return -1;}
    }
    G->v[insert_v]=v_id;
    G->v_degree[insert_v]=0;
    // Force graph to be non-connected
    set_connected(G, -1, -1);
    return 1;
}

int add_e(graph *G,int e_start, int start_v, int end_v,int direction,int fwd_weigh, int bk_weight){
/*
realloc() will have to be used here.
https://www.tutorialspoint.com/c_standard_library/c_function_realloc.htm
*/    
    /*
    * Add validation to prevent over-flows.
    */
    
    if (e_start >= G->no_e){return -1;}
    if (start_v >= G->no_v){return -1;}
    if (end_v >= G->no_v){return -1;}
    
    G->e[e_start][0]=start_v;
    G->e[e_start][1]=end_v;
    G->e[e_start][2]=direction;
    G->e[e_start][3]=fwd_weigh;
    G->v_adj[start_v][end_v]=1;
    G->v_degree[start_v] ++;
    G->v_incidents[start_v][e_start]++;
    G->v_incidents[end_v][e_start]++;
    // if this is self referencing then it is valid to say 
    // it has two edges added not just one.
    // I will have to research this.
    G->v_degree[end_v] ++;
    
    if (direction==2){
        G->e[e_start][4]=bk_weight;
        G->v_adj[end_v][start_v]=1;
    }
    set_connected(G,start_v,end_v);
    return 0;
}


int move_v(){return 0;}
/**
An articilation point is a node which prevents a hameltonain path from being found.
*/
long find_articilation(graph *G){return 0;}

/**
A unique path menas that even if the starting vertices are different 
The code msut be clever enought to know that the path is the same.
Watch https://www.youtube.com/watch?v=dQr4wZCiJJ4&t=0s&index=6&list=PLQ3WsqGOBztQQxp7Nw1svSn0Y9Hi6isda
*/

long find_unique_hameltonain_apth(graph *G){return 0;}

int get_degree(graph * G, int start_v){
    if (start_v >= G->no_v){return -1;}
    return G->v_degree[start_v];
}

int move_e(graph * G, int e_start, int start_v, int end_v,int direction,int fwd_weigh, int bk_weight){
    // Remove edges
    if(e_start >= G->no_e){return -1;}
    // re-set the adjacency matrix to 0 for this edge.
    G->v_adj[G->e[ e_start][0] ][ G->e[e_start][1] ]=0;
    
    // if the direction is both ways then remove the backtrack path
    if (G->e[e_start][2]==2) {
        G->v_adj[G->e[e_start][1] ][ G->e[e_start][0] ]=0;
    }
    
    for (int i=0; i < E_ATTRIB_SIZE; i++){
        G->e[e_start][i]=-1;
    }
    // return 0;
    return add_e(G,e_start,start_v,end_v,direction,fwd_weigh,bk_weight);
}
/**
 * This function returns the distance between two vertices but does not test if the path is pissible.
 * if the possability of the path is important use the 
 * v_valid_distance function.
 * */
 
int v_distance(graph *G, int start_v, int end_v){
    // if vertix sent down is bigger tne the number of verticies return -1
    if (start_v >= G->no_v){return -1;}
    if (end_v >= G->no_v){return -1;}
    int i; int j; int counter=0;
    
    /**
    * Check adjacency matrix if the
    * end_v is in the matrix for the start_v they 
    * are adjacent and there is no need to search any more.
    * Based on the Direction the matrix will be populated 
    * with the cordinates.  
    * if two vertacies are adjacent the distance between them is 0
    * There is 0 nodes to traverse.  
    **/
    if (G->v_adj[start_v][end_v]==1){return 0;}
    
    /**
     * If the end_v is not in the matrix then edges will have to be
     * followed. Depending on the directions of ecges the search will
     * work differently.
     * 
     * If the edges only allow one direction 
     * then searching the matrix is no good 
     * because this edge is only one way
     */
     
     for (i=0; i < G->no_e; i++){
         if (G->e[i][0]==start_v){
            // start from the found edge so j=i
            for (j=i; j < G->no_e; j++){
               counter++;
               if (G->e[j][1]==end_v){ return counter-1; }
            } // end for j
         } // if (G->e[i][0]==start_v){
     } // end for i
    return 0;
}

int v_valid_distance(graph *G, int start_v, int end_v, int direction){return 0;}
int read_adjency(){return 0;}
int read_incidence(){return 0;}

int write_adjency(graph *G, char delim,char * OfileName){
  int i=0; int j=0;
  fprintf(stdout,"%c",delim);
  for (i=0;i< G->no_v;i++){
      if (G->v[i] !=-1){
        fprintf(stdout,"%c%ld",delim,G->v[i]);
      } else {i=G->no_v;} // End the loop because no more verticies exist.
  }
  for (i=0;i< G->no_v;i++){
      if (G->v[i] !=-1){
        fprintf(stdout,"\n%ld",G->v[i]);
        for (j=0;j< G->no_v;j++){
            if (G->v[j] !=-1){
                fprintf(stdout,"%c%ld",delim,G->v_adj[i][j]);
            } else {j=G->no_v;}
        }
      } else {i=G->no_v;} // End the loop because no more verticies exist.
  }
  return 0;
}

int write_incidence(graph *G, char delim,char * OfileName){
  int i=0; int j=0;
  fprintf(stdout,"%c",delim);
  for (i=0;i< G->no_e;i++){
      if (G->e[i][0] !=-1){
        fprintf(stdout,"%c%d",delim,i);
      } else {i=G->no_e;} // End the loop because no more edges exist.
  }
  for (i=0;i<G->no_v;i++){
      if (G->v[i] !=-1){
        fprintf(stdout,"\n%ld",G->v[i]);
        for (j=0;j<G->no_e;j++){
            if (G->e[j][0] !=-1){
                fprintf(stdout,"%c%ld",delim,G->v_incidents[i][j]);
            } else {j=G->no_e;}
        }
      } else {i=G->no_v;} // End the loop because no more verticies exist.
  }
  return 0;
}

// this is a Decomposition
int make_sub_g(graph G, int start_v,int end_v,int no_of_v){return 0;}

int is_vertex_transitave(){return 0;}

int log_error(){return 0;}

bool is_icomorph(graph G1, graph G2){return 0;}

int init_G(graph *G, int no_e, int no_v){
  int i=0; int j=0;
  G->g_type = 1;
  G->is_bypartheid=true;
  G->no_e = no_e;
  G->no_v = no_v;
  G->e = (long **) calloc(no_e, sizeof(long));
  G->v = (long*) calloc(no_v, sizeof(long));
  G->v_degree = (long*) calloc(no_v, sizeof(long));
  G->v_adj = (long**) calloc(no_v, sizeof(long));
  G->v_incidents = (long**) calloc(no_v, sizeof(long));
  
  for (i=0; i < no_e; i++){
      G->e[i]=(long*) calloc(E_ATTRIB_SIZE, sizeof(long));
      for (j=0; j < E_ATTRIB_SIZE; j++){
          G->e[i][j]=-1;
      }
  }
  
  for (i=0; i<no_v;i++) {
      G->v[i] = -1;
      G->v_degree[i] = 0;
      G->v_adj[i] = (long*) calloc(no_v, sizeof(long));
      G->v_incidents[i] = (long*) calloc(no_e, sizeof(long));
  }
  return 0;
}

int disp_graph(graph *G, int no_e, int no_v){
  int i,j;
  
  for (i=0; i < no_e; i++){
      for (j=0; j < E_ATTRIB_SIZE; j++){
          fprintf(stdout,"\nG->e[%d][%d]=%ld",i,j,G->e[i][j]);
      }
  }
   
  for (i=0; i<no_v;i++){
      fprintf(stdout,"\nG.v[%d]=%ld",i,G->v[i]);
  }
  return 0;
}

