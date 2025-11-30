# Compiler and flags
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Iinclude
LDFLAGS  :=

# Directories
SRC_DIR   := src
BUILD_DIR := build
BIN_DIR   := bin

# Target name
TARGET := $(BIN_DIR)/deduplicate

# All .cpp files in src/
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)

# Turn src/foo.cpp into build/foo.o
OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Default target
all: $(TARGET)

# Link step: build final executable
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

# Compile step: build/whatever.o from src/whatever.cpp
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Make sure build/ and bin/ exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Cleanup
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Convenience target: debug build with -g and no optimization
debug: CXXFLAGS += -g -O0
debug: clean all

.PHONY: all clean debug

