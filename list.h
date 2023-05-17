#ifndef LIST_H
#define LIST_H

#include "node.h"

typedef struct
{
    Node *head;
    Node *last;
    int size;
} List;

List * list_create();

// adiciona um item no início da lista
void list_push_front(List *l, data_type data);

// retorna o i-ésimo elemento da lista
data_type list_get(List *l, int i);

int list_size(List *l);

// remove o primeiro elemento
data_type list_pop_front(List *l);

// retorna uma lista contendo o reverso de outra
List * list_reverse(List *l);

// remove todos os nós da lista
void list_clear(List *l);

// remove todas as ocorrências de um valor na lista
void list_remove(List *l, data_type data);

// adiciona os itens da lista m no início da lista l
void list_cat(List *l, List *m);

// adiciona no final da lista
void list_push_back(List *l, data_type data);

void list_print(List *l, void (*print_fn)(data_type));

void list_destroy(List *l);

#endif