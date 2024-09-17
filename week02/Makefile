# Define the compiler and common flags
CC = clang
CFLAGS = -Wall -Wvla -Werror -g

########################################################################

.PHONY: all asan msan nosan clean

# Default target
all: asan

# Target for AddressSanitizer, LeakSanitizer, and UndefinedBehaviorSanitizer
asan: CFLAGS += -fsanitize=address,leak,undefined
asan: list hanoi palindrome two_sum

# Target for MemorySanitizer, UndefinedBehaviorSanitizer, and tracking origins
msan: CFLAGS += -fsanitize=memory,undefined -fsanitize-memory-track-origins
msan: list hanoi palindrome two_sum

# Target without sanitizers
nosan: list hanoi palindrome two_sum

########################################################################

# Build the list program
list: list.o
	$(CC) $(CFLAGS) -o list list.o

# Compile list.c into list.o
list.o: list.c
	$(CC) $(CFLAGS) -c list.c

# Build the hanoi program
hanoi: hanoi.o
	$(CC) $(CFLAGS) -o hanoi hanoi.o

# Compile hanoi.c into hanoi.o
hanoi.o: hanoi.c
	$(CC) $(CFLAGS) -c hanoi.c

# Build the palindrome program
palindrome: palindrome.o
	$(CC) $(CFLAGS) -o palindrome palindrome.o

# Compile palindrome.c into palindrome.o
palindrome.o: palindrome.c
	$(CC) $(CFLAGS) -c palindrome.c

# Build the two_sum program
two_sum: two_sum.o
	$(CC) $(CFLAGS) -o two_sum two_sum.o

# Compile two_sum.c into two_sum.o
two_sum.o: two_sum.c
	$(CC) $(CFLAGS) -c two_sum.c

########################################################################

# Clean up compiled files
clean:
	rm -f *.o list hanoi palindrome two_sum
