CFLAGS = -O3 -g -Wall -fstrict-aliasing -std=c99 -I ../src

all: test_1_parse test_1_init test_1_add_v test_1_add_e test_1_get_degree test_1_set_adj test_1_v_distance test_1_edge_exists test_1_read_adjency
		
graph:graph.c 
	$(CC) $(CFLAGS) graph.c -o $@

test_1_parse:unit_test/test_1_parse.c 
	@echo "###### Test ONE parse #####"
	$(CC) $(CFLAGS) unit_test/test_1_parse.c -o unit_test/$@
	./unit_test/$@ -E 6 -V 6 -I input.txt -O output.txt
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

test_1_read_adjency:unit_test/test_1_read_adjency.c 
	@echo "###### Test ONE read_adjency #####"
	$(CC) $(CFLAGS) unit_test/test_1_read_adjency.c -o unit_test/$@
	
	./unit_test/$@ -E 3 -V 3 -I "unit_test/adj_matrix/adjacency_matrix_1_3_Verticies_All_Combos.txt" -O "unit_test/out.txt" 
	unit_test/test_1_read_adjency.sh "unit_test/adj_matrix/adjacency_matrix_1_3_Verticies_All_Combos.txt" "unit_test/out.txt"

	rm unit_test/$@
#	rm unit_test/out.txt
	        