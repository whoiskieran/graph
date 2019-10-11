/**
* A property is on an edger or vertix
* Edges and Verticies can have multiple properties.
* prop_n and prop_v store the name and value of the property.
* two of arrays these structures should be created edge properties and vertix properties.
* not all edges and verticies will have properties so an id field will used to access them.
**/

typedef struct property {
  long id;
  char **prop_n;
  char **prop_v;
  long no_ent;  // total no of elements
  long cur_ent; //the current element increment when alement is added.
} property;	


int add_nv(property *P, long id, char *name, char *val){
  return 0;
}