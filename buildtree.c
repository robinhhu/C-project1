#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "treestructure.h"
#include "buildtree.h"

// make a node at given location (x,y) and level

Node *makeNode( double x, double y, int level ) {

  int i;

  Node *node = (Node *)malloc(sizeof(Node));

  node->level = level;

  node->xy[0] = x;
  node->xy[1] = y;

  for( i=0;i<4;++i )
    node->child[i] = NULL;

  return node;
}

// split a leaf nodes into 4 children

void makeChildren( Node *parent ) {

  double x = parent->xy[0];
  double y = parent->xy[1];

  int level = parent->level;

  double hChild = pow(2.0,-(level+1));

  parent->child[0] = makeNode( x,y, level+1 );
  parent->child[1] = makeNode( x+hChild,y, level+1 );
  parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
  parent->child[3] = makeNode( x,y+hChild, level+1 );

  return;
}

// visit every leaf node and add children

void growtree(Node *node) {
	if (node->child[0] != NULL)
	{
		int i;
		for (i = 0;i < 4;i ++)
			growtree(node->child[i]);
	}
	else
		makeChildren(node);
	return;
}

