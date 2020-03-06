#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "treestructure.h"
#include "buildtree.h"
#include "removechildren.h"
#include "nodeValue.h"

// make a node at given location (x,y) and level

Node *makeNode( double x, double y, int level ) {

  int i;

  Node *node = (Node *)malloc(sizeof(Node));

  node->level = level;
  node->flag = 0;

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
	if (node->child[0] != NULL) {
		int i;
		for (i = 0;i < 4;i ++)
			growtree(node->child[i]);
	}
	else
		makeChildren(node);
	return;
}

// produce a value for every leaf node and set a flag

void flagQuadtree(Node *node) {
	if (node->child[0] != NULL) {
		int i;
		for (i = 0;i < 4;i ++)
			flagQuadtree(node->child[i]);
	}
	else {
		double value = nodeValue(node, 0.0);
		if (value > 0.5)
			node->flag = 1;
		else if (value < -0.5)
			node->flag = -1;
	}
	return;
}
			
// making data-dependent Quadtree

void modifyTree(Node *node, int num[]) {
	int MaxLevel = 6;
	if (node->child[0] != NULL) {
		int i, flagminus;
		flagminus = 0;
		for (i = 0;i < 4;i ++) {
			if (node->child[i]->flag == -1)
				flagminus ++;
		}
		if (flagminus == 4) {
			removeChildren(node);
			num[0] += 4;
		}
		else {
			for (i = 0;i < 4;i ++) {
				modifyTree(node->child[i],num);
			}
		}
	}
	else {
		if (node->flag == 1 && node->level < MaxLevel) {
			makeChildren(node);
			num[1] += 4;
		}
	}
	return;
}

// print out the number of nodes added or removed
void dtdependentTree(Node *head, int num[]) {
	flagQuadtree(head);
	
	modifyTree(head,num);
	
	printf("Added %d nodes, removed %d nodes.\n",num[1],num[0]);
	return;
}

// continue running until no nodes added or removed
void adapt(Node *node) {
	while(1) {
		int num[2];
		num[0] = 0;
		num[1] = 0;
		dtdependentTree(node, num);
		if (num[0] == 0 && num[1] == 0)
			break;
	}

	return;
}
