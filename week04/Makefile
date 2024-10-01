# COMP2521 - Week 7 Lab

# !!! DO NOT MODIFY THIS FILE !!!

CC = clang
CFLAGS = -Wall -Wvla -Werror -gdwarf-4

########################################################################

.PHONY: asan msan nosan

asan: CFLAGS += -fsanitize=address,leak,undefined
asan: all

msan: CFLAGS += -fsanitize=memory,undefined -fsanitize-memory-track-origins
msan: all

nosan: all

########################################################################

.PHONY: all
all: queue runBst

queue: Queue.c Stack.c driver.c
	$(CC) $(CFLAGS) Stack.c Queue.c driver.c -o driver

runBst: runBst.o bst.o
	$(CC) $(CFLAGS) -o runBst runBst.o bst.o 

runBst.o: runBst.c bst.h

bst.o: bst.c bst.h 

.PHONY: clean
clean:
	rm -f driver runBst *.o