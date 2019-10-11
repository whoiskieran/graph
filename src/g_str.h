int E_ATTRIB_SIZE = 5; // This is a constant;
/**
* https://snap.stanford.edu/snap/download.html
* Stanford SNAP C++ graph library is also usefull 
* it will be used for testing benchmarking this project.
* It is planned that this will be a C version of the SNAP code.
**/

/**
* A property is on an edger or vertix
* Edges and Verticies can have multiple properties.
* If it is a vertix then set the v_id otherwise set the e_id
* prop_n and prop_v store the name and value of the property.
**/

/*
typedef struct property {
	long *e_id;
	long *v_id;
	char **prop_n;
	char **prop_v;
}
*/

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
  long *v_in_deg; // only the incomming degree
  long *v_out_deg; // only the outgoing degree.
  long *e_cycles;  // list of edges which are part of cycle used for finding bridge edges.
  long *v_cycles; // list of verticies involved in a cycle.
  bool connected; // boolean
  int g_type;
 // Each type has a number
  bool is_bypartheid;
  bool is_connected;
  bool is_simple; // No loops or multiple edges
  bool use_adj;  // Not recommended as adjency matrixes use a lot of memory and most graphs are sparse so a lot of 0 in this matrix.
  bool use_incident;
  long G_id; // The id of this graph
  long *G_related_id; //Related Graphs used when braking a graph up into sub graphs.
//  graph_data *gd;
} graph;


/** 
* Explicit declaration of functions
**/

int init_G(graph *G, int no_e, int no_v);
int add_v(graph *G, long insert_v,long v_id);
int add_e(graph *G,long e_start, long start_v, long end_v,int direction,int fwd_weigh, int bk_weight);
long get_no_e(graph *G);
long get_no_v(graph *G);
int move_v();
long find_articilation(graph *G);
long find_unique_hameltonain_path(graph *G);
long get_degree(graph * G, int start_v);
long get_in_degree(graph *G, long v);
long get_out_degree(graph *G, long v);
int move_e(graph * G, int e_start, int start_v, int end_v,int direction,int fwd_weigh, int bk_weight);
int v_distance(graph *G, int start_v, int end_v);
int make_VTNH();
long * find_edges(graph *G, long v_start,long e_start, long pos);
long * find_common_elem(long * arr_1, long * arr_2, long len_1, long len_2, long ofset_1, long ofset_2);
long * find_first_bridge_e(graph *G, long start_v, long end_v);
long find_cycle_e(graph *G, long v_start, long * edge_list, long fwd_bk_nut, long direction);
graph combine_g(graph * G1, graph * G2, long bridge_v1, long bridge_v2,int direction,int fwd_weigh, int bk_weight);
int g_complement();
long find_cut_v(graph *G);
int v_valid_distance(graph *G, int start_v, int end_v, int direction);
int get_eccentricity(graph *G);
int get_diamater(graph *G);
int get_radious(graph *G);
long * get_vertix(graph *G, long e);
int read_adjency(graph *G, char delim,char * IfileName);
int read_incidence(graph *G, char delim,char * IfileName);
int edge_exists(graph *G, long start_v, long end_v, long no_edges_to_search, int direction);
int write_adjency(graph *G, char delim,char * OfileName);
int write_incidence(graph *G, char delim,char * OfileName);
int make_sub_g(graph G, int start_v,int end_v,int no_of_v);
int is_vertex_transitave();
int log_error(char * msg);
bool is_icomorph(graph G1, graph G2);
bool set_adj(graph *G, bool use_adj);
int disp_graph(graph *G, int no_e, int no_v);
long get_fwd_weight(graph *G, long e_start);
long get_bk_weight(graph *G, long e_start);
long set_fwd_weight(graph *G, long e_start, long w);
long set_bk_weight(graph *G, long e_start, long w);
/**
 * @Author Kieran O'Sullivan
 * 
 * 
 */

// The graph
// the v_start - 0 to start from the beginning.
// the v_end - the end vetix if v_start and v_end the same then look for cycle.
// long_path 1 longerst 0 shortest.

