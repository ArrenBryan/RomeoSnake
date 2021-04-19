#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/**
 * A node that holds value, the next node and the prev node.
 */
typedef struct Node
{
    void *value;		// The value of the node. Ref: http://web.eecs.utk.edu/~bvanderz/cs365/notes/generic-types.html
    struct Node *next;	// The next node.
    struct Node *prev;	// The prev node.
} Node;

/**
 * A doubly linked list.
 */
typedef struct LinkedList
{
    Node *head;	// The head of this linked list.
    Node *tail;	// The tail of this linked list.
    int size;   // [Read-only] LinkedList size.
} LinkedList;

/**
 * Initialize new Node. [Constuctor]
 * @param value Node value.
 * @return Node instance.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
Node *Node__create(void *value);

/**
 * Initialize new LinkedList. [Constuctor]
 * @return LinkedList instance.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
LinkedList *LinkedList__create();

/**
 * Add node to linked list.
 * @param ll LinkedList instance.
 * @param newNode A node that will be added.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
void LinkedList__addNode(LinkedList *l, Node *newNode);

#endif
