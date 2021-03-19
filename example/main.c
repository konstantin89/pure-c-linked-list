#include "linked_list.h"


#include <stdio.h>
#include <stddef.h>


struct mystruct {
    int data;
    struct list_head mylist;
};


int main(void)
{
    LIST_HEAD(mylinkedlist);


    struct mystruct first;
    struct mystruct second;

    first.data = 10;
    INIT_LIST_HEAD(&first.mylist);

    second.data = 20;
    INIT_LIST_HEAD(&second.mylist);

    list_add_front(&first.mylist, &mylinkedlist);
    list_add_front(&second.mylist, &mylinkedlist);


    struct list_head *position = NULL;
    struct mystruct  *datastructureptr = NULL;

    list_for_each(position, &mylinkedlist)
    {
        datastructureptr = list_entry(position, struct mystruct, mylist);
        printf("list_for_each: data  =  %d\n", datastructureptr->data);
    }

    list_for_each_entry(datastructureptr, &mylinkedlist, mylist)
    {
        printf("list_for_each_entry: data  =  %d\n", datastructureptr->data);
    }

    return 0;
}