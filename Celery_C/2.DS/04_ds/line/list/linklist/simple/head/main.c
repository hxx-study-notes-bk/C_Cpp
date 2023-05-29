#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    list *linklist;
    datatype arr[] = {12, 9, 23, 2, 34, 6, 45};
    int i;
    int err;

    linklist = list_create();
    if (linklist == NULL)
        exit(1);

    for (i = 0; i < sizeof(arr)/sizeof(datatype); i++)
    {
        if(list_order_insert(linklist, &arr[i]))
            exit(1);
    }

    list_display(linklist);

    datatype value;
    err = list_delete_at(linklist, 2, &value);
    if (err)
        exit(1);
    list_display(linklist);
    printf("delete:%d\n", value);

#if 0
    int value = 12;
    list_delete(linklist, &value);
    list_display(linklist);
#endif

    list_destroy(linklist);

    exit(0);
}