TARGET = HPSCProject1
CXX = g++
CFLAGS = -std=c++14

SRC = src/
LIB = lib/
BIN = bin/
ROOT = $(shell pwd)

FILES = proj1_a.cpp
LIBFILES = Matrix.cpp Vector.cpp

# make the binaries

$(TARGET):
	$(CXX) $(CFLAGS) -o $(BIN)$(TARGET) -I $(LIB) $(addprefix $(LIB), $(LIBFILES)) $(addprefix $(SRC), $(FILES))


# make the data files

data: $(TARGET)
	cd $(BIN); ./$(TARGET)
