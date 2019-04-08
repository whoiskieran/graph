CFLAGS = -O3 -g -Wall -fstrict-aliasing -std=c99 -I ../src

all: test_1_parse test_1_init test_1_add_v test_1_add_e test_1_get_degree test_1_set_adj test_1_v_distance test_1_edge_exists test_1_write_adjency test_1_read_adjency test_2_get_degree test_1_find_edges test_1_write_incidence test_1_read_incidence test_1_find_first_bridge_e
		
test:unit_test/test.c
	$(CC) $(CFLAGS) unit_test/test.c -o unit_test/$@
	./unit_test/$@

test_1_parse:unit_test/test_1_parse.c 
	@echo "###### Test ONE parse #####"
	$(CC) $(CFLAGS) unit_test/test_1_parse.c -o unit_test/$@
	./unit_test/$@ -E 3 -V 3 -I input.txt -O output.txt
	rm unit_test/$@
	
test_1_init:unit_test/test_1_init.c 
	@echo "###### Test ONE init #####"
	$(CC) $(CFLAGS) unit_test/test_1_init.c -o unit_test/$@
	./unit_test/$@
	rm unit_test/$@

test_1_add_v:unit_test/test_1_add_v.c 
	@echo "###### Test ONE add vertix #####"
	$(CC) $(CFLAGS) unit_test/test_1_add_v.c -o unit_test/$@
	./unit_test/$@
	rm unit_test/$@

test_1_add_e:unit_test/test_1_add_e.c 
	@echo "###### Test ONE add edge #####"
	$(CC) $(CFLAGS) unit_test/test_1_add_e.c -o unit_test/$@
	./unit_test/$@
	rm unit_test/$@

test_2_add_e:unit_test/test_2_add_e.c 
	@echo "###### Test TWO add edge #####"
	$(CC) $(CFLAGS) unit_test/test_2_add_e.c -o unit_test/$@
	./unit_test/$@
	rm unit_test/$@

test_3_add_e:unit_test/test_3_add_e.c 
	@echo "###### Test THREE add edge #####"
	$(CC) $(CFLAGS) unit_test/test_3_add_e.c -o unit_test/$@
	./unit_test/$@
	rm unit_test/$@
	
test_1_get_degree:unit_test/test_1_get_degree.c 
	@echo "###### Test ONE get degree #####"
	$(CC) $(CFLAGS) unit_test/test_1_get_degree.c -o unit_test/$@
	./unit_test/$@
	rm unit_test/$@

test_1_set_adj:unit_test/test_1_set_adj.c 
	@echo "###### Test ONE set adjency #####"
	$(CC) $(CFLAGS) unit_test/test_1_set_adj.c -o unit_test/$@
	./unit_test/$@
	rm unit_test/$@

test_1_v_distance:unit_test/test_1_v_distance.c 
	@echo "###### Test ONE direction and adjency matrix set to TRUE #####"
	$(CC) $(CFLAGS) unit_test/test_1_v_distance.c -o unit_test/$@
	./unit_test/$@
	rm unit_test/$@

test_1_edge_exists:unit_test/test_1_edge_exists.c 
	@echo "###### Test ONE edge exists #####"
	$(CC) $(CFLAGS) unit_test/test_1_edge_exists.c -o unit_test/$@
	./unit_test/$@
	rm unit_test/$@

