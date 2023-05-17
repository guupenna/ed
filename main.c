
#include <stdio.h>

#include "list.h"

void print_int(data_type data)
{
    printf("%d", data);
}

int main()
{
    int n, val, i;

    List *l = list_create();

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &val);
        list_push_front(l, val);
    }

    List *l2 = list_create();

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &val);
        list_push_back(l2, val);
    }
    // list_cat(l, l2);

    list_print(l, print_int);
    list_print(l2, print_int);

    list_destroy(l);
    list_destroy(l2);

    return 0;
}