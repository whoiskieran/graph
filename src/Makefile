CFLAGS = -O3 -g -Wall -fstrict-aliasing -std=c99 -I ../src

all: test_1_parse test_1_init test_1_add_v test_2_add_v test_3_add_v test_4_add_v test_1_add_e test_2_add_e test_1_get_degree test_1_set_adj test_1_v_distance test_1_edge_exists test_1_write_adjency test_1_read_adjency test_2_read_adjency test_2_get_degree test_1_find_edges test_2_find_edges test_3_find_edges test_4_find_edges test_5_find_edges test_6_find_edges test_1_write_incidence test_1_read_incidence test_1_get_vertix test_1_find_first_bridge_e test_1_set_fwd_weight test_2_set_fwd_weight test_1_set_bk_weight test_2_set_bk_weight test_1_get_bk_weight test_2_get_bk_weight test_1_get_fwd_weight test_2_get_fwd_weight test_1_get_e_id test_2_get_e_id test_1_get_v_id test_2_get_v_id  test_1_combine_g test_1_get_no_regions test_1_get_adj_list test_2_get_adj_list test_3_get_adj_list test_1_e_has_uniq_id test_2_e_has_uniq_id test_1_v_has_uniq_id test_2_v_has_uniq_id test_1_get_v_pos_by_id
		
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

test_2_add_v:unit_test/test_2_add_v.c 
	@echo "###### Test TWO add vertix make sure vertix is unique #####"
	$(CC) $(CFLAGS) unit_test/test_2_add_v.c -o unit_test/$@
	./unit_test/$@
	rm unit_test/$@

test_3_add_v:unit_test/test_3_add_v.c 
	@echo "###### Test THREE add new vertix test realloc of vertix #####"
	$(CC) $(CFLAGS) unit_test/test_2_add_v.c -o unit_test/$@
	./unit_test/$@
	rm unit_test/$@

test_4_add_v:unit_test/test_4_add_v.c 
	@echo "###### Test FOUR add new vertix with insertion point too big #####"
	$(CC) $(CFLAGS) unit_test/test_2_add_v.c -o unit_test/$@
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
	
	./unit_test/$@ -E 12 -V 12 -I "unit_test/adj_matrix/adjacency_matrix_12_Node_Graph_Both_Directions.txt" -O "unit_test/out_8a.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_12_Node_Graph_Both_Directions.txt" "unit_test/out_8a.txt"
	
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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" "unit_test/out_14.txt"
	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" "unit_test/out_16.txt"

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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" "unit_test/out_14.txt"
	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" "unit_test/out_16.txt"
	./unit_test/$@ -E 8 -V 6 -I "unit_test/adj_matrix/multi_graph.txt" -O "unit_test/out_17.txt"
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/multi_graph.txt" "unit_test/out_17.txt"

	
	rm unit_test/$@
	rm unit_test/out*.txt


test_2_read_adjency:unit_test/test_2_read_adjency.c 
	@echo "###### Test TWO read_adjency Invalid Adjacency Goes here. #####"
	$(CC) $(CFLAGS) unit_test/test_2_read_adjency.c -o unit_test/$@

	./unit_test/$@ -E 0 -V 0 -I "unit_test/adj_matrix/adjacency_matrix_Empty.txt" -O "unit_test/out_1.txt"
	
	rm unit_test/$@

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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"
	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"
	
	# rm unit_test/out*.txt
	rm unit_test/$@

test_1_set_fwd_weight:unit_test/test_1_set_fwd_weight.c 
	@echo "###### Test 1 set_fwd_weight #####"
	$(CC) $(CFLAGS) unit_test/test_1_set_fwd_weight.c -o unit_test/$@

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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"
	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"

	rm unit_test/$@

test_2_set_fwd_weight:unit_test/test_2_set_fwd_weight.c 
	@echo "###### Test 2 set_fwd_weight #####"
	$(CC) $(CFLAGS) unit_test/test_2_set_fwd_weight.c -o unit_test/$@

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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"
	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"

	rm unit_test/$@


test_1_set_bk_weight:unit_test/test_1_set_bk_weight.c 
	@echo "###### Test 1 set_bk_weight #####"
	$(CC) $(CFLAGS) unit_test/test_1_set_bk_weight.c -o unit_test/$@

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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"
	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"

	rm unit_test/$@