test_1_write_adjency:unit_test/test_1_write_adjency.c 
	@echo "###### Test ONE write_adjency #####"
	$(CC) $(CFLAGS) unit_test/test_1_write_adjency.c -o unit_test/$@
		
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_1_3_Verticies_All_Combos.txt" -O "unit_test/out_1.txt" 
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_1_3_Verticies_All_Combos.txt" "unit_test/out_1.txt"
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_2_3_Verticies_All_Combos.txt" -O "unit_test/out_2.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_2_3_Verticies_All_Combos.txt" "unit_test/out_2.txt"
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_3_3_Verticies_All_Combos.txt" -O "unit_test/out_3.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_3_3_Verticies_All_Combos.txt" "unit_test/out_3.txt"
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_4_3_Verticies_All_Combos.txt" -O "unit_test/out_4.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_4_3_Verticies_All_Combos.txt" "unit_test/out_4.txt"
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_1_binary-tree.txt" -O "unit_test/out_5.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_1_binary-tree.txt" "unit_test/out_5.txt"
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_2_binary-tree.txt" -O "unit_test/out_6.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_2_binary-tree.txt" "unit_test/out_6.txt"
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_Linked_List_Verticie.txt" -O "unit_test/out_7.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_Linked_List_Verticie.txt" "unit_test/out_7.txt"
	./unit_test/$@ -E 12 -V 12 -I "unit_test/adj_matrix/adjacency_matrix_12_Node_Graph.txt" -O "unit_test/out_8.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_12_Node_Graph.txt" "unit_test/out_8.txt"
	./unit_test/$@ -E 10 -V 9 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge.txt" -O "unit_test/out_9.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge.txt" "unit_test/out_9.txt"
	./unit_test/$@ -E 5 -V 5 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_1.txt" -O "unit_test/out_10.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_1.txt" "unit_test/out_10.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_11.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" "unit_test/out_11.txt"
	./unit_test/$@ -E 3 -V 4 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_3.txt" -O "unit_test/out_12.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_3.txt" "unit_test/out_12.txt"
	./unit_test/$@ -E 9 -V 8 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_4.txt" -O "unit_test/out_13.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_4.txt" "unit_test/out_13.txt"
	
	rm unit_test/$@
	rm unit_test/out*.txt


test_1_read_adjency:unit_test/test_1_read_adjency.c 
	@echo "###### Test ONE read_adjency #####"
	$(CC) $(CFLAGS) unit_test/test_1_read_adjency.c -o unit_test/$@
		
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_1_3_Verticies_All_Combos.txt" -O "unit_test/out_1.txt" 
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_1_3_Verticies_All_Combos.txt" "unit_test/out_1.txt"
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_2_3_Verticies_All_Combos.txt" -O "unit_test/out_2.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_2_3_Verticies_All_Combos.txt" "unit_test/out_2.txt"
	./unit_test/$@ -E 6 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_3_3_Verticies_All_Combos.txt" -O "unit_test/out_3.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_3_3_Verticies_All_Combos.txt" "unit_test/out_3.txt"
	./unit_test/$@ -E 6 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_4_3_Verticies_All_Combos.txt" -O "unit_test/out_4.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_4_3_Verticies_All_Combos.txt" "unit_test/out_4.txt"
	./unit_test/$@ -E 6 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_1_binary-tree.txt" -O "unit_test/out_5.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_1_binary-tree.txt" "unit_test/out_5.txt"
	./unit_test/$@ -E 6 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_2_binary-tree.txt" -O "unit_test/out_6.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_2_binary-tree.txt" "unit_test/out_6.txt"
	./unit_test/$@ -E 4 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Linked_List_Verticie.txt" -O "unit_test/out_7.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_Linked_List_Verticie.txt" "unit_test/out_7.txt"	
	./unit_test/$@ -E 12 -V 12 -I "unit_test/adj_matrix/adjacency_matrix_12_Node_Graph.txt" -O "unit_test/out_8.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_12_Node_Graph.txt" "unit_test/out_8.txt"
	./unit_test/$@ -E 10 -V 9 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge.txt" -O "unit_test/out_9.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge.txt" "unit_test/out_9.txt"	
	./unit_test/$@ -E 5 -V 5 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_1.txt" -O "unit_test/out_10.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_1.txt" "unit_test/out_10.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_11.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" "unit_test/out_11.txt"
	./unit_test/$@ -E 3 -V 4 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_3.txt" -O "unit_test/out_12.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_3.txt" "unit_test/out_12.txt"
	./unit_test/$@ -E 9 -V 8 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_4.txt" -O "unit_test/out_13.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_4.txt" "unit_test/out_13.txt"
	
	rm unit_test/$@
	rm unit_test/out*.txt

test_2_get_degree:unit_test/test_2_get_degree.c 
	@echo "###### Test TWO get degree #####"
	$(CC) $(CFLAGS) unit_test/test_2_get_degree.c -o unit_test/$@

	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_1_3_Verticies_All_Combos.txt" -O "unit_test/out_1.txt" 
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_2_3_Verticies_All_Combos.txt" -O "unit_test/out_2.txt"
	./unit_test/$@ -E 6 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_3_3_Verticies_All_Combos.txt" -O "unit_test/out_3.txt"
	./unit_test/$@ -E 6 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_4_3_Verticies_All_Combos.txt" -O "unit_test/out_4.txt"
	./unit_test/$@ -E 6 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_1_binary-tree.txt" -O "unit_test/out_5.txt"
	./unit_test/$@ -E 6 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_2_binary-tree.txt" -O "unit_test/out_6.txt"
	./unit_test/$@ -E 4 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Linked_List_Verticie.txt" -O "unit_test/out_7.txt"
	./unit_test/$@ -E 12 -V 12 -I "unit_test/adj_matrix/adjacency_matrix_12_Node_Graph.txt" -O "unit_test/out_8.txt"
	./unit_test/$@ -E 10 -V 9 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge.txt" -O "unit_test/out_9.txt"
	./unit_test/$@ -E 5 -V 5 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_1.txt" -O "unit_test/out_10.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_11.txt"
	./unit_test/$@ -E 3 -V 4 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_3.txt" -O "unit_test/out_12.txt"
	./unit_test/$@ -E 9 -V 8 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_4.txt" -O "unit_test/out_13.txt"
	
	rm unit_test/$@
	
test_1_find_edges:unit_test/test_1_find_edges.c 
	@echo "###### Test ONE find edges #####"
	$(CC) $(CFLAGS) unit_test/test_1_find_edges.c -o unit_test/$@

	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_1_3_Verticies_All_Combos.txt" -O "unit_test/out_1.txt" 
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_2_3_Verticies_All_Combos.txt" -O "unit_test/out_2.txt"
	./unit_test/$@ -E 6 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_3_3_Verticies_All_Combos.txt" -O "unit_test/out_3.txt"
	./unit_test/$@ -E 6 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_4_3_Verticies_All_Combos.txt" -O "unit_test/out_4.txt"
	./unit_test/$@ -E 6 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_1_binary-tree.txt" -O "unit_test/out_5.txt"
	./unit_test/$@ -E 6 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_2_binary-tree.txt" -O "unit_test/out_6.txt"
	./unit_test/$@ -E 4 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Linked_List_Verticie.txt" -O "unit_test/out_7.txt"
	./unit_test/$@ -E 12 -V 12 -I "unit_test/adj_matrix/adjacency_matrix_12_Node_Graph.txt" -O "unit_test/out_8.txt"
	./unit_test/$@ -E 10 -V 9 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge.txt" -O "unit_test/out_9.txt"
	./unit_test/$@ -E 5 -V 5 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_1.txt" -O "unit_test/out_10.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_11.txt"
	./unit_test/$@ -E 3 -V 4 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_3.txt" -O "unit_test/out_12.txt"
	./unit_test/$@ -E 9 -V 8 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_4.txt" -O "unit_test/out_13.txt"
	
	rm unit_test/$@
	
