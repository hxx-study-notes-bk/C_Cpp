#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list *list_create()
{
    list *me;

    me = malloc(sizeof(*me));
    if (me == NULL)
        return NULL;
    me->next = NULL;
    return me;
}

int list_insert_at(list *me, int i, datatype *data)
{
    int j = 0;
    list *node = me;
    list *newnode;

    if (i < 0)
        return -1;

    while (j < i && node != NULL)
    {
        node = node->next;
        j++;
    }

    if (node != NULL)
    {
        newnode = malloc(sizeof(*newnode));
        if (newnode == NULL)
            return -2;
        newnode->data = *data;

        newnode->next = node->next;
        node->next = newnode;
        return 0;
    }

    return -3;
}
int list_order_insert(list *me, datatype *data)
{
    list *p = me;
    list *q;

    while (p->next != NULL && p->next->data < *data)
        p = p->next;

    q = malloc(sizeof(*q));
    if (q == NULL)
        return -1;

    q->data = *data;
    q->next = p->next;
    p->next = q;

    return 0;
}

int list_delete_at(list *me, int i, datatype *data)
{
    int j = 0;
    list *node = me;
    list *oldnode;

    *data = -1;

    if (i < 0)
        return -1;

    while (j < i && node != NULL)
    {
        node = node->next;
        j++;
    }

    if (node != NULL)
    {
        oldnode = node->next;
        node->next = node->next->next;
        *data = oldnode->data;
        free(oldnode);
        oldnode = NULL;
        return 0;
    }
    else
        return -2;
}
int list_delete(list *me, datatype *data)
{
    list *p = me;
    list *q;

    while (p->next != NULL && p->next->data != *data)
        p = p->next;
    
    if (p->next == NULL)
        return -1;
    else
    {
        q = p->next;
        p->next = p->next->next;
        free(q);
        q = NULL;
    }
}

int list_isempty(list *me)
{
    if (me->next == NULL)
        return 0;
    return 1;
}

void list_display(list *me)
{
    list *node = me->next;
    if (list_isempty(me) == 0)
        return;

    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    return;
}

void list_destroy(list *me)
{
    list *node = me;
    list *next;
    while (node != NULL)
    {
        next = node->next;
        free(node);
        node = next;
    }
    return;
}