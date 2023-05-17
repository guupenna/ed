#ifndef NODE_H
#define NODE_H

typedef int data_type;

typedef struct Node
{
    data_type data;
    struct Node *next;
} Node;

Node * node_construct(data_type data, Node *next);

void node_destroy(Node *n);

#endif