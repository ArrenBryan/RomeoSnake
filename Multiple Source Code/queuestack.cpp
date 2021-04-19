#include "queuestack.hpp"

NodeQueue *NodeQueue__create(NodeTree *object)
{
	NodeQueue *nq = (NodeQueue*)malloc(sizeof(NodeQueue));
	
	if (nq == NULL)
    {
        printf("Allocation Error!");
        exit(1);
    }
    
    nq->next = NULL;
    nq->object = object;
    
    return nq;
}

Queue *Queue__create()
{
    Queue *q = (Queue*) malloc (sizeof(Queue));

    if (q == NULL)
    {
        printf("Allocation Error!");
        exit(1);
    }
    
    q->root = NULL;
    
    return q;
}

void Queue__pushNode(Queue *q, NodeQueue *newNode)
{
	if (q->root == NULL)
	{
		q->root = newNode;
		return;
	}
	
	NodeQueue *currNode = q->root;
	while (currNode->next != NULL)
	{
		currNode = currNode->next;	
	}
	currNode->next = newNode;
}

NodeQueue *Queue__popNode(Queue *q)
{
	NodeQueue *deletedNode;
	deletedNode = q->root;
	
	q->root = q->root->next;
	
	return deletedNode;
}

bool Queue__isEmpty(Queue *q)
{
	if (q->root == NULL)
	{
		return true;
	}
	
	return false;
}

/* =============================================================================================== */

Stack *Stack__create()
{
	Stack *s = (Stack*) malloc (sizeof(Stack));

    if (s == NULL)
    {
        printf("Allocation Error!");
        exit(1);
    }
    
    s->root = NULL;
    
    return s;
}

void Stack__addNode(Stack *s, NodeQueue *newNode)
{
	if (s->root == NULL)
	{
		s->root = newNode;
		newNode->next = NULL;
		return;
	}
	
	newNode->next = s->root;
	s->root = newNode;
}

Stack *Stack__reverse(Stack *s)
{
	Stack *stackReverse = Stack__create();
	NodeQueue* currNode = s->root;
	NodeQueue* newNodeQueue;
	NodeTree * newNodeTree;
	
	while (currNode != NULL)
	{
		NodeTree *newNodeTree = NodeTree__create(&currNode->object->value);
		newNodeQueue = NodeQueue__create(newNodeTree);
		Stack__addNode(stackReverse, newNodeQueue);
		currNode = currNode->next;
	}

	return stackReverse;
}

void Stack__display(Stack *s)
{
	NodeQueue *currNode = s->root;
	while (currNode != NULL)
	{
		printf ("%d  ", currNode->object->value.coorX);
		printf ("%d\n", currNode->object->value.coorY);
		currNode = currNode->next;
	}
}

NodeQueue Stack__getTop(Stack *s)
{
	NodeQueue *currNode = s->root;
	
	return *currNode;
}

void Stack__pop(Stack *s)
{	
	s->root = s->root->next;
}
