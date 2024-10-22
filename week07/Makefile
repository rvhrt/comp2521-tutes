CC = clang
CFLAGS = -Wall -Werror -g -fsanitize=address,leak,undefined

.PHONY: all
all: runGraph

runGraphAdjList: runGraph.c GraphAdjList.c
	$(CC) $(CFLAGS) -o runGraphAdjList runGraph.c GraphAdjList.c

runGraphAdjMatrix: runGraph.c GraphAdjMatrix.c
	$(CC) $(CFLAGS) -o runGraphAdjMatrix runGraph.c GraphAdjMatrix.c

runGraph: runGraph.c Graph.c
	$(CC) $(CFLAGS) -o runGraph runGraph.c Graph.c

.PHONY: clean
clean:
	rm -f runGraphAdjList runGraphAdjMatrix runGraph