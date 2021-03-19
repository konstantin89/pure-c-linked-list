#define CATCH_CONFIG_MAIN
#include "ext/catch.hpp"

#include "linked_list.h"

struct mystruct {
    int data;
    struct list_head mylist;
};

TEST_CASE("Basic - list_for_each_entry single element", "[linked_list, basic]") 
{
    LIST_HEAD(mylinkedlist);

    struct mystruct first;

    first.data = 10;
    INIT_LIST_HEAD(&first.mylist);

    list_add(&first.mylist, &mylinkedlist);

    int counter = 0;

    struct mystruct  *datastructureptr = NULL;

    list_for_each_entry(datastructureptr, &mylinkedlist, mylist)
    {
        REQUIRE(datastructureptr->data == 10);
        counter++;
    }

    REQUIRE(counter == 1);
}

TEST_CASE("Basic - list_for_each_entry two element", "[linked_list, basic]")
{
    LIST_HEAD(mylinkedlist);

    struct mystruct first;

    first.data = 0;
    INIT_LIST_HEAD(&first.mylist);


    struct mystruct second;

    second.data = 1;
    INIT_LIST_HEAD(&second.mylist);


    list_add(&first.mylist, &mylinkedlist);
    list_add(&second.mylist, &mylinkedlist);

    int counter = 0;

    struct mystruct  *datastructureptr = NULL;

    list_for_each_entry(datastructureptr, &mylinkedlist, mylist)
    {
        counter++;
    }

    REQUIRE(counter == 2);
}