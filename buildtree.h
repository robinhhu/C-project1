// make a node at given location (x,y) and level
Node *makeNode( double x, double y, int level );

// split a leaf nodes into 4 children
void makeChildren( Node *parent );

// visit every leaf node and add children
void growtree(Node *node);

// produce a value for every leaf node and set a flag
void flagQuadtree(Node *node);

// making data-dependent Quadtree
void modifyTree(Node *node,int num[]);

// print out the number of nodes added or removed
void dtdependentTree(Node *head,int num[]);

// continue running until no nodes added or removed
void adapt(Node *node);
