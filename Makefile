#Makefile :: grafo

all: graph.o
	 gcc -o graph graph.o

graph.o: graph.c
	gcc -c graph.c

run:
	./Graph

clean:
	rm *.o
