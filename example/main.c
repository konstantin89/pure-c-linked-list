#include "linked_list.h"


// https://medium.com/@414apache/kernel-data-structures-linkedlist-b13e4f8de4bf


// https://www.tutorialspoint.com/c_standard_library/c_macro_offsetof.htm




#include <stddef.h>
#include <stdio.h>





#include <stdio.h>
#include <stddef.h>


struct mystruct {
    int data;
    struct list_head *mylist;
};


int main(void)
{

    struct mystruct first = {
     .data = 10,
     .mylist = LIST_HEAD_INIT(first.mylist)
    };

    LIST_HEAD(mylinkedlist);

    list_add(&first.mylist, &mylinkedlist);


    struct list_head *position = NULL;
    struct mystruct  *datastructureptr = NULL;

    list_for_each(position, &mylinkedlist)
    {
        datastructureptr = list_entry(position, struct mystruct, mylist);
        printf("data  =  %d\n", datastructureptr->data);
    }



    //list_for_each_entry(datastructureptr, &mylinkedlist, mylist)
    //{
    //    printf("data  =  %d\n", datastructureptr->data);
    //}

    return 0;
}