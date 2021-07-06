CFLAGS = -O3 -g -Wall -fstrict-aliasing -std=c99
# TESTFILE = pbtest
TESTFILE = pb16-81
TESTFILE = pb_400_01.txt

test:main
#	rm *.csv
#	./main -E 1 -Z 2 -t 2 -f $(TESTFILE)
	./main -E 0 -Z 1 -f $(TESTFILE) 2> out1.txt
	./main -E 0 -Z 2 -f $(TESTFILE) 2> out2.txt
	./main -E 0 -Z 3 -f $(TESTFILE) 2> out3.txt
	./main -E 0 -Z 4 -f $(TESTFILE) 2> out4.txt
	./main -E 0 -Z 5 -f $(TESTFILE) 2> out5.txt
		
main:main.c 
	$(CC) $(CFLAGS) main.c -o $@

debug:main.c 
	$(CC) $(CFLAGS) -D DEBUG=1 main.c -o main
	./main -Z 1 -f $(TESTFILE)
	./main -Z 1 -f $(TESTFILE)
	
debugExp:main.c 
	$(CC) $(CFLAGS) -D DEBUG=1 main.c -o main
	./main -E 1 -Z 1 -f $(TESTFILE)
	./main -E 1 -Z 1 -t 2 -f $(TESTFILE)
