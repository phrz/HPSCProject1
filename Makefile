#
#  Makefile
#  HPSCProject1
#
#  Created by Paul Herz on 9/3/16.
#  Copyright © 2016 Paul Herz. All rights reserved.
#

TARGETA = HPSCProject1_a
TARGETB = HPSCProject1_b

CXX = g++
CFLAGS = -std=c++14

SRC = src/
LIB = lib/
BIN = bin/
ROOT = $(shell pwd)/
DATA = data/
NB = notebooks/
RP = reports/

AFILES = proj1_a.cpp
BFILES = proj1_b.cpp
LIBFILES = Matrix.cpp Vector.cpp

NOTEBOOK_A = $(NB)proj1_a.ipynb
NOTEBOOK_B = $(NB)proj1_b.ipynb

REPORT_A = $(RP)proj1_a.pdf
REPORT_B = $(RP)proj1_b.pdf



################################
# All target                   #
################################

all: all_bin all_data all_reports



################################
# Application binaries         #
################################

all_bin: $(TARGETA) $(TARGETB)

$(TARGETA):
	$(CXX) $(CFLAGS) -o $(BIN)$(TARGETA) -I $(LIB) $(addprefix $(LIB), $(LIBFILES)) $(addprefix $(SRC), $(AFILES))

$(TARGETB):
	$(CXX) $(CFLAGS) -o $(BIN)$(TARGETB) -I $(LIB) $(addprefix $(LIB), $(LIBFILES)) $(addprefix $(SRC), $(BFILES))



################################
# Data files                   #
################################

all_data: data_a data_b

data_a: $(TARGETA)
	cd $(BIN); ./$(TARGETA)

data_b: $(TARGETB)
	cd $(BIN); ./$(TARGETB)



################################
# Reports                      #
################################

all_reports: $(REPORT_A) $(REPORT_B)

$(REPORT_A): data_a $(NOTEBOOK_A)
	jupyter nbconvert --to pdf --execute $(NOTEBOOK_A) --output-dir $(ROOT)$(RP)

$(REPORT_B): data_b $(NOTEBOOK_B)
	jupyter nbconvert --to pdf --execute $(NOTEBOOK_B) --output-dir $(ROOT)$(RP)



################################
# Miscellaneous                #
################################

clean:
	rm -f ./$(DATA)a/*
	rm -f ./$(DATA)b/*
	rm -f ./$(BIN)$(TARGETA)
	rm -f ./$(BIN)$(TARGETB)
	rm -f ./$(RP)*.pdf
	rm -f ./$(NB)*.nbconvert.ipynb