test_1_write_incidence:unit_test/test_1_write_incidence.c 
	@echo "###### Test ONE write_incidence #####"
	$(CC) $(CFLAGS) unit_test/test_1_write_incidence.c -o unit_test/$@
		
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_1_3_Verticies_All_Combos.txt" -O "unit_test/incidence_matrix/incidence_matrix_1_3_Verticies_All_Combos.txt" 
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_2_3_Verticies_All_Combos.txt" -O "unit_test/incidence_matrix/incidence_matrix_2_3_Verticies_All_Combos.txt"
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_3_3_Verticies_All_Combos.txt" -O "unit_test/incidence_matrix/incidence_matrix_3_3_Verticies_All_Combos.txt"
	./unit_test/$@ -E 6 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_4_3_Verticies_All_Combos.txt" -O "unit_test/incidence_matrix/incidence_matrix_4_3_Verticies_All_Combos.txt"
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_1_binary-tree.txt" -O "unit_test/incidence_matrix/incidence_matrix_1_binary-tree.txt"
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_2_binary-tree.txt" -O "unit_test/incidence_matrix/incidence_matrix_2_binary-tree.txt"
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_Linked_List_Verticie.txt" -O "unit_test/incidence_matrix/incidence_matrix_Linked_List_Verticie.txt"
	./unit_test/$@ -E 12 -V 12 -I "unit_test/adj_matrix/adjacency_matrix_12_Node_Graph.txt" -O "unit_test/incidence_matrix/incidence_matrix_12_Node_Graph.txt"
	./unit_test/$@ -E 10 -V 9 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge.txt" -O "unit_test/incidence_matrix/incidence_matrix_Find_Bridge_Edge.txt"
	./unit_test/$@ -E 5 -V 5 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_1.txt" -O "unit_test/incidence_matrix/incidence_matrix_Find_Bridge_Edge_1.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/incidence_matrix/incidence_matrix_Find_Bridge_Edge_2.txt"
	./unit_test/$@ -E 3 -V 4 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_3.txt" -O "unit_test/incidence_matrix/incidence_matrix_Find_Bridge_Edge_3.txt"
	./unit_test/$@ -E 9 -V 8 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_4.txt" -O "unit_test/incidence_matrix/incidence_matrix_Find_Bridge_Edge_4.txt"

	rm unit_test/$@


test_1_read_incidence:unit_test/test_1_read_incidence.c 
	@echo "###### Test ONE read_incidence #####"
	$(CC) $(CFLAGS) unit_test/test_1_read_incidence.c -o unit_test/$@
		
	./unit_test/$@ -E 3 -V 3 -I "unit_test/incidence_matrix/incidence_matrix_1_3_Verticies_All_Combos.txt" -O "unit_test/out_1.txt"  
	unit_test/test_1_read_adjency.sh "unit_test/incidence_matrix/incidence_matrix_1_3_Verticies_All_Combos.txt" "unit_test/out_1.txt"
	
	./unit_test/$@ -E 3 -V 3 -I "unit_test/incidence_matrix/incidence_matrix_2_3_Verticies_All_Combos.txt" -O "unit_test/out_2.txt"
	unit_test/test_1_read_adjency.sh "unit_test/incidence_matrix/incidence_matrix_2_3_Verticies_All_Combos.txt" "unit_test/out_2.txt"
	
	./unit_test/$@ -E 6 -V 3 -I "unit_test/incidence_matrix/incidence_matrix_3_3_Verticies_All_Combos.txt" -O "unit_test/out_3.txt"
	unit_test/test_1_read_adjency.sh "unit_test/incidence_matrix/incidence_matrix_3_3_Verticies_All_Combos.txt" "unit_test/out_3.txt"
	
	./unit_test/$@ -E 6 -V 3 -I "unit_test/incidence_matrix/incidence_matrix_4_3_Verticies_All_Combos.txt" -O "unit_test/out_4.txt"
	unit_test/test_1_read_adjency.sh "unit_test/incidence_matrix/incidence_matrix_4_3_Verticies_All_Combos.txt" "unit_test/out_4.txt"
	
	./unit_test/$@ -E 6 -V 7 -I "unit_test/incidence_matrix/incidence_matrix_1_binary-tree.txt" -O "unit_test/out_5.txt"
	unit_test/test_1_read_adjency.sh "unit_test/incidence_matrix/incidence_matrix_1_binary-tree.txt" "unit_test/out_5.txt"
	
	./unit_test/$@ -E 6 -V 7 -I "unit_test/incidence_matrix/incidence_matrix_2_binary-tree.txt" -O "unit_test/out_6.txt"
	unit_test/test_1_read_adjency.sh "unit_test/incidence_matrix/incidence_matrix_2_binary-tree.txt" "unit_test/out_6.txt"
	
	./unit_test/$@ -E 4 -V 6 -I "unit_test/incidence_matrix/incidence_matrix_Linked_List_Verticie.txt" -O "unit_test/out_7.txt"
	unit_test/test_1_read_adjency.sh "unit_test/incidence_matrix/incidence_matrix_Linked_List_Verticie.txt" "unit_test/out_7.txt"
	
	./unit_test/$@ -E 12 -V 12 -I "unit_test/incidence_matrix/incidence_matrix_12_Node_Graph.txt" -O "unit_test/out_8.txt"
	unit_test/test_1_read_adjency.sh "unit_test/incidence_matrix/incidence_matrix_12_Node_Graph.txt" "unit_test/out_8.txt"
	
	./unit_test/$@ -E 10 -V 9 -I "unit_test/incidence_matrix/incidence_matrix_Find_Bridge_Edge.txt" -O "unit_test/out_9.txt"
	unit_test/test_1_read_adjency.sh "unit_test/incidence_matrix/incidence_matrix_Find_Bridge_Edge.txt" "unit_test/out_9.txt"

	./unit_test/$@ -E 5 -V 5 -I "unit_test/incidence_matrix/incidence_matrix_Find_Bridge_Edge_1.txt" -O "unit_test/out_10.txt"
	unit_test/test_1_read_adjency.sh "unit_test/incidence_matrix/incidence_matrix_Find_Bridge_Edge_1.txt" "unit_test/out_10.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/incidence_matrix/incidence_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_11.txt"
	unit_test/test_1_read_adjency.sh "unit_test/incidence_matrix/incidence_matrix_Find_Bridge_Edge_2.txt" "unit_test/out_11.txt"
	./unit_test/$@ -E 3 -V 4 -I "unit_test/incidence_matrix/incidence_matrix_Find_Bridge_Edge_3.txt" -O "unit_test/out_12.txt"
	unit_test/test_1_read_adjency.sh "unit_test/incidence_matrix/incidence_matrix_Find_Bridge_Edge_3.txt" "unit_test/out_12.txt"
	./unit_test/$@ -E 9 -V 8 -I "unit_test/incidence_matrix/incidence_matrix_Find_Bridge_Edge_4.txt" -O "unit_test/out_13.txt"
	unit_test/test_1_read_adjency.sh "unit_test/incidence_matrix/incidence_matrix_Find_Bridge_Edge_4.txt" "unit_test/out_13.txt"

	rm unit_test/out*.txt
	rm unit_test/$@