long * find_path(graph *G, long v_start, long v_end, long e_start, int long_path){
  // Inatalize e_path and v_path to a maximun  
  long * e_path = (long *) calloc(G->no_e, sizeof(long)); 
  long * v_path = (long *) calloc(G->no_v, sizeof(long)); 
  long v_counter =0; long i; long e_counter;
  long *e_list;
  long * vertix_list;
  long weight[2]; // [0] is the weight [1] is the edge no
  long t_weight=-1;
  weight[0]=-1; weight[1]=-1;
  e_path[0]=-1; v_path[0]=-1;
  // Validation
  if (v_start < 0){e_path[0]=0; return e_path;}
  if (v_end < 0){e_path[0]=0; return e_path;}
  if (v_start > G->no_v){e_path[0]=0; return e_path;}
  if (v_end > G->no_v){e_path[0]=0; return e_path;}

  /**
  * If the start or end vertix have no edges this is a pointless search.
  **/

  if (get_degree(G,v_start)==0){e_path[0]=0; return e_path;}
  if (get_degree(G,v_end)==0){e_path[0]=0; return e_path;}
  /**
  Find the bridge don't cross it unless necessary.
  **/
  // find_first_bridge_e(G, v_start, v_end);
	
  /**
  * get the edge list of the start v
  * get the vertix of these edges
  * test if the vertix vertix of these matches the end_v
  * 
  **/

  v_counter =1; e_counter=1;
  v_path[v_counter]=v_start; // The first element [0] is the no of elements.
  e_path[e_counter]=e_start; // The first element [0] is the no of elements.

  do {
  /**
  * get the edge list of the start v
  * get the vertix of these edges
  * test if the vertix vertix of these matches the end_v
  * 
  **/
    e_list = find_edges(G,v_path[v_counter],e_path[e_counter], 0);
          
    /**
      * get the edge with the lowest or highest weight
      * get the next vertix
      * get the edges for this vertix.
      * add to the e_path and v_path
    **/ 
    
    for (i=1; i < e_list[0]; i++){
    /** 
      * This if ststement tests the direction of the edge
      * A non directed path is treated differently.
      * A non directed path allows two way travel.
      * it is possible that traveling one way on the path is less
      * expensive than traveling back on the same path. A walking 
      * ruit up-hill is slower than a down-hill walk on the same path.
    **/
      if (G->e[ e_list[i] ][2] < 2){
        t_weight=get_fwd_weight(G, e_list[i]);
        if (long_path ==1) {
          if (t_weight > weight[0]){weight[0]=t_weight; weight[1]=e_list[i];}
        } else {
          if (t_weight < weight[0]){weight[0]=t_weight; weight[1]=e_list[i];}
        }        
      } else {
        t_weight=get_fwd_weight(G, e_list[i]);
        if (long_path ==1) {
          if (t_weight > weight[0]){weight[0]=t_weight; weight[1]=e_list[i];}
        } else {
          if (t_weight < weight[0]){weight[0]=t_weight; weight[1]=e_list[i];}
        }
        t_weight=get_bk_weight(G, e_list[i]);
        if (long_path ==1) {
          if (t_weight > weight[0]){weight[0]=t_weight; weight[1]=e_list[i];}
        } else {
          if (t_weight < weight[0]){weight[0]=t_weight; weight[1]=e_list[i];}
        }
      } // if (G->e[ e_list[i] ][2] < 2){
    } // end for i
    
    vertix_list = get_vertix(G, weight[1]);
    if (vertix_list[0]==v_start){v_start=vertix_list[1];}
    else {v_start=vertix_list[0];}

    e_path[e_counter]=weight[1];
    v_path[v_counter]=v_start;
    
    v_counter++;e_counter++;
  } while ((v_counter < G->no_v) && (e_counter < G->no_e));
  
  int X =0;
  e_path[0] =X; // number of edges found
  v_path[0] =X; // number of vertixes found.
  
  return e_list;
} // end find_path


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


