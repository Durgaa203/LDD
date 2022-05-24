all:output

output:cat.o
	gcc -o output cat.o

cat.o:cat.c
	gcc -c -g -Wall cat.c

clean:
	rm -f *.o output

