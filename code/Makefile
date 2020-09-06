CXX = g++

SDL_LIB = -lSDL2
SDL_INCLUDE = -I/usr/local/include

CXXFLAGS = -Wall -c -std=c++11 $(SDL_INCLUDE)
LDFLAGS = $(SDL_LIB)
PROJ_NAME = chip8

OBJS_DIR := objFiles
SRCS_DIR := src
INC_DIR := include
SRCS_FILES := $(SRCS_DIR)/main.cpp $(SRCS_DIR)/view.cpp $(SRCS_DIR)/chip8.cpp $(SRCS_DIR)/rectangle.cpp 

OBJS_FILES = $(patsubst $(SRCS_DIR)/%.cpp,$(OBJS_DIR)/%.o, $(SRCS_FILES))


.PHONY: all clean test

all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJS_FILES)
	$(CXX) $(OBJS_FILES) $(LDFLAGS) -o $@


$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p objFiles
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) $< -o $@

test:
	@echo "SRC FILES = '$(SRCS_FILES)'"
	@echo "OBJ FILES = '$(OBJS_FILES)'"

clean:
	rm -f $(OBJS_DIR)/*.o
	rm -f $(PROJ_NAME)
