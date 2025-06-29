CXX = g++
CXXFLAGS = -std=c++11 `pkg-config --cflags opencv4`
LDFLAGS = `pkg-config --libs opencv4`

SRC_DIR := src/camera
BUILD_DIR := build
SRC := $(SRC_DIR)/camera.cpp
OBJ := $(BUILD_DIR)/camera.o
TARGET := $(SRC_DIR)/camera

all: $(TARGET)

$(BUILD_DIR):
	mkdir -p $@

$(OBJ): $(SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET) $(OBJ)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
