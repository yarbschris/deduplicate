# Compiler Flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Iinclude
LDFLAGS :=

# Directories
SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin

# Target Name
TARGET := $(BIN_DIR)/deduplicate

# All .cpp files in src/
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)

# Turn all source files into object files
OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Default target
all: $(TARGET)

# Build executable from .o files
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

# Compile .cpp to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Make Build Directory if it does not exist
(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Make Bin Directory if it does not exist
(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)


# Convenience target: debug build with -g and no optimization
debug: CXXFLAGS += -g -O0
debug: clean all

.PHONY: all clean debug