int add_v(graph *G, long insert_v,long v_id){
/*
realloc() will have to be used here.
https://www.tutorialspoint.com/c_standard_library/c_function_realloc.htm
*/

    // don't insert vertices if bigger than no_v
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

int add_e(graph *G,long e_start, long start_v, long end_v,int direction,int fwd_weigh, int bk_weight){
// fprintf(stderr,"\nStart add_e %ld \n",e_start);
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
    G->v_in_deg[start_v] ++;
    
    if (G->use_incident==true){
      G->v_incidents[start_v][e_start]++;
      G->v_incidents[end_v][e_start]++;
    }
    // if this is self referencing then it is valid to say 
    // it has two edges added not just one.
    // I will have to research this.
    G->v_degree[end_v] ++;
    G->v_out_deg[end_v] ++;
    
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
* A unique path menas that even if the starting vertices are different 
* The code msut be clever enought to know that the path is the same.
* Watch https://www.youtube.com/watch?v=dQr4wZCiJJ4&t=0s&index=6&list=PLQ3WsqGOBztQQxp7Nw1svSn0Y9Hi6isda
**/


long find_unique_hameltonain_path(graph *G){return 0;}

/**
* get_degree of the vertix.
* this is the total degree both in and out
**/

long get_degree(graph * G, int start_v){return (start_v < G->no_v ? G->v_degree[start_v]:-1);}

/**
*
* For vertix in a directed graph in degree is the number of edges 
* going into that vertix.
* out degree is the edges leaving the vertix.
*
**/

long get_in_degree(graph *G, long v){return (v < G->no_v ? G->v_in_deg[v]:-1);}
long get_out_degree(graph *G, long v){return (v < G->no_v ? G->v_out_deg[v]:-1);}

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
* Search for an edges that has a start or end pos that is equal to the vertix being sent down.
* v_start is the vertix which will be at the beginning or end of an edge.
* e_start is the edge to start at.
* pos is either 0,1 or 2
*   if pos is 0 search for edges that start at this vertix.
*   if pos is 1 search for edges that end at this vertix.
*   if pos is 2 search for edges that start and end at this vertix.
**/


long * find_edges(graph *G, long v_start,long e_start, long pos ){
  
  // Validation 
  if (e_start < 0){long * fin_e_list = (long *) calloc((1), sizeof(long)); return fin_e_list;}
  if (v_start < 0){long * fin_e_list = (long *) calloc((1), sizeof(long)); return fin_e_list;}
  if (v_start > G->no_v){long * fin_e_list = (long *) calloc((1), sizeof(long)); return fin_e_list;}
  if (e_start > G->no_e){long * fin_e_list = (long *) calloc((1), sizeof(long)); return fin_e_list;}
  
  long i = 0; long j=0;
  long * e_list = (long *) calloc(G->no_e, sizeof(long));
  long degree =0;
    
  for (i=e_start; i< G->no_e; i++){
    if (pos >= 2){
      if (G->e[i][0]==v_start){
        e_list[j] = i;
        j++;
      }
      if (G->e[i][1]==v_start){
        e_list[j] = i;        
        j++;
      }      
    } else { 
      /**
      * if the direction of the edge is 1 then return only 
      * the position requested.
      * if the edge runs in both directions then the concept of
      * a start point is not relivent so return both start and end points.
      **/
      
      if (G->e[i][2] < 2){
        if (G->e[i][pos]==v_start){
          e_list[j] = i;
          j++;
        }
      } else {
        if (G->e[i][0]==v_start){
          e_list[j] = i;
          j++;
        }
        if (G->e[i][1]==v_start){
          e_list[j] = i;        
          j++;
        }   
      } // end if G->e[i][2]==1
    } // end if pos else
  } // end for i

  /**
  * If start_e too large then edges may be missed.  Get the degree and compare it.
  * If the degree is wrong then start at the beginning of edges and search.
  **/
  
  if (pos >= 2){degree = get_degree(G,v_start);}
  else if (pos ==0){degree = get_in_degree(G,v_start);}
  else {degree = get_in_degree(G,v_start);}

  if (j != degree){
    for (i=0; i < e_start; i++){
      if (pos >= 2){
        if (G->e[i][0]==v_start){
          e_list[j] = i;
          j++;
        }
        if (G->e[i][1]==v_start){
          e_list[j] = i;        
          j++;
        }      
      } else { 
        /**
        * if the direction of the edge is 1 then return only 
        * the position requested.
        * if the edge runs in both directions then the concept of
        * a start point is not relivent so return both start and end points.
        **/
      
        if (G->e[i][2] < 2){
          if (G->e[i][pos]==v_start){
            e_list[j] = i;
            j++;
          }
        } else {
          if (G->e[i][0]==v_start){
            e_list[j] = i;
            j++;
          }
          if (G->e[i][1]==v_start){
            e_list[j] = i;        
            j++;
          }   
        } // end if G->e[i][2]==1
      } // end if pos else
    } // end for i  
  } // END if (j != degree)
  
  e_list = (long *) realloc(e_list, j *sizeof(long));  
  
  long * fin_e_list = (long *) calloc((j+1), sizeof(long));
  fin_e_list[0]=j; //Return the number of edges along with the edges themselves.
  for (i=1; i <=j; i++) {fin_e_list[i]=e_list[i-1]; }
  return fin_e_list;
}


/**
* search array_1 against array_2
* pass down the size of both arays makes the function a bit more re-useable.
* start at a particular point in each array offset can be different for each array.
* the function returns the common elements and the number of elements in common.
**/

long * find_common_elem(long * arr_1, long * arr_2, long len_1, long len_2, long ofset_1, long ofset_2){

  long i=0; long j=0; 
  long t_found=0;
  long * found_l = (long*) calloc((len_1+len_2),sizeof(long));
     
  for (i=ofset_1; i <=len_1; i++){
    for(j=ofset_2; j <=len_2; j++){
      if (arr_1[i] == arr_2[j]){found_l[t_found+1]=arr_1[i];t_found++;}
    } // end for j
  }  // end for i

  found_l[0] = t_found;
  found_l =(long *) realloc(found_l,(t_found+1) *sizeof(long));

  return found_l;
}


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
* A bridge edge is an edge which when removed breaks the graph
* into two graphs.  
* The degree of the node at the start of bridge will be grater than or euqal to
* the degree of the node at the end of the bridge edge.
*.
* This will find potential bridges not guaranteed ones.
* The final test is that removing the edge creates more valid graphs.
* This huristic has a problem with a line of connected nodes 
**/


long * find_first_bridge_e(graph *G, long start_v, long end_v) {

  long *r_err;
  r_err = (long*) calloc(1,sizeof(long));
  r_err[0] =-1;
  long t_deg =0;  //float avg_deg =0;
  
  if (start_v > end_v){return r_err;}
  if (start_v < 0){return r_err;}
  if (end_v > G->no_v){return r_err;}
  if (end_v==start_v){r_err[0]++; return r_err;}

  long i=0; long prev_deg=0; long cur_deg=0;
  long * edge_list; // long * edge_list_1; long * edge_list_2;
  // Do a quick search to find the most obvious potential edges.
  // Return the first one found.
  
  for (i=start_v; i < end_v;i++){
    cur_deg = get_degree(G,i);
    t_deg += cur_deg;
    // any vertix with a single edge is a bridge.
    // it is a pendent node.
    
    if (cur_deg ==1){
      edge_list = find_edges(G,i,0,2);
      // There is no need to use the find_cycle function here.
      // A vertix with a single edge cannot be on a cycle.
      if (edge_list[0]>0){return edge_list;}
    }
    
    if (i > start_v){
      if (cur_deg > prev_deg){
        edge_list = find_edges(G,i,0,2);
        if (edge_list[0]>0){find_cycle_e(G,i, edge_list, -1, 0); return edge_list;}
      } // if (cur_dep>prev_deg)
    } // if (i > start_v)
    
    if (i==(start_v+1)) {
      // Test the start vertix which could not be tested 
      // as there was nothing to compare it with
      // Check the degree of the first vertix against the previous degree
      // this can only be done at this pint as there was nothing to chekc at
      // the start of the loop.  

      if (cur_deg < prev_deg) {
      // Find the edges of the first vertix (start_v)
        edge_list = find_edges(G,start_v,0,2);
        if (edge_list[0]>0){find_cycle_e(G,start_v, edge_list, -1, 0); return edge_list;}
      } 
    } // if (i==(start_v+1))
    prev_deg = cur_deg;
  } // end for i=start_v
  
  return r_err;
}

/**
* {Graph g} - 
* {Start_v} - the start vertix to search from.
* {edte_list} - the list of edges to search the start vertix has if a vertix has no edges 
*              this function is pointless and should not be used 
* {fwd_bk_nut} - Direction of search values -1, 0, 1
*              -1 is backword search start at lowest adjacent vertix to start_v
*              0 allow function to decide which will be based on how close the vertix is 
*                to the end of the graph.
*              1 start at the highest connected vertix to the start vertix.
* {direction} - used to check the direction of edges.
**/

long find_cycle_e(graph *G, long v_start, long * edge_list, long fwd_bk_nut, long direction){
  G->e_cycles = (long*) calloc(G->no_e, sizeof(long));  
  G->v_cycles = (long*) calloc(G->no_v, sizeof(long));
  long first_v =0; // First is the vertix start the walk on.
  long cur_v=0; long e_count =0;
  if (G->no_v < v_start) {return -1;}
  if ((fwd_bk_nut !=-1) && (fwd_bk_nut !=0) &&  (fwd_bk_nut !=1)){return -1;}
  long * vertix_list;
  long * edge_list_1;
   
  // If the search is nutral then use the start_v if it is more than half the size of the 
  // no_v the start searching from the vertix to the end of the graph.
  // if it is less then half then search from the end of the graph.
  if (fwd_bk_nut ==0) {fwd_bk_nut = ((v_start *2 > G->no_v) ? 1 :-1); }
  long i=0; // long j=0;
  // Put the edges into the cycle
  // These will be searched to find cycles.
  for (i=1; i <= edge_list[0]; i++){ 
    G->e_cycles[(i-1)] = edge_list[i]; 
    vertix_list = get_vertix(G, edge_list[i]);
    if (i==1){first_v=vertix_list[0];}
    if (fwd_bk_nut==-1){
      if (first_v > vertix_list[0]) {first_v = vertix_list[0];}
      if (first_v > vertix_list[1]) {first_v = vertix_list[1];}
    } else {
      if (first_v < vertix_list[0]) {first_v = vertix_list[0];}
      if (first_v < vertix_list[1]) {first_v = vertix_list[1];}
    } // end if (fwd_bk_nut==-1)    
  } // end for i=1
  
  fprintf(stderr,"\nfirst_v=%ld v_start=%ld",first_v,v_start);
  for (i=1; i <= edge_list[0]; i++){
    fprintf(stderr,"\nedge_list[%ld]=%ld",i,edge_list[i]);
  }
  fprintf (stderr,"\n");
  
  G->e_cycles[edge_list[0]+1]=-1; // use this to mark the end of the sequence.
  
  G->v_cycles[0] = v_start; 
  if (G->no_v > 1) {G->v_cycles[1] = first_v;}
  cur_v=-1; 
  // Walk until the start vertix is returned to
  // or all the edges have been walked.
  // Start at the start vertix
  edge_list_1 = find_edges(G,v_start,0,2);
  
  while ((v_start != cur_v) || (e_count > G->no_e)){
    e_count ++;
    if (edge_list_1[0]>0){}
    
    if (fwd_bk_nut==-1){
  
    } else {
  
    } // end if
  } // end while
      
  return 0;
}

/**
* This funciton takes two graphs and returns a combination of them.
* whether this combination makes sense as a graph is up to the user to decide.
* To combine the graoh a link will have to be created between two graphs.
* to passs doen the bridge vetix form graph 1 and graph 2.
**/
graph combine_g(graph * G1, graph * G2, long bridge_v1, long bridge_v2,int direction,int fwd_weigh, int bk_weight){
  graph G3;
  long no_e; long no_v; long i=0; long j=0; long v_offset=0; long e_offset=0;
  no_e = G1->no_e + G2->no_e;
  no_v = G1->no_v + G2->no_v;
  if (init_G(&G3,no_e,no_v) !=-1){
  // Start copying over the first graph edges
    for (i=0; i < G1->no_e; i++){
      for (j=0; j< E_ATTRIB_SIZE; j++){G3.e[i][j] = G1->e[i][j];}
    } // end for i
    
    for (i=0; i < G1->no_v; i++){
      G3.v[i] = G1->v[i];
      G3.v_degree[i] = G1->v_degree[i];
      G3.v_in_deg[i] = G1->v_in_deg[i];
      G3.v_out_deg[i] = G1->v_out_deg[i];
    } // end for i=0
    
    // Calculate the off-set to increment the vertix id.
    // and the edged offset.
    v_offset = no_v - G1->no_v;
    e_offset = no_e - G1->no_e;
    
    for (i=0; i < G2->no_v; i++){
      G3.v[(i+v_offset)] = G2->v[i]+v_offset;
      G3.v_degree[(i+v_offset)] = G2->v_degree[i];
      G3.v_in_deg[(i+v_offset)] = G2->v_in_deg[i];
      G3.v_out_deg[(i+v_offset)] = G2->v_out_deg[i];
    } // end for i=0
    
    // Add edges and increment the verticies by the offset.
    // when combining two graphs G1={v0,v1,v2} G2={v0,v1.v2}.
    // G3={v0,v1,v2,v3,v4,v5}
    // Edges on G2 must be changed to point at the incremented verticies.
    
    for (i=0; i < G2->no_e; i++){
      for (j=0; j< E_ATTRIB_SIZE; j++){
        if (j==0 || j==1){
          G3.e[(i+e_offset)][j] = (G2->e[i][j]+v_offset); 
        } else {
          G3.e[(i+e_offset)][j] = G2->e[i][j];
        }  // end if
      } // end for j
    } // end for i
  } // end if init_G
  
  if ((bridge_v1 > -1) && (bridge_v2 > -1)){
    if ((bridge_v1 < G1->no_v) && (bridge_v2 < G2->no_v)){
      add_e(&G3,no_e, bridge_v1, (bridge_v2+v_offset),direction,fwd_weigh, bk_weight);    
    }
  }
  
  return G3;
}

/**
* Graph Theory: 48. Complement of a Graph
* https://www.youtube.com/watch?v=VTgxv334KSU
*
**/


int g_complement() {return 0;}

/**
* Graph Theory: 53. Cut-Vertices
* https://www.youtube.com/watch?v=BxAgmaLWaq4
*
**/



long find_cut_v(graph *G){return 0;}

int v_valid_distance(graph *G, int start_v, int end_v, int direction){return 0;}

/**
* Graph Theory: 51. Eccentricity, Radius & Diameter
* get_diamater and get radious
* https://www.youtube.com/watch?v=YbCn8d4Enos&list=PLoJC20gNfC2gmT_5WgwYwGMvgCjYVsIQg&index=55
**/


int get_eccentricity(graph *G){return 0;}
int get_diamater(graph *G){return 0;}
int get_radious(graph *G){return 0;}

/**
* get the vertix at the start and end of an edge
**/

long * get_vertix(graph *G, long e){ 
  long * v_arr;
  v_arr = (long*) calloc(2, sizeof(long));
  v_arr[0]=-1; v_arr[1]=-1;
  if (e > G->no_e){return v_arr;}
  v_arr[0] = G->e[e][0]; v_arr[1] = G->e[e][1];
  return v_arr;
}

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
  char tmp_line; // used to check if the last char is part of a number more than one digit.
  char tmp_line_1[10]; // allow up to 10 digits for first number.
  char output_msg[1024];    
  int no_l =0; int i; int j; long no_e=0; long no_v =0; long l_size =0; int adj_i=0;
  G->use_adj = true;
  G->use_incident = true;
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
        if (i>0){ tmp_line = line[i-1];}
        else {tmp_line = line[i];}
        
        if(line[i]=='\n') {l_size=i;} 
        else {
          if(line[i] != delim){
            if (tmp_line == delim){no_v++;}
          }
        }
      } // end for
      // l_size is reduced by 1 exclude line return
      // may need to revise for windows.
      l_size--;
    } else {
      /**
      * Initilize parts of the graph which depend on the no_v.
      * After line 0 we have the number of vertices.
      * the edges (in an adjacency matrix can be a maximum of the square 
      * of the verticies.
      **/      
      if (no_l==1) {init_G(G,(no_v*no_v),no_v);}
      
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
          if (i==0){
            while (line[i] !=delim){
              tmp_line_1[i]=line[i];
              i++;
            }
            G->v[(no_l-1)] = atol(tmp_line_1);
          
          } else {
            if (adj_i < no_v){
              G->v_adj[(no_l-1)][adj_i] = atol(&line[i]);
            }
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
    * THIS MAY NOT BE CORRECT WILL HAVE TO THINK THIS THROUGH
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
  
  if (G->no_e != no_e){
    // Free up the remaining memory
    G->no_e = no_e;
    G->e = (long **) realloc(G->e, G->no_e *sizeof(long));  
  }
  
  return 0;
}

int read_incidence(graph *G, char delim,char * IfileName){
  FILE* fd;
  char line[2048];
  char tmp_line; // used to check if the last char is part of a number more than one digit.
  char tmp_line_1[10]; // allow up to 10 digits for first number.
  char output_msg[1024];    
  int no_l =0; int i; long v; long e; long no_e=0; long no_v =0; long l_size =0; long inc_i=0;
  long start_v=-1; long end_v=-1;
  
  sprintf(output_msg,"function read_incidence failed to open file %s",IfileName);  
  if ((fd=fopen(IfileName,"r"))==NULL){return log_error(output_msg);}

  while (fgets(line,sizeof(line),fd)){    
    if (no_l == 0){
      l_size = sizeof(line);
      for (i=0;i < l_size; i++){        
        if (i>0){ tmp_line = line[i-1];}
        else {tmp_line = line[i];}
        
        if(line[i]=='\n') {l_size=i;} 
        else {
          if(line[i] != delim){
            if (tmp_line == delim){no_e++;}
          }
        }
      } // end for
      // l_size is reduced by 1 exclude line return
      // may need to revise for windows.
      l_size--;
    } else { 
      /**
      * Initalise the graph the no_v is no_e *2
      * need to lookup what to do with graph with a lot of 
      * non-connected verticies.
      * the no_e as an edge has a start and end vetix.
      * In reality this will be far less. 
      **/
      
      if (no_l==1) {init_G(G,no_e,no_e*2);}
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
          if (i==0){
            while (line[i] !=delim){
              tmp_line_1[i]=line[i];
              i++;
            }
            G->v[(no_l-1)] = atol(tmp_line_1);
            no_v++;
          } else {
            G->v_incidents[(no_l-1)][inc_i] = atol(&line[i]);
            inc_i++;
          } // end if i==0
        } // end if not delim
      } // end for
    } // end if (no_l ==0)
    no_l +=1;
    inc_i =0;
  } // end while
  
  /**
  * Close file as it is not needed. If there is a crash later this will be clean.
  **/
  
  fclose(fd);
  
  G->no_v = no_v;
  G->v = (long *) realloc(G->v, G->no_v *sizeof(long));  

  /**
  *
  * Process the array column by column
  * Edges are the columns.
  * Each column will have two 1's or a 2 where there is a caycl.
  * Once the start and end point are found add the edge and move on.
  *
  * These structures are not very good for recording direction.
  *
  **/
  G->use_incident=false;  // prevent add_e incrementing incidence matrix 
  for (e=0;e<no_e;e++){
    for (v=0;v<no_v;v++){
      if (G->v_incidents[v][e] > 0){
      // If the incience is 1 then 
      // there is no cycle and the start and end
      // vertix will be different
        if (G->v_incidents[v][e]==1){
          if (start_v==-1){start_v=v; }
          else if (end_v==-1){end_v=v; v=no_v;}
        } else {
          start_v=v; end_v=v; v=no_v;
        }
        // Once the end vertix has been found no need to 
        // Process the rest of the matrix as it will be 0 
      }  // end if incidents <0
    } // end for v
    if ((start_v >-1) && (end_v >-1)){
      add_e(G,e,start_v,end_v,0,0,0);
      start_v=-1; end_v=-1;
    }
  } // end for e
  G->use_incident=true;
  return 0;
}


