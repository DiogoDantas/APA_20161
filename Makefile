CC = g++
OPTIONS = -std=c++11 -Wall -Werror -O2 -g3 

SRC_DIR = src
BUILD_DIR = obj
DIST_DIR = bin

insertion: directories insertion.o
	$(CC) $(OPTIONS) $(BUILD_DIR)/insertion.o -o $(DIST_DIR)/insertion

insertion.o: $(SRC_DIR)/insertion.cpp
	$(CC) $(OPTIONS) $(SRC_DIR)/insertion.cpp -c 
	mv insertion.o obj/

selection: directories selection.o
	$(CC) $(OPTIONS) $(BUILD_DIR)/selection.o -o $(DIST_DIR)/selection

selection.o: $(SRC_DIR)/selection.cpp
	$(CC) $(OPTIONS) $(SRC_DIR)/selection.cpp -c
	mv selection.o obj/

quick: directories quicksort.o
	$(CC) $(OPTIONS) $(BUILD_DIR)/quicksort.o -o $(DIST_DIR)/quick

quicksort.o: $(SRC_DIR)/quicksort.cpp
	$(CC) $(OPTIONS) $(SRC_DIR)/quicksort.cpp -c
	mv quicksort.o obj/

merge: directories mergesort.o
	$(CC) $(OPTIONS) $(BUILD_DIR)/mergesort.o -o $(DIST_DIR)/merge

mergesort.o: $(SRC_DIR)/mergesort.cpp
	$(CC) $(OPTIONS) $(SRC_DIR)/mergesort.cpp -c
	mv mergesort.o obj/

heap: directories heapsort.o
	$(CC) $(OPTIONS) $(BUILD_DIR)/heapsort.o -o $(DIST_DIR)/heap

heapsort.o: $(SRC_DIR)/heapsort.cpp
	$(CC) $(OPTIONS) $(SRC_DIR)/heapsort.cpp -c
	mv heapsort.o obj/

directories: 
	mkdir -p $(BUILD_DIR)
	mkdir -p $(DIST_DIR)

.PHONY = clean

clean: 
	rm -f $(BUILD_DIR)/*.o
	rm -f $(DIST_DIR)/*
	rm -f -d $(BUILD_DIR)
	rm -f -d $(DIST_DIR)


	