test_2_set_bk_weight:unit_test/test_2_set_bk_weight.c 
	@echo "###### Test 2 set_bk_weight #####"
	$(CC) $(CFLAGS) unit_test/test_2_set_bk_weight.c -o unit_test/$@

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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"
	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"

	rm unit_test/$@
	

test_1_get_bk_weight:unit_test/test_1_get_bk_weight.c 
	@echo "###### Test 1 get_bk_weight #####"
	$(CC) $(CFLAGS) unit_test/test_1_get_bk_weight.c -o unit_test/$@

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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"

	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"

	rm unit_test/$@

test_2_get_bk_weight:unit_test/test_2_get_bk_weight.c 
	@echo "###### Test 2 get_bk_weight #####"
	$(CC) $(CFLAGS) unit_test/test_2_get_bk_weight.c -o unit_test/$@

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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"

	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"

	rm unit_test/$@


test_1_get_fwd_weight:unit_test/test_1_get_fwd_weight.c 
	@echo "###### Test 1 get_fwd_weight #####"
	$(CC) $(CFLAGS) unit_test/test_1_get_fwd_weight.c -o unit_test/$@

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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"
	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"

	rm unit_test/$@

test_2_get_fwd_weight:unit_test/test_2_get_fwd_weight.c 
	@echo "###### Test 1 get_fwd_weight #####"
	$(CC) $(CFLAGS) unit_test/test_2_get_fwd_weight.c -o unit_test/$@

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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"
	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"

	rm unit_test/$@


test_1_get_e_id:unit_test/test_1_get_e_id.c 
	@echo "###### Test 1 test both set and get edge id #####"
	$(CC) $(CFLAGS) unit_test/test_1_get_e_id.c -o unit_test/$@

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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"

	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"

	rm unit_test/$@

test_2_get_e_id:unit_test/test_2_get_e_id.c 
	@echo "###### Test 1 test both set and get edge id With invalid edge number #####"
	$(CC) $(CFLAGS) unit_test/test_2_get_e_id.c -o unit_test/$@

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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"

	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"

	rm unit_test/$@

test_1_get_v_id:unit_test/test_1_get_v_id.c 
	@echo "###### Test 1 test both set and get vertix id #####"
	$(CC) $(CFLAGS) unit_test/test_1_get_v_id.c -o unit_test/$@

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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"

	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"

	rm unit_test/$@

test_2_get_v_id:unit_test/test_2_get_v_id.c 
	@echo "###### Test 1 test both set and get vertix id With invalid vertix number #####"
	$(CC) $(CFLAGS) unit_test/test_2_get_v_id.c -o unit_test/$@

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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"

	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"

	rm unit_test/$@



test_1_find_edges:unit_test/test_1_find_edges.c 
	@echo "###### Test ONE find edges all graphs have edges #####"
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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"
	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"

	# rm unit_test/out*.txt	
	rm unit_test/$@

test_2_find_edges:unit_test/test_2_find_edges.c 
	@echo "###### Test TWO find edges pass down invalid vertix #####"
	$(CC) $(CFLAGS) unit_test/test_2_find_edges.c -o unit_test/$@

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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"
	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"

#	rm unit_test/out*.txt	
	rm unit_test/$@

test_3_find_edges:unit_test/test_3_find_edges.c 
	@echo "###### Test THREE find edges pass down invalid edge #####"
	$(CC) $(CFLAGS) unit_test/test_3_find_edges.c -o unit_test/$@

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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"
	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"

#	rm unit_test/out*.txt	
	rm unit_test/$@

test_4_find_edges:unit_test/test_4_find_edges.c 
	@echo "###### Test FOUR find vertix at start of edge all graphs have edges #####"
	$(CC) $(CFLAGS) unit_test/test_4_find_edges.c -o unit_test/$@

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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"
	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"

#	rm unit_test/out*.txt	
	rm unit_test/$@

test_5_find_edges:unit_test/test_5_find_edges.c 
	@echo "###### Test FIVE find vertix at end of edge all graphs have edges #####"
	$(CC) $(CFLAGS) unit_test/test_5_find_edges.c -o unit_test/$@
# Some of thses adjacency matrix do not have endges to vertix 0.
# vertix 0 is used in the test so they are excluded here.
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_1_3_Verticies_All_Combos.txt" -O "unit_test/out_1.txt" 
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_2_3_Verticies_All_Combos.txt" -O "unit_test/out_2.txt"
	./unit_test/$@ -E 6 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_3_3_Verticies_All_Combos.txt" -O "unit_test/out_3.txt"
	./unit_test/$@ -E 6 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_4_3_Verticies_All_Combos.txt" -O "unit_test/out_4.txt"
# 	./unit_test/$@ -E 6 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_1_binary-tree.txt" -O "unit_test/out_5.txt"
	./unit_test/$@ -E 6 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_2_binary-tree.txt" -O "unit_test/out_6.txt"
#	./unit_test/$@ -E 4 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Linked_List_Verticie.txt" -O "unit_test/out_7.txt"
	./unit_test/$@ -E 12 -V 12 -I "unit_test/adj_matrix/adjacency_matrix_12_Node_Graph.txt" -O "unit_test/out_8.txt"
	./unit_test/$@ -E 10 -V 9 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge.txt" -O "unit_test/out_9.txt"
	./unit_test/$@ -E 5 -V 5 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_1.txt" -O "unit_test/out_10.txt"
#	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_11.txt"
#	./unit_test/$@ -E 3 -V 4 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_3.txt" -O "unit_test/out_12.txt"
	./unit_test/$@ -E 9 -V 8 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_4.txt" -O "unit_test/out_13.txt"
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"
	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
#	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"

#	rm unit_test/out*.txt	
	rm unit_test/$@

test_6_find_edges:unit_test/test_6_find_edges.c 
	@echo "###### Test SIX find edges start V2 E2 #####"
	$(CC) $(CFLAGS) unit_test/test_6_find_edges.c -o unit_test/$@

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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"
	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"

#	rm unit_test/out*.txt	
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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/incidence_matrix/incidence_matrix_Articulation_Point.txt"
	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/incidence_matrix/incidence_matrix_Find_Bridge_Edge_2_Error.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/incidence_matrix/incidence_matrix_Find_Bridge_Edge_2.txt"

#	rm unit_test/out*.txt
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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/incidence_matrix/incidence_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"
	unit_test/test_1_read_adjency.sh "unit_test/incidence_matrix/incidence_matrix_Articulation_Point.txt" "unit_test/out_14.txt"
	./unit_test/$@ -E 7 -V 7 -I "unit_test/incidence_matrix/incidence_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	unit_test/test_1_read_adjency.sh "unit_test/incidence_matrix/incidence_matrix_Find_Bridge_Edge_2_Error.txt" "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/incidence_matrix/incidence_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"
	unit_test/test_1_read_adjency.sh "unit_test/incidence_matrix/incidence_matrix_Find_Bridge_Edge_2.txt" "unit_test/out_16.txt"

	rm unit_test/out*.txt
	rm unit_test/$@

test_1_get_vertix:unit_test/test_1_get_vertix.c 
	@echo "###### Test ONE get vertix #####"
	$(CC) $(CFLAGS) unit_test/test_1_get_vertix.c -o unit_test/$@

	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_1_3_Verticies_All_Combos.txt" -O "unit_test/test_1_get_vertix_data/e_v_1_3_Verticies_All_Combos.txt" 
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_2_3_Verticies_All_Combos.txt" -O "unit_test/test_1_get_vertix_data/e_v_2_3_Verticies_All_Combos.txt"
	./unit_test/$@ -E 6 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_3_3_Verticies_All_Combos.txt" -O "unit_test/test_1_get_vertix_data/e_v_3_3_Verticies_All_Combos.txt"
	./unit_test/$@ -E 6 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_4_3_Verticies_All_Combos.txt" -O "unit_test/test_1_get_vertix_data/e_v_4_3_Verticies_All_Combos.txt"
	./unit_test/$@ -E 6 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_1_binary-tree.txt" -O "unit_test/test_1_get_vertix_data/e_v_1_binary-tree.txt"
	./unit_test/$@ -E 6 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_2_binary-tree.txt" -O "unit_test/test_1_get_vertix_data/e_v_2_binary-tree.txt"
	./unit_test/$@ -E 4 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Linked_List_Verticie.txt" -O "unit_test/test_1_get_vertix_data/e_v_Linked_List_Verticie.txt"
	./unit_test/$@ -E 12 -V 12 -I "unit_test/adj_matrix/adjacency_matrix_12_Node_Graph.txt" -O "unit_test/test_1_get_vertix_data/e_v_12_Node_Graph.txt"
	./unit_test/$@ -E 10 -V 9 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge.txt" -O "unit_test/test_1_get_vertix_data/e_v_Find_Bridge_Edge.txt"
	./unit_test/$@ -E 5 -V 5 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_1.txt" -O "unit_test/test_1_get_vertix_data/e_v_Find_Bridge_Edge_1.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/test_1_get_vertix_data/e_v_Find_Bridge_Edge_2.txt"
	./unit_test/$@ -E 3 -V 4 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_3.txt" -O "unit_test/test_1_get_vertix_data/e_v_Find_Bridge_Edge_3.txt"
	./unit_test/$@ -E 9 -V 8 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_4.txt" -O "unit_test/test_1_get_vertix_data/e_v_Find_Bridge_Edge_4.txt"
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/test_1_get_vertix_data/e_v_Articulation_Point.txt"

	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/test_1_get_vertix_data/e_v__Find_Bridge_Edge_2_Error.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/test_1_get_vertix_data/e_v__Find_Bridge_Edge_2.txt"

	rm unit_test/$@
#	rm unit_test/out*.txt


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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"

	rm unit_test/out*.txt
	rm unit_test/$@

test_1_combine_g:unit_test/test_1_combine_g.c 
	@echo "###### Test ONE Combine G #####"
	$(CC) $(CFLAGS) unit_test/test_1_combine_g.c -o unit_test/$@
	./unit_test/$@
	rm unit_test/$@

test_1_get_no_regions:unit_test/test_1_get_no_regions.c
	@echo "###### Test ONE get_no_regions #####"
	$(CC) $(CFLAGS) unit_test/test_1_get_no_regions.c -o unit_test/$@
	./unit_test/$@
	rm unit_test/$@

test_1_get_adj_list:unit_test/test_1_get_adj_list.c 
	@echo "###### Test ONE get adj list #####"
	$(CC) $(CFLAGS) unit_test/test_1_get_adj_list.c -o unit_test/$@
	./unit_test/$@
	rm unit_test/$@

test_2_get_adj_list:unit_test/test_2_get_adj_list.c 
	@echo "###### Test TWO get adj list #####"
	$(CC) $(CFLAGS) unit_test/test_2_get_adj_list.c -o unit_test/$@
	./unit_test/$@
	rm unit_test/$@

test_3_get_adj_list:unit_test/test_3_get_adj_list.c 
	@echo "###### Test THREE test_3_get_adj_list #####"
	$(CC) $(CFLAGS) unit_test/test_3_get_adj_list.c -o unit_test/$@

	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_1_3_Verticies_All_Combos.txt" -O "unit_test/test_3_get_adj_list_data/v_1_3_Verticies_All_Combos.txt" 
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_2_3_Verticies_All_Combos.txt" -O "unit_test/test_3_get_adj_list_data/v_2_3_Verticies_All_Combos.txt"
	./unit_test/$@ -E 6 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_3_3_Verticies_All_Combos.txt" -O "unit_test/test_3_get_adj_list_data/v_3_3_Verticies_All_Combos.txt"
	./unit_test/$@ -E 6 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_4_3_Verticies_All_Combos.txt" -O "unit_test/test_3_get_adj_list_data/v_4_3_Verticies_All_Combos.txt"
	./unit_test/$@ -E 6 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_1_binary-tree.txt" -O "unit_test/test_3_get_adj_list_data/v_1_binary-tree.txt"
	./unit_test/$@ -E 6 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_2_binary-tree.txt" -O "unit_test/test_3_get_adj_list_data/v_2_binary-tree.txt"
	./unit_test/$@ -E 4 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Linked_List_Verticie.txt" -O "unit_test/test_3_get_adj_list_data/v_Linked_List_Verticie.txt"
	./unit_test/$@ -E 12 -V 12 -I "unit_test/adj_matrix/adjacency_matrix_12_Node_Graph.txt" -O "unit_test/test_3_get_adj_list_data/v_12_Node_Graph.txt"
	./unit_test/$@ -E 10 -V 9 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge.txt" -O "unit_test/test_3_get_adj_list_data/v_Find_Bridge_Edge.txt"
	./unit_test/$@ -E 5 -V 5 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_1.txt" -O "unit_test/test_3_get_adj_list_data/v_Find_Bridge_Edge_1.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/test_3_get_adj_list_data/v_Find_Bridge_Edge_2.txt"
	./unit_test/$@ -E 3 -V 4 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_3.txt" -O "unit_test/test_3_get_adj_list_data/v_Find_Bridge_Edge_3.txt"
	./unit_test/$@ -E 9 -V 8 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_4.txt" -O "unit_test/test_3_get_adj_list_data/v_Find_Bridge_Edge_4.txt"
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/test_3_get_adj_list_data/v_Articulation_Point.txt"
	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/test_3_get_adj_list_data/v__Find_Bridge_Edge_2_Error.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/test_3_get_adj_list_data/v__Find_Bridge_Edge_2.txt"

	./unit_test/$@ -E 0 -V 4 -I "unit_test/adj_matrix/adjacency_matrix_No_Edges.txt" -O "unit_test/test_3_get_adj_list_data/adjacency_matrix_No_Edges.txt"
	./unit_test/$@ -E 12 -V 11 -I "unit_test/adj_matrix/Spoke_Node_Connects_Sections.txt" -O "unit_test/test_3_get_adj_list_data/Spoke_Node_Connects_Sections.txt"
	./unit_test/$@ -E 17 -V 15 -I "unit_test/adj_matrix/Three_Sections_Connected_By_Separate_Nodes.txt" -O "unit_test/test_3_get_adj_list_data/Three_Sections_Connected_By_Separate_Nodes.txt"
	./unit_test/$@ -E 11 -V 10  -I "unit_test/adj_matrix/Two_Section_Connected_By_One_Edge.txt" -O "unit_test/test_3_get_adj_list_data/Two_Section_Connected_By_One_Edge.txt"
	./unit_test/$@ -E 12 -V 11 -I "unit_test/adj_matrix/Two_Section_Connected_By_One_Node.txt" -O "unit_test/test_3_get_adj_list_data/Two_Section_Connected_By_One_Node.txt"


	rm unit_test/$@