test_1_find_first_bridge_e:unit_test/test_1_find_first_bridge_e.c 
	@echo "###### Test ONE find first bridge #####"
	$(CC) $(CFLAGS) unit_test/test_1_find_first_bridge_e.c -o unit_test/$@

#	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_1_3_Verticies_All_Combos.txt" -O "unit_test/out_1.txt" 
#	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_2_3_Verticies_All_Combos.txt" -O "unit_test/out_2.txt"
#	./unit_test/$@ -E 6 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_3_3_Verticies_All_Combos.txt" -O "unit_test/out_3.txt"
#	./unit_test/$@ -E 6 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_4_3_Verticies_All_Combos.txt" -O "unit_test/out_4.txt"
#	./unit_test/$@ -E 6 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_1_binary-tree.txt" -O "unit_test/out_5.txt"
#	./unit_test/$@ -E 6 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_2_binary-tree.txt" -O "unit_test/out_6.txt"
#	./unit_test/$@ -E 4 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Linked_List_Verticie.txt" -O "unit_test/out_7.txt"
#	./unit_test/$@ -E 12 -V 12 -I "unit_test/adj_matrix/adjacency_matrix_12_Node_Graph.txt" -O "unit_test/out_8.txt"
	./unit_test/$@ -E 10 -V 9 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge.txt" -O "unit_test/out_9.txt"
	./unit_test/$@ -E 5 -V 5 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_1.txt" -O "unit_test/out_10.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_11.txt"
	./unit_test/$@ -E 3 -V 4 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_3.txt" -O "unit_test/out_12.txt"
	./unit_test/$@ -E 9 -V 8 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_4.txt" -O "unit_test/out_13.txt"

	rm unit_test/$@

	@echo "USE THE ERROR MATRIX FOR TESTING"