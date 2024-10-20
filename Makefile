CC = g++
SRC = src
OBJ = obj

all: $(OBJ)/main.o $(OBJ)/afn.o
	$(CC)  $(OBJ)/main.o $(OBJ)/afn.o -o main -static

$(OBJ)/main.o: $(OBJ) $(SRC)/main.cpp
	$(CC) -c $(SRC)/main.cpp -o $(OBJ)/main.o -static

$(OBJ)/afn.o: $(OBJ) $(SRC)/afn.hpp $(SRC)/afn.cpp
	$(CC) -c $(SRC)/afn.cpp -o $(OBJ)/afn.o -static

$(OBJ):
	mkdir $(OBJ)

clear:
	rm -fr $(OBJ) main

run:
	./main < in