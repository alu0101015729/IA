IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g

ODIR=../src
LDIR =../lib

LIBS=-lm

_OBJ = busqueda.o main.o nodo.o map.o car.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: main

$(ODIR)/busqueda.o: $(ODIR)/busqueda.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
	
$(ODIR)/main.o: $(ODIR)/main.cpp $(IDIR)/busqueda.hpp $(IDIR)/map.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/nodo.o: $(ODIR)/nodo.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/map.o: $(ODIR)/map.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/car.o: $(ODIR)/car.cpp
	$(CC) -c -o $@ $< $(CFLAGS)	

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~
