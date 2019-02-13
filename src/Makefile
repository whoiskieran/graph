CFLAGS = -O3 -g -Wall -fstrict-aliasing -std=c99 -I ../src

all: test_parse test_init
		
graph:graph.c 
	$(CC) $(CFLAGS) graph.c -o $@

test_parse:unit_test/test_parse.c 
	$(CC) $(CFLAGS) unit_test/test_parse.c -o unit_test/$@
	./unit_test/$@ -E 6 -V 6 -I input.txt -O output.txt
	
test_init:unit_test/test_init.c 
	$(CC) $(CFLAGS) unit_test/test_init.c -o unit_test/$@
	./unit_test/$@

