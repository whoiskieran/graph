

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
  bool use_adj;  // Not recommended as adjency matrixes use a lot of memory and most graphs are sparse so a lot of 0 in this matrix.
//  graph_data *gd;
} graph;

/** 
* Explicit declaration of functions
**/
int log_error(char * msg);
int write_adjency(graph *G, char delim,char * OfileName);
int init_G(graph *G, int no_e, int no_v);

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
  
  if (argc<2){return -1;}
  
  while ( (ch = getopt(argc, argv, "E:V:I:O:?:"))!=-1 ) {
    switch(ch) {
	  case 'E': *no_e=atoi(optarg); break;
	  case 'V': *no_v=atoi(optarg); break;
	  case 'I': strncpy(IfileName, optarg, 254); break;
	  case 'O': strncpy(OfileName, optarg, 254); break;
	  default: return -1; 
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
    
    if (e_start > (G->no_e-1)){
      G->no_e++;
      G->e = (long **) realloc(G->e, G->no_e *sizeof(long));
      
      for (long i=0; i < G->no_e; i++){
        G->e[i]=(long*) realloc(G->e[i], E_ATTRIB_SIZE * sizeof(long));
      } // end for long i
    } // end if (e_start > (G->no_e-1)
    
    if (start_v >= G->no_v){return -1;}
    if (end_v >= G->no_v){return -1;}
    
    G->e[e_start][0]=start_v;
    G->e[e_start][1]=end_v;
    G->e[e_start][2]=direction;
    G->e[e_start][3]=fwd_weigh;
    
    if (G->use_adj==true){G->v_adj[start_v][end_v]=1;}
    
    G->v_degree[start_v] ++;
    G->v_incidents[start_v][e_start]++;
    G->v_incidents[end_v][e_start]++;
    // if this is self referencing then it is valid to say 
    // it has two edges added not just one.
    // I will have to research this.
    G->v_degree[end_v] ++;
    
    if (direction==2){
      G->e[e_start][4]=bk_weight;
      if (G->use_adj==true){G->v_adj[end_v][start_v]=1;}
    }
    set_connected(G,start_v,end_v);

    return 0;
}


long get_no_e(graph *G){return G->no_e;}
long get_no_v(graph *G){return G->no_v;}


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

long find_unique_hameltonain_path(graph *G){return 0;}

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
 * This function returns the distance between two vertices but does not test if the path is possible.
 * if the possability of the path is important use the 
 * v_valid_distance function.
**/
 
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
    if (G->use_adj==true){if (G->v_adj[start_v][end_v]==1){return 0;}}
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

/**
* Graph Theory: 30. The 5 Known Vertex-Transitive Non-Hamiltonian Graphs
* https://www.youtube.com/watch?v=FgHuQw7kb-o&t=0s&list=PLQ3WsqGOBztQQxp7Nw1svSn0Y9Hi6isda&index=51
**/

int make_VTNH(){return 0;}
/**
* Find a bridge is a good way to break up a graph into sub graphs.
* Graph Theory: 34. Bridge edges
* https://www.youtube.com/watch?v=zxu0dL436gI&t=0s&list=PLQ3WsqGOBztQQxp7Nw1svSn0Y9Hi6isda&index=54
* 
* Graph Theory: 35. Bridges in Connected Graphs
* https://www.youtube.com/watch?v=SFFEc8DbO0Y&list=PLQ3WsqGOBztQQxp7Nw1svSn0Y9Hi6isda&index=54
*
* Graph Theory: 47. Subgraphs of Regular Graphs
* https://www.youtube.com/watch?v=KFtPHoaqUaQ
*
**/

int find_bridge() {return 0;}

/**
* Graph Theory: 48. Complement of a Graph
* https://www.youtube.com/watch?v=VTgxv334KSU
*
**/

int g_complement() {return 0;}

int v_valid_distance(graph *G, int start_v, int end_v, int direction){return 0;}

/**
* Graph Theory: 51. Eccentricity, Radius & Diameter
* get_diamater and get radious
* https://www.youtube.com/watch?v=YbCn8d4Enos&list=PLoJC20gNfC2gmT_5WgwYwGMvgCjYVsIQg&index=55
**/
int get_diamater(graph *G){return 0;}
int get_radious(graph *G){return 0;}

/**
* Check if there is an edge between two vertices.
* The function takes the start and end vertixes.
* the number of edges to search if it is too large 
* it is set to the mamimum edges of the graph. 
* the directions in a bio-directional graph the start and end 
* verticies and the end and start are also tested. 
**/

int edge_exists(graph *G, long start_v, long end_v, long no_edges_to_search, int direction){

  if (G->no_e < no_edges_to_search){no_edges_to_search=G->no_e;}
  
  for (long i =0; i < no_edges_to_search; i++){
    if ((direction < 1) || (direction > 2)){direction=G->e[i][2];}
    if (direction==2){
      if ((G->e[i][0]==start_v && G->e[i][1]==end_v) || (G->e[i][0]==end_v && G->e[i][1]==start_v)) {return i;}
    } else {
      if (G->e[i][0]==start_v && G->e[i][1]==end_v) {return i;}
    } // end if direction ==2
  } // end for i
  return -1;
}

int read_adjency(graph *G, char delim,char * IfileName){
  FILE* fd;
  char line[2048];
  char output_msg[1024];    
  int no_l =0; int i; int j; long no_e=0; long no_v =0; long l_size =0; int adj_i=0;
  G->use_adj = true;
  sprintf(output_msg,"function read_adjency failed to open file %s",IfileName);  
  if ((fd=fopen(IfileName,"r"))==NULL){return log_error(output_msg);}

  while (fgets(line,sizeof(line),fd)){    
    /**
    * The first line is the list of vertices.
    * This number of verticies is calcualted 
    * the delimiter is ignored.
    **/
    
    if (no_l == 0){
      l_size = sizeof(line);
      for (i=0;i < l_size; i++){
        if(line[i]=='\n') {l_size=i;} 
        else {if(line[i] != delim){no_v++;}}
      } // enf for
      // l_size is reduced by 1 exclude line return
      // may need to revise for windows.
      l_size--;
    } else {
      /**
      * Initilize parts of the graph which depend on the no_v.
      * After line 0 we have the number of vertices.
      **/      
      if (no_l==1) {init_G(G,no_e,no_v);}
      
      /**
      * Line number is grater than 0 and adjacency matrix is being read.
      **/
      
      for (i=0; i <= l_size; i++){   
        if(line[i] != delim){
          // The first column is the vertix id
          // the if statement deals with this
          // the no_l is 1 grater than the no_v
          // because of the header line.
          // The else part puts the 1's into the matrix 
          // calloc has already set them to 0
          // ignoring the delimiter.   
          if (i==0){G->v[(no_l-1)] = atol(&line[i]);}
          else {
            G->v_adj[(no_l-1)][adj_i] = atol(&line[i]);
            adj_i++;
          } 
        } // end if not delim
      } // end for
    } // end if (no_l)
    no_l +=1;
    adj_i =0;
  } // end while
  
  /**
  * Close file as it is not needed. If there is a crash later this will be clean.
  **/
  fclose(fd);

  /**
  * The number of edges will need to be re-calculated 
  * in the case of bio-directional graphs 
  **/
    
  for(i=0;i<no_v; i++){
    for (j=0; j<no_v; j++){

    /**
    * if i and j are the same then a 1 at this position is
    * a self reference node and this is an edge.
    * Example if G->v_adj[0][0] and G->v_adj[0][0] this is an edge
    * its direction is irrelivent as starts in the same place as it ends.
    *
    * A bio-directional edge is a single edge.
    * it should only be counted once.
    **/
      
      if (G->v_adj[i][j]==1){
        if (i == j) {
        
        /**
        * if i = j then this is a self referencing node.
        * check if an edge already exists for this 
        * if there is no edge create a new one.
        * The direction of an edge on a self referencing noe is 2
        * I will have to look this up but it seems obvious but as 
        * I think self referencing nodes are pointless I am probably 
        * wrong.
        **/
          if (edge_exists(G,i,j,no_e+1,2)==-1){
            add_e(G,no_e,i,j,2,0,0);
            no_e++;
          }          
        } else {
          if ((G->v_adj[i][j]==1) && (G->v_adj[j][i]==1)){
          /**
          * If there is a one at positin i,j and j,i then 
          * this is explicitally bi-directional.
          *
          * Example 0,1 and 1,0 are both 1 then a bi-directional 
          * edge exists.
          * check if the edge exists and creat it if it does not.
          **/
            if (edge_exists(G,i,j,no_e+1,2)==-1){
              add_e(G,no_e,i,j,2,0,0);
              no_e++;
            }
          } else {
          /**
          * This is explicitally a uni-directinal edge.
          * 
          **/
            if (edge_exists(G,i,j,no_e+1,1)==-1){
              add_e(G,no_e,i,j,1,0,0);
              no_e++;
            }
          } // end if ((G->v_adj[i][j]==1) && (G->v_adj[j][i]==1)){
        } // end if i==j
      } // if (G->v_adj[i][j]==1)
    } // end for j
  } // end for i
  
  return 0;
}

int read_incidence(){return 0;}

int write_adjency(graph *G, char delim,char * OfileName){
  int i=0; int j=0;
  FILE* fd;

  char output_msg[1024];
  sprintf(output_msg,"function write_adjency Failed to Open File Name %s",OfileName);

  if (strcmp(OfileName,"")==0){fd=stdout;} 
  else { 
    fclose(stdout);
    if ((fd=fopen(OfileName,"w"))==NULL){return log_error(output_msg);}
  }
   
  fprintf(fd,"%c",delim);
  
  for (i=0;i< G->no_v;i++){
      if (G->v[i] !=-1){
        fprintf(fd,"%c%ld",delim,G->v[i]);
      } else {i=G->no_v;} // End the loop because no more verticies exist.
  }
  
  for (i=0;i< G->no_v;i++){
      if (G->v[i] !=-1){
        fprintf(fd,"\n%ld",G->v[i]);
        for (j=0;j< G->no_v;j++){
            if (G->v[j] !=-1){
                fprintf(fd,"%c%ld",delim,G->v_adj[i][j]);
            } else {j=G->no_v;}
        }
      } else {i=G->no_v;} // End the loop because no more verticies exist.
  }
  
  fclose(fd);
  
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

int log_error(char * msg){ fprintf(stderr,"\n%s\n",msg); return -1;}

bool is_icomorph(graph G1, graph G2){return 0;}
/**
The set the adjacency loie OO programming don't use variable name 
as I may change it.
**/
bool set_adj(graph *G, bool use_adj){ G->use_adj=use_adj; return use_adj;}

int init_G(graph *G, int no_e, int no_v){
  int i=0; int j=0;
  G->g_type = 1;
  G->is_bypartheid=true;
  G->no_e = no_e;
  G->no_v = no_v;
  G->use_adj = false;
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

