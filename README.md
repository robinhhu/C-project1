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

Update March 4th, after finishing the tast2. Coding process went pretty well. And the test and demostration had been screenshoted.
The algorism was based on the design decision that we assume all children nodes are leaf nodes. So simply traverse through all the children, free the nodes and then set the pointer to children to NULL.

Also March 4th, finish half of the task3. That is, write a data-dependent tree. The first stage is pretty straight-forward, just do it in a recursive way. The second stage, however, require us to print out the number of nodes added or removed. Since the function is recursive, it's hard to count the result and print it only once. And that's why the idea of pointer comes into places. What I need to do is to pass a pointer as an argument to the function. And print the result out of function later.
