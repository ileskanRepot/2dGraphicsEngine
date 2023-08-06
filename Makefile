FLAGS = -g -Wall
CC = gcc
INPUT = main.c logic.c render.c
OUTPUT = main

all: $(INPUT)
	$(CC) $(FLAGS) $(INPUT) -o $(OUTPUT)

run: $(INPUT) all
	./main

valgrind: $(INPUT) all
	valgrind -s --leak-check=full ./$(OUTPUT)
