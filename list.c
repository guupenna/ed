#include <stdio.h>
#include <stdlib.h>

#include "list.h"

List * list_create()
{
    List *l = (List *)malloc(sizeof(List));
    l->head = NULL;
    l->last = NULL;
    l->size = 0;

    return l;
}

void list_push_front(List *l, data_type data)
{
    l->head = node_construct(data, l->head);
    if (l->last == NULL)
    {
        l->last = l->head;
    }
    l->size++;
}

data_type list_get(List *l, int i)
{
    Node *n = l->head;

    for (int cont = 1; cont < i; cont++)
    {
        n = n->next;
    }

    return n->data;
}

int list_size(List *l)
{
    return l->size;
}

data_type list_pop_front(List *l)
{
    Node *n = l->head;

    if (n == NULL)
    {
        printf("Erro: A lista está vazia.\n");
        exit(1);
    }

    l->head = l->head->next;
    l->size--;

    data_type data = n->data;
    node_destroy(n);

    return data;
}

List * list_reverse(List *l)
{
    List *l2 = list_create();
    Node *n = l->head;

    while (n)
    {
        list_push_front(l2, n->data);
        n = n->next;
    }

    return l2;
}

void list_clear(List *l)
{
    while (l->size)
    {
        list_pop_front(l);
    }
}

void list_remove(List *l, data_type data)
{
    Node *n = l->head, *prev = NULL, *curr = NULL;
    
    while (n)
    {
        if (n->data == data)
        {
            if (prev == NULL)
            {
                l->head = curr = n->next;
            } else
            {
                prev->next = curr = n->next;
            }
            l->size--;
            node_destroy(n);
            n = curr;
        } else
        {
            prev = n;
            n = n->next;
        }
    }
}

void list_cat(List *l, List *m)
{
    Node *n = m->head;

    while (n)
    {
        list_push_front(l, n->data);
        n = n->next;
    }
}

void list_push_back(List *l, data_type data)
{
    Node *n = node_construct(data, NULL);

    if (l->last == NULL)
    {
        l->last = l->head = n;
    } else
    {
        l->last = l->last->next = n;
    }

    l->size++;
}

void list_print(List *l, void (*print_fn)(data_type))
{
    Node *n = l->head;

    printf("[");
    while (n) {
        print_fn(n->data);
        n = n->next;
        if (n) printf(", ");
    }
    printf("]\n");
}

void list_destroy(List *l)
{
    Node *n = l->head;

    while (n)
    {
        Node *next = n->next;
        node_destroy(n);
        n = next;
    }
    
    free (l);
}