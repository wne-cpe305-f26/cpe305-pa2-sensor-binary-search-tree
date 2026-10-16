CXX ?= g++
CXXFLAGS ?= -std=c++20 -Wall -Wextra -Wpedantic -Werror
CPPFLAGS ?= -Iinclude

BIN_DIR := bin
BUILD_DIR := build
APP := $(BIN_DIR)/sensor_tree
TEST_APP := $(BIN_DIR)/sensor_tree_tests

APP_OBJECTS := $(BUILD_DIR)/sensor_tree.o $(BUILD_DIR)/main.o
TEST_OBJECTS := $(BUILD_DIR)/sensor_tree.o $(BUILD_DIR)/test_main.o \
	$(BUILD_DIR)/supplied_tests.o $(BUILD_DIR)/student_tests.o

.PHONY: all test sanitize clean

all: $(APP)

$(APP): $(APP_OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(APP_OBJECTS) -o $@

$(TEST_APP): $(TEST_OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(TEST_OBJECTS) -o $@

$(BUILD_DIR)/%.o: src/%.cpp include/sensor_tree.hpp | $(BUILD_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: tests/%.cpp include/sensor_tree.hpp | $(BUILD_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR) $(BUILD_DIR):
	mkdir -p $@

test: $(TEST_APP)
	./$(TEST_APP)

sanitize: CXXFLAGS += -fsanitize=address,undefined -fno-omit-frame-pointer
sanitize: clean $(TEST_APP)
	./$(TEST_APP)

clean:
	rm -rf $(BIN_DIR) $(BUILD_DIR)
