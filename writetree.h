// write out the tree to file 'quad.out'
void writeTree( Node *head );

// recursively visit the leaf nodes
void writeNode( FILE *fp, Node *node );

// write out the (x,y) corners of the node
void printOut( FILE *fp, Node *node );
