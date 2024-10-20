CC = g++
FLAGS = -static
SRC = src
OBJ = obj

all: $(OBJ)/main.o $(OBJ)/afn.o
	$(CC) $(FLAGS) $(OBJ)/main.o $(OBJ)/afn.o -o main 
$(OBJ)/main.o: $(OBJ) $(SRC)/main.cpp
	$(CC) $(FLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o -static

$(OBJ)/afn.o: $(OBJ) $(SRC)/afn.hpp $(SRC)/afn.cpp
	$(CC) $(FLAGS) -c $(SRC)/afn.cpp -o $(OBJ)/afn.o -static

$(OBJ):
	mkdir $(OBJ)

clear:
	rm -fr $(OBJ) main

run:
	./main < in