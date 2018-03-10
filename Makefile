all: graph.o
	 gcc -o graph graph.o

graph.o: graph.c
	gcc -c graph.c

run:
	./Graph

clear:
	clear

clean:
	rm *.o

zip:
	zip -r graph.zip ../graph
