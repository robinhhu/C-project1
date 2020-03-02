
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/basicQuadtree

SRC= main.c buildtree.c writetree.c destorynode.c

# generic build details

CC=      cc
COPT=    -g
CFLAGS= -lm

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE) 

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o:  main.c treestructure.h buildtree.h writetree.h destorynode.h
buildtree.o: buildtree.c treestructure.h writetree.h
writetree.o: writetree.c treestructure.h writetree.h
destorynode.o: destorynode.c treestructure.h destorynode.h 

