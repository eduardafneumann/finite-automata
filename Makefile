CC = g++
SRC = src
OBJ = obj

all: $(OBJ)/main.o $(OBJ)/afn.o
	$(CC) $(OBJ)/main.o $(OBJ)/afn.o -o main

$(OBJ)/main.o: $(OBJ) $(SRC)/main.cpp
	$(CC) -c $(SRC)/main.cpp -o $(OBJ)/main.o

$(OBJ)/afn.o: $(OBJ) $(SRC)/afn.hpp $(SRC)/afn.cpp
	$(CC) -c $(SRC)/afn.cpp -o $(OBJ)/afn.o

$(OBJ):
	mkdir $(OBJ)

clear:
	rm -fr $(OBJ) main

run:
	./main < in