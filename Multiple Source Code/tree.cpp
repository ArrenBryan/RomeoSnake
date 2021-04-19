#include "tree.hpp"

Tree *Tree__create () {
	Tree *t = (Tree*) malloc (sizeof(Tree));
	if (t == NULL) {
		printf ("Allocation Error!\n");
		exit(0);
	}
	
	t->root = NULL;
	return t;
}

bool Tree__isEmpty (Tree *t) {
	return (t->root == NULL);
}

NodeTree *NodeTree__create(Point *coord)
{
	NodeTree *newNode = (NodeTree*) malloc (sizeof(NodeTree));
	
	if (newNode == NULL)
    {
        printf("Allocation Error!");
        exit(1);
    }

    newNode->value.coorX = coord->coorX;
    newNode->value.coorY = coord->coorY;
	newNode->parent = NULL;
	
    return newNode;
}

void Tree__addNode (Tree *t, NodeTree *newNode, NodeTree *parentNode) {	
	if (Tree__isEmpty (t) == true) {
		newNode->parent = NULL;
		t->root = newNode;
		return;
	}
	
	newNode->parent = parentNode;
}
