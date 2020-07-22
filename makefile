# Make struct_packed project

.PHONY = clean all
CC := gcc

all: struct_packed

struct_packed : struct_packed.o
struct_packed.o : struct_packed.c

clean :
	rm -f *.o struct_packed

