# C-project1

Have already completed the Exercise for Lectures 4 & 5 before starting this work.
Commit the initial version with task 1 finished.
valgrind demonstrated that all memory is free after running the algorithm.
The code passed all the tests.

The algorism based on the fact that in order to free all the nodes, the program need to traverse through all the leaf nodes and then the head nodes.
That is, the traversal is required to be performed in a postorder way.

The initial attempt which is still comment in the file "destorynode.c" was the pervious version of the destorynode function.
The initial code was valid but it did not peoduce the expired result. Which means it only deleted the lead nodes but kept those
nodes that had child at the beginning still.
And the main reason the algorism failed was I performed the traversal in a preorder way. So it was hard for me to free the head nodes after
freeing the leaf nodes.
