#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "treestructure.h"
#include "buildtree.h"
#include "writetree.h"
#include "destorytree.h"
#include "removechildren.h"

int main( int argc, char **argv ) {

  Node *head;

  // make the head node
  head = makeNode( 0.0,0.0, 0 );

  // grow the tree
  growtree( head );
  growtree( head );

  // remove the children
  removeChildren( head->child[1]);

  // print the tree for Gnuplot
  writeTree( head );

  // delete the tree and free the nodes
  destoryTree(head);

  return 0;
}
