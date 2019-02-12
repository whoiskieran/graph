CFLAGS = -O3 -g -Wall -fstrict-aliasing -std=c99
		
graph:graph.c 
	$(CC) $(CFLAGS) graph.c -o $@

test_parse:test_parse.c 
	$(CC) $(CFLAGS) test_parse.c -o $@
	./$@ -E 6 -V 6 -I input.txt -O output.txt
	
test_init:test_init.c 
	$(CC) $(CFLAGS) test_init.c -o $@
	

