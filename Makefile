CC = g++
OPTIONS = -std=c++11 -Wall -Werror -g3 

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

directories: 
	mkdir -p $(BUILD_DIR)
	mkdir -p $(DIST_DIR)

.PHONY = clean

clean: 
	rm -f $(BUILD_DIR)/*.o
	rm -f $(DIST_DIR)/*


	
