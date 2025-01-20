### Makefile ###
EXE=Example
INC=\

SRC=\
	src/main.cpp\
	src/header.cpp\

CXX=clang++
CXXFLAGS=-g -Iinclude/
LFLAGS=
LDFLAGS=

.SUFFIXES:

all:	$(EXE)

$(INC): $(SRC)

$(EXE):	$(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $@ $(LFLAGS) $(LDFLAGS)

clean:
	rm -f $(EXE)
