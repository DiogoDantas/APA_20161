CC = g++
OPTIONS = -std=c++11 -Wall -Werror -g3 

SRC_DIR = src
BUILD_DIR = obj
DIST_DIR = bin

insertion: insertion.o
	$(CC) $(OPTIONS) $(BUILD_DIR)/insertion.o -o $(DIST_DIR)/insertion

insertion.o: $(SRC_DIR)/insertion.cpp
	$(CC) $(OPTIONS) $(SRC_DIR)/insertion.cpp -c 
	mv insertion.o obj/

.PHONY = clean

clean: 
	rm -f $(BUILD_DIR)/*.o
	rm -f $(DIST_DIR)/*


	
