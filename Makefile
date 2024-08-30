# Makefile for Memory Bandwidth Benchmark Program

# Compiler and flags
CC = gcc
CFLAGS = -O2 -fopenmp -Wall

# Target executable name
TARGET = main

# Source files
SRC = main.c

# Default target
all: $(TARGET)

# Compile the target
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up generated files
clean:
	rm -f $(TARGET)

.PHONY: all clean run
