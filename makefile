all: dirinfo.o 
	gcc dirinfo.o

a.out: dirinfo.o
	gcc dirinfo.o

dirinfo.o: dirinfo.c 
	gcc -c dirinfo.c

run: a.out
	./a.out

clean: dirinfo.o
	rm *.o