test_1_e_has_uniq_id:unit_test/test_1_e_has_uniq_id.c 
	@echo "###### Test ONE add edge has unique id #####"
	$(CC) $(CFLAGS) unit_test/test_1_e_has_uniq_id.c -o unit_test/$@
	./unit_test/$@
	rm unit_test/$@

test_2_e_has_uniq_id:unit_test/test_2_e_has_uniq_id.c 
	@echo "###### Test TWO add edge has unique id  ALL id's are unique so this function should find this #####"
	$(CC) $(CFLAGS) unit_test/test_2_e_has_uniq_id.c -o unit_test/$@
	./unit_test/$@
	rm unit_test/$@


test_1_v_has_uniq_id:unit_test/test_1_v_has_uniq_id.c 
	@echo "###### Test ONE add vertix has unique id #####"
	$(CC) $(CFLAGS) unit_test/test_1_v_has_uniq_id.c -o unit_test/$@
	./unit_test/$@
	rm unit_test/$@

test_2_v_has_uniq_id:unit_test/test_2_v_has_uniq_id.c 
	@echo "###### Test TWO add verticies has unique id  ALL id's are unique so this function should find this #####"
	$(CC) $(CFLAGS) unit_test/test_2_v_has_uniq_id.c -o unit_test/$@
	./unit_test/$@
	rm unit_test/$@

test_1_get_v_pos_by_id:unit_test/test_1_get_v_pos_by_id.c 
	@echo "###### Test 1 invalid input for get_v_pos_by_id #####"
	$(CC) $(CFLAGS) unit_test/test_1_get_v_pos_by_id.c -o unit_test/$@

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
	./unit_test/$@ -E 7 -V 6 -I "unit_test/adj_matrix/adjacency_matrix_Articulation_Point.txt" -O "unit_test/out_14.txt"

	./unit_test/$@ -E 7 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2_Error.txt" -O "unit_test/out_15.txt"
	./unit_test/$@ -E 8 -V 7 -I "unit_test/adj_matrix/adjacency_matrix_Find_Bridge_Edge_2.txt" -O "unit_test/out_16.txt"

	rm unit_test/$@


