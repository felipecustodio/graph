# /***********************************************/
# /* SCC0216 - Modelagem Computacional em Grafos */
# /* Felipe Scrochio Custódio - 9442688          */
# /***********************************************/

# compiler
CC = gcc

# output
BINARY = ./graph

# sources directory
SRC = ./graph.c ./main.c

# includes directory
INCLUDES = .

# compiler flags
FLAGS = -g -std=c99

all: compile

compile:
	$(CC) -o $(BINARY) -I $(INCLUDES) $(SRC) $(FLAGS)

run:
	$(BINARY)

debug:
	valgrind --leak-check=full --show-reachable=yes --track-origins=yes $(BINARY)

clean:
	rm *.o

zip:
	zip -r graph.zip ../graph
