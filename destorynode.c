#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "treestructure.h"
#include "destorynode.h"


//void destoryNode(Node *head) {
//	if (head -> child[0]) {
//		int i;
//		for(i = 0;i < 4;i ++)
//			destoryNode(head -> child[i]);
//	}
//	else {
//		free(head);
//		head = NULL;
//	}
//	return;
//}

// traverse through all the leaf and free all the nodes
void destoryNode(Node *head) {
	if(head != NULL) {
		int i;
		for(i = 0;i < 4;i ++)
			destoryNode(head -> child[i]);
		free(head);
	}
}
