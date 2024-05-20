# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Iinclude -g

LIBS = -lglfw -lGL -lGLEW -lm

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Find all .c files in the src directory
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Target executable
TARGET = $(BIN_DIR)/main

main:
	@mkdir -p $(BIN_DIR)
	$(CC) $(SRC_FILES) -o $(TARGET) $(LIBS) $(CFLAGS)
	@cp *.txt $(BIN_DIR)

# Clean up build artifacts
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Print out information for debugging
.PHONY: info
info:
	@echo "SRC_FILES: $(SRC_FILES)"
	@echo "OBJ_FILES: $(OBJ_FILES)"
	@echo "TARGET: $(TARGET)"

