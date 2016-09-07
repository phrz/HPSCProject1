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

clean:
	rm ./$(DATA)*
	rm ./$(BIN)$(TARGETA)
	rm ./$(BIN)$(TARGETB)
