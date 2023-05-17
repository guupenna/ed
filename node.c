#include <stdio.h>
#include <stdlib.h>

#include "node.h"

Node * node_construct(data_type data, Node *next)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = next;

    return node;
}

void node_destroy(Node *n)
{
    free(n);
}