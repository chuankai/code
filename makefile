CXX = g++
INCLUDE_PATH = lib
CXXFLAGS = -std=c++23 -Wall -Wextra -g -fsanitize=address -fno-omit-frame-pointer -I$(INCLUDE_PATH)
MAKEFLAGS += --no-builtin-rules
BIN_PATH = bin

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $(BIN_PATH)/$@

