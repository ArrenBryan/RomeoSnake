#ifndef QUEUESTACK_h
#define QUEUESTACK_h

#include <stdio.h>
#include <stdlib.h>
#include "utility.hpp"
#include "tree.hpp"

typedef struct NodeQueue
{
	struct NodeQueue *next;
	struct NodeTree *object;
} NodeQueue;

typedef struct Queue
{
	NodeQueue *root;
} Queue;

/**
 * Initialize new NodeQueue. [Constuctor]
 * @return NodeQueue instance.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
NodeQueue *NodeQueue__create(NodeTree *object);

/**
 * Initialize new Queue. [Constuctor]
 * @return Queue instance.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
Queue *Queue__create();

/**
 * Push / add Node to Queue.
 * @param q Queue instance.
 * @param newNode A node that will be added.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
void Queue__pushNode(Queue *q, NodeQueue *newNode);

/**
 * Pop / delete Node from Queue.
 * @param q Queue instance.
 * @return NodeQueue instance.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
NodeQueue *Queue__popNode(Queue *q);

/**
 * Checking if the queue is empty or not.
 * @param q Queue instance.
 * @return TRUE if the queue is empty and FALSE if the queue is'nt empty.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
bool Queue__isEmpty(Queue *q);

/* =============================================================================================== */

typedef struct Stack
{
	NodeQueue *root;
} Stack;

/**
 * Initialize new Stack. [Constuctor]
 * @return Stack instance.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
Stack *Stack__create();

/**
 * Add Node to Stack.
 * @param s Stack instance.
 * @param newNode A node that will be added.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
void Stack__addNode(Stack *s, NodeQueue *newNode);

/**
 * Display stack.
 * @param s Stack instance.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
void Stack__display(Stack *s);

/**
 * Get top Node in stack.
 * @param s Stack instance.
 * @return NodeQueue instance.
 *
 * Author:	Heldi Apriadi (191511015)
 */
NodeQueue Stack__getTop(Stack *s);

/**
 * pop / delate Node from stack.
 * @param s Stack instance.
 *
 * Author:	Heldi Apriadi (191511015)
 */
void Stack__pop(Stack *s);

/**
 * Reverse stack.
 * @param s Stack instance.
 * @return Reversed Stack instance.
 *
 * Author:	Bryan Azriel Parulian (191511008)
 */
Stack *Stack__reverse(Stack *s);

#endif
