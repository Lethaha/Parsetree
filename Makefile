CC=g++
CFLAGS=-c -std=c++11
LIBS=-lboost_program_options
SOURCES=Prac2.cpp parsetree.cpp tree_iterator.cpp tree_node.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=mage.exe

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LIBS) -o $@

run: 
	./$(EXECUTABLE)
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o $(EXECUTABLE)
