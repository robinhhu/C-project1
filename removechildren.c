#include <stdio.h>
#include <stdlib.h>
#include "treestructure.h"
#include "removechildren.h"

// free the children and set pointer to children to NULL
void removeChildren( Node *parent ) 
{
	int i;

	for(i = 0;i < 4;i ++) 
	{
		free(parent->child[i]);
		parent->child[i] = NULL;
	}

	return;
}
