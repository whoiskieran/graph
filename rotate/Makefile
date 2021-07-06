CFLAGS = -O3 -g -Wall -fstrict-aliasing -std=c99 -I ../src

all: rotate_v_id 

rotate_v_id:rotate_v_id.c 
	@echo "###### Rotate v id #####"
	$(CC) $(CFLAGS) rotate_v_id.c -o $@

	./$@ -E 3 -V 3 -I "../src/unit_test/adj_matrix/adjacency_matrix_1_3_Verticies_All_Combos.txt" -O "rotated_1_3_Verticies_All_Combos.txt" 
	./$@ -E 3 -V 3 -I "../src/unit_test/adj_matrix/adjacency_matrix_2_3_Verticies_All_Combos.txt" -O "rotated_2_3_Verticies_All_Combos.txt"
	./$@ -E 6 -V 3 -I "../src/unit_test/adj_matrix/adjacency_matrix_3_3_Verticies_All_Combos.txt" -O "rotated_3_3_Verticies_All_Combos.txt"
	./$@ -E 6 -V 3 -I "../src/unit_test/adj_matrix/adjacency_matrix_4_3_Verticies_All_Combos.txt" -O "rotated_4_3_Verticies_All_Combos.txt"
	./$@ -E 6 -V 7 -I "../src/unit_test/adj_matrix/adjacency_matrix_1_binary-tree.txt" -O "rotated_1_binary-tree.txt"
	./$@ -E 6 -V 7 -I "../src/unit_test/adj_matrix/adjacency_matrix_2_binary-tree.txt" -O "rotated_2_binary-tree.txt"
	./$@ -E 4 -V 6 -I "../src/unit_test/adj_matrix/adjacency_matrix_Linked_List_Verticie.txt" -O "rotated_Linked_List_Verticie.txt"
	./$@ -E 12 -V 12 -I "../src/unit_test/adj_matrix/adjacency_matrix_12_Node_Graph.txt" -O "rotated_12_Node_Graph.txt"
	./$@ -E 10 -V 9 -I "../src/unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge.txt" -O "rotated__Find_Bridge_Edge.txt"
	./$@ -E 5 -V 5 -I "../src/unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_1.txt" -O "rotated_Find_Bridge_Edge_1.txt"
	./$@ -E 8 -V 7 -I "../src/unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "rotated_Find_Bridge_Edge_2.txt"
	./$@ -E 3 -V 4 -I "../src/unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_3.txt" -O "rotated_Find_Bridge_Edge_3.txt"
	./$@ -E 9 -V 8 -I "../src/unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_4.txt" -O "rotated_Find_Bridge_Edge_4.txt"
	./$@ -E 7 -V 6 -I "../src/unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "rotated_Articulation_Point.txt"
	./$@ -E 7 -V 7 -I "../src/unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "rotated_Find_Bridge_Edge_2_Error.txt"
	./$@ -E 8 -V 7 -I "../src/unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "rotated_Find_Bridge_Edge_2.txt"
	./$@ -E 0 -V 4 -I "../src/unit_test/adj_matrix/adjacency_matrix_No_Edges.txt" -O "rotated__No_Edges.txt"
	./$@ -E 12 -V 11 -I "../src/unit_test/adj_matrix/Spoke_Node_Connects_Sections.txt" -O "rotated_Spoke_Node_Connects_Sections.txt"
	./$@ -E 17 -V 15 -I "../src/unit_test/adj_matrix/Three_Sections_Connected_By_Separate_Nodes.txt" -O "rotated_Three_Sections_Connected_By_Separate_Nodes.txt"
	./$@ -E 11 -V 10  -I "../src/unit_test/adj_matrix/Two_Section_Connected_By_One_Edge.txt" -O "rotated_Two_Section_Connected_By_One_Edge.txt"
	./$@ -E 12 -V 11 -I "../src/unit_test/adj_matrix/Two_Section_Connected_By_One_Node.txt" -O "rotated_Two_Section_Connected_By_One_Node.txt"
       
	rm $@
