#
#
#
CC=
CXX=clang++

BIN_DIR=./bin
SRC_DIR=./src
BUILD_DIR=./build
TEST_DIR=./test

TARGET_EXEC=$(BIN_DIR)/main
TEST_EXEC=$(BIN_DIR)/test
OBJS= $(BUILD_DIR)/game.o \
	$(BUILD_DIR)/main.o
TEST_OBJS=$(BUILD_DIR)/game.o \
	$(BUILD_DIR)/test.o

INC_DIRS=-I../googletest/include
LDIR=-L../googletest/build/lib/
LIBS=-lgtest -lgtest_main

CPPFLAGS= -g -std=c++14

all: $(TARGET_EXEC) $(TEST_EXEC)

$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS) $(INC_DIRS) $(LDIR) $(LIBS)
$(TEST_EXEC): $(TEST_OBJS)
	$(CXX) $(TEST_OBJS) -o $@ $(LDFLAGS) $(INC_DIRS) $(LDIR) $(LIBS)
$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CXX) -c $(CPPFLAGS) $(CFLAGS) $< -o $@ -I$(SRC_DIR)
$(BUILD_DIR)/game.o: $(SRC_DIR)/game.cpp
	$(CXX) -c $(CPPFLAGS) $(CFLAGS) $< -o $@ -I$(SRC_DIR)
$(BUILD_DIR)/test.o: $(TEST_DIR)/TestsGame.cpp $(SRC_DIR)/game.h
	$(CXX) -c $(CPPFLAGS) $(CFLAGS) $< -o $@ -I$(SRC_DIR)

.PHONY: clean
clean:
	rm -r $(OBJS) $(TARGET_EXEC) $(TEST_EXEC)
