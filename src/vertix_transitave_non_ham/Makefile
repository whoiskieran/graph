CFLAGS = -O3 -g -Wall -fstrict-aliasing -std=c99 -I ../../src

all: gen_vtuh		
gen_vtuh:gen_vtuh.c
	$(CC) $(CFLAGS) gen_vtuh.c -o $@
#	./$@ -S 9 > out_9.txt
#	./$@ -S 27 > out_27.txt
#	./$@ -S 29 > out_29.txt
	./$@ -S 83 > out_83.txt
	rm $@

