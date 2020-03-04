
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/basicQuadtree

SRC= main.c buildtree.c writetree.c destorytree.c removechildren.c

# generic build details

CC=      cc
COPT=    -g
CFLAGS= -lm
WALL = -Wall

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) $(WALL) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE) 

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o:  main.c treestructure.h buildtree.h writetree.h destorytree.h
buildtree.o: buildtree.c treestructure.h writetree.h
writetree.o: writetree.c treestructure.h writetree.h
destorytree.o: destorytree.c treestructure.h destorytree.h 
removechildren.o: removechildren.c treestructure.h removechildren.h
