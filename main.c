#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "treestructure.h"
#include "buildtree.h"
#include "writetree.h"
#include "destorynode.h"

int main( int argc, char **argv ) {

  Node *head;

  // make the head node
  head = makeNode( 0.0,0.0, 0 );

  // make a tree
  makeChildren( head );

  // grow the tree
  growtree( head );
  growtree( head );
  // print the tree for Gnuplot
  writeTree( head );

  // delete the tree and free the nodes
  destoryNode(head);

  return 0;
}
