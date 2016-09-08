TARGETA = HPSCProject1_a
TARGETB = HPSCProject1_b

CXX = g++
CFLAGS = -std=c++14

SRC = src/
LIB = lib/
BIN = bin/
ROOT = $(shell pwd)
DATA = data/

AFILES = proj1_a.cpp
BFILES = proj1_b.cpp
LIBFILES = Matrix.cpp Vector.cpp

# make the binaries

$(TARGETA):
	$(CXX) $(CFLAGS) -o $(BIN)$(TARGETA) -I $(LIB) $(addprefix $(LIB), $(LIBFILES)) $(addprefix $(SRC), $(AFILES))

$(TARGETB):
	$(CXX) $(CFLAGS) -o $(BIN)$(TARGETB) -I $(LIB) $(addprefix $(LIB), $(LIBFILES)) $(addprefix $(SRC), $(BFILES))


# make the data files

data_a: $(TARGETA)
	cd $(BIN); ./$(TARGETA)

data_b: $(TARGETB)
	cd $(BIN); ./$(TARGETB)

clean:
	rm -f ./$(DATA)a/*
	rm -f ./$(DATA)b/*
	rm -f ./$(BIN)$(TARGETA)
	rm -f ./$(BIN)$(TARGETB)
