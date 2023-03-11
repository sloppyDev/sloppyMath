NAME = sloppyMath
TARGET = $(NAME).a
LIB_INC = $(NAME).h

COMM_LIB_DIR = ../commonLibs
BUILD_DIR = ./build
SRC_DIRS = ./src
INC_DIRS = ./include
COMM_INC_DIR = $(COMM_LIB_DIR)/include

SRCS = $(shell find $(SRC_DIRS) -name *.cpp)
OBJS = $(SRCS:%=$(BUILD_DIR)/%.o)

INC_FLAGS = $(addprefix -I,$(INC_DIRS))
CPPFLAGS = $(INC_FLAGS) -MMD -MP -std=c++11
CXXFLAGS = -g -W -Wall -Wextra -pedantic -O0

copy: $(COMM_LIB_DIR)/$(TARGET)
	cp $(INC_DIRS)/$(LIB_INC) $(COMM_INC_DIR)/$(LIB_INC)

test: lib/src/main.cpp.o $(LIB_DIR)/$(TARGET)
	g++ $^ -o $@ 

$(COMM_LIB_DIR)/$(TARGET): $(OBJS)
	ar rcs $@ $^

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	g++ $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR)
