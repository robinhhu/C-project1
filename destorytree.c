#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "treestructure.h"
#include "destorytree.h"

// traverse through all the leaf and free all the nodes
void destoryTree(Node *head) 
{
	if(head != NULL) 
	{
		int i;
		for(i = 0;i < 4;i ++)
			destoryTree(head -> child[i]);
		free(head);
	}
}