int write_adjency(graph *G, char delim,char * OfileName){
  int i=0; int j=0;
  FILE* fd;

  char output_msg[1024];
  sprintf(output_msg,"function write_adjency Failed to Open File Name %s",OfileName);

  if (strcmp(OfileName,"")==0){ fd=stdout;} 
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
  
  if (strcmp(OfileName,"")!=0){fclose(fd);}
  
  return 0;
}


int write_incidence(graph *G, char delim,char * OfileName){
  int i=0; int j=0;

  FILE* fd;

  char output_msg[1024];
  sprintf(output_msg,"function write_incidents Failed to Open File Name %s",OfileName);

  if (strcmp(OfileName,"")==0){ fd=stdout;} 
  else { 
    fclose(stdout);
    if ((fd=fopen(OfileName,"w"))==NULL){return log_error(output_msg);}
  }

  fprintf(fd,"%c",delim);
  for (i=0;i< G->no_e;i++){
      if (G->e[i][0] !=-1){
        fprintf(fd,"%c%d",delim,i);
      } else {i=G->no_e;} // End the loop because no more edges exist.
  }
  for (i=0;i<G->no_v;i++){
      if (G->v[i] !=-1){
        fprintf(fd,"\n%ld",G->v[i]);
        for (j=0;j<G->no_e;j++){
            if (G->e[j][0] !=-1){
                fprintf(fd,"%c%ld",delim,G->v_incidents[i][j]);
            } else {j=G->no_e;}
        }
      } else {i=G->no_v;} // End the loop because no more verticies exist.
  }
  if (strcmp(OfileName,"")!=0){fclose(fd);}
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
  G->use_adj = false;
  
  if(no_v > 0){
    G->no_v = no_v;
    G->v = (long*) calloc(no_v, sizeof(long));
    G->v_degree = (long*) calloc(no_v, sizeof(long));
    G->v_in_deg = (long*) calloc(no_v, sizeof(long));
    G->v_out_deg = (long*) calloc(no_v, sizeof(long));
    G->v_adj = (long**) calloc(no_v, sizeof(long));
    G->v_incidents = (long**) calloc(no_v, sizeof(long));
    
    for (i=0; i<no_v;i++) {
      G->v[i] = -1;
      G->v_adj[i] = (long*) calloc(no_v, sizeof(long));
      if (no_e >0) {G->v_incidents[i] = (long*) calloc(no_e, sizeof(long));}
    } // end for i
  } // end no_v >0
  
  if(no_e > 0){  
    G->no_e = no_e;
    G->e = (long **) calloc(no_e, sizeof(long));
    
    for (i=0; i < no_e; i++){
      G->e[i]=(long*) calloc(E_ATTRIB_SIZE, sizeof(long));
      for (j=0; j < E_ATTRIB_SIZE; j++){
          G->e[i][j]=-1;
      } // end for j
    } // end for i  
  } // end no_e >0
  
  return 0;
}


int disp_graph(graph *G, int no_e, int no_v){
  int i,j;
  for (i=0; i < no_e; i++){
      for (j=0; j < E_ATTRIB_SIZE; j++){
          fprintf(stderr,"\nG->e[%d][%d]=%ld",i,j,G->e[i][j]);
      }
  }
   
  for (i=0; i<no_v;i++){
      fprintf(stderr,"\nG.v[%d]=%ld",i,G->v[i]);
  }
  return 0;
}

long get_fwd_weight(graph *G, long e_start)
{ return (e_start < G->no_e ? G->e[e_start][3] : -1);}

long get_bk_weight(graph *G, long e_start)
{ return (e_start < G->no_e ? G->e[e_start][4] : -1);}


long set_fwd_weight(graph *G, long e_start, long w){ 
  if (e_start < G->no_e){G->e[e_start][3] = w;}
  else {return -1;} 
  return G->e[e_start][3];
}

long set_bk_weight(graph *G, long e_start, long w){ 
  if (e_start < G->no_e){G->e[e_start][4] = w;}
  else {return -1;} 
  return G->e[e_start][4];
}

