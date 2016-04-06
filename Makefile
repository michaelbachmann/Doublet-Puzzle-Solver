BIN_DIR = bin
CC = g++
CPPFLAGS = -std=c++11 -Wall -g

all: $(BIN_DIR)/doublet

$(BIN_DIR)/hashtable.o: lib/hash_table.h src/hash_table.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c src/hash_table.cpp -o $(BIN_DIR)/hashtable.o

$(BIN_DIR)/minheap.o: lib/min_heap.h src/min_heap.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c src/min_heap.cpp -o $(BIN_DIR)/minheap.o

$(BIN_DIR)/doubletsolver.o: lib/doubletsolver.h src/doubletsolver.cpp $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) -c src/doubletsolver.cpp -o $(BIN_DIR)/doubletsolver.o

$(BIN_DIR)/hashtabletester: $(BIN_DIR)/hashtable.o $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) $(BIN_DIR)/hashtable.o src/hash_table_tester.cpp -o bin/hashtabletester

$(BIN_DIR)/minheaptester: $(BIN_DIR)/hashtable.o $(BIN_DIR)/minheap.o $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) $(BIN_DIR)/hashtable.o $(BIN_DIR)/minheap.o src/min_heap_tester.cpp -o bin/minheaptester

$(BIN_DIR)/doublet: $(BIN_DIR)/hashtable.o $(BIN_DIR)/minheap.o $(BIN_DIR)/doubletsolver.o $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) $(BIN_DIR)/hashtable.o $(BIN_DIR)/minheap.o $(BIN_DIR)/doubletsolver.o src/doublet.cpp -o bin/doublet

.PHONY: clean
clean:
	rm -rf $(BIN_DIR)

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp