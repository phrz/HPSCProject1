TARGETA = HPSCProject1_a
TARGETB = HPSCProject1_b

CXX = g++
CFLAGS = -std=c++14

SRC = src/
LIB = lib/
BIN = bin/
ROOT = $(shell pwd)

AFILES = proj1_a.cpp
BFILES = proj1_b.cpp
LIBFILES = Matrix.cpp Vector.cpp

# make the binaries

$(TARGETA):
	$(CXX) $(CFLAGS) -o $(BIN)$(TARGETA) -I $(LIB) $(addprefix $(LIB), $(LIBFILES)) $(addprefix $(SRC), $(AFILES))

$(TARGETB):
	$(CXX) $(CFLAGS) -o $(BIN)$(TARGETB) -I $(LIB) $(addprefix $(LIB), $(LIBFILES)) $(addprefix $(SRC), $(BFILES))


# make the data files

data: $(TARGET)
	cd $(BIN); ./$(TARGET)
