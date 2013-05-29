CC=g++
CFLAGS=-fopenmp -I ~/lib/boost_1_53_0/ -ftree-vectorize -std=gnu++0x -o3 -msse -msse2 -msse3 -msse4.1 -msse4.2 -ftree-vectorizer-verbose=5 -funsafe-loop-optimizations -fdump-tree-vect-details -fdump-tree-optimized
LDFLAGS= 
SOURCES= main.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE= main

all: $(SOURCES) $(EXECUTABLE)
		
$(EXECUTABLE): $(SOURCES) 
		$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o $@

