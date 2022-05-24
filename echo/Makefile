all:output

output:echo.o
	gcc -o output echo.o
echo.o:echo.c
	gcc -c -g -Wall echo.c

clean:
	rm -f *.o output
