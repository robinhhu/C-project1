#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "treestructure.h"
#include "buildtree.h"
#include "writetree.h"
#include "destorytree.h"
#include "removechildren.h"
#include "nodeValue.h"

int main( int argc, char **argv ) {

  Node *head;

  // make the head node
  head = makeNode( 0.0,0.0, 0 );

  // grow the tree
  growtree( head );
  growtree( head );

  // add node value to each node, modify the tree depend on the value
  // and print out the number of nodes added and removed.
  printout( head );

  // remove the children
  removeChildren( head->child[1]);

  // print the tree for Gnuplot
  writeTree( head );

  // delete the tree and free the nodes
  destoryTree(head);

  return 0;
}
