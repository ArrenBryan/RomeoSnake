#ifndef TREE_h
#define TREE_h

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include "utility.hpp"

typedef Point valuetype;			// The typedata of value's node.

/**
 * A node that holds value, connector to parent, first son and next brother.
 */
typedef struct NodeTree {
	valuetype value;				// The value of the node.
	struct NodeTree *parent;		// Connector to parent.
} NodeTree;

typedef struct Tree {
	NodeTree *root;					// The root of this Tree.
} Tree;

/**
 * Initialize new Tree. [Constuctor]
 * @return Tree instance.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
Tree *Tree__create ();

/**
 * Checking if the tree is empty or not.
 * @param t Tree instance.
 * @return TRUE if the tree is empty and FALSE if the tree is'nt empty.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
bool Tree__isEmpty (Tree *t);

/**
 * Initialize new NodeTree. [Constuctor]
 * @param coord coordinates that will be stored to value.
 * @return NodeTree instance.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
NodeTree *NodeTree__create(Point *coord);

/**
 * Adding / Insert a Node to Tree.
 * @param t Tree instance.
 * @param newNode A node that will be added.
 * @param parentNode parent's address that will be connected with newNode. 
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
void Tree__addNode (Tree *t, NodeTree *newNode, NodeTree *parentNode);

#endif
