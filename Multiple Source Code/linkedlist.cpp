#include "linkedlist.hpp"

Node *Node__create(void *value)
{
	Node *n = (Node *)malloc(sizeof(Node));
	
	if (n == NULL)
    {
        printf("Allocation Error!");
        exit(1);
    }
    
	n->value = value;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

LinkedList *LinkedList__create()
{
    LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList));

    if (l == NULL)
    {
        printf("Allocation Error!");
        exit(1);
    }

    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    
    return l;
}

void LinkedList__addNode(LinkedList *l, Node *newNode)
{
    if (l->head == NULL)
    {
    	l->head = newNode;
    	l->tail = newNode;
	}
	else
	{
	    newNode->prev = l->tail;
	    l->tail->next = newNode;
		l->tail = newNode;
	}
}
