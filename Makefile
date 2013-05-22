CC=g++
CFLAGS=-fopenmp
LDFLAGS= 
SOURCES= main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE= main

all: $(SOURCES) $(EXECUTABLE)
		
$(EXECUTABLE): $(SOURCES) 
		$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o $@
