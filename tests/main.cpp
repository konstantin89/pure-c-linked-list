#define CATCH_CONFIG_MAIN
#include "ext/catch.hpp"

#include <iostream>
#include <vector>

#include "linked_list.h"

struct mystruct {
    int data;
    struct list_head mylist;
};

TEST_CASE("list_add_front - two elements", "[linked_list, basic]")
{
    LIST_HEAD(mylinkedlist);

    constexpr int DATA_VALUE = 5;
    constexpr int NUMBER_OF_LINKED_LIST_ELEMENTS = 2;

    struct mystruct first;

    first.data = DATA_VALUE;
    INIT_LIST_HEAD(&first.mylist);


    struct mystruct second;

    second.data = DATA_VALUE;
    INIT_LIST_HEAD(&second.mylist);


    list_add_front(&first.mylist, &mylinkedlist);
    list_add_front(&second.mylist, &mylinkedlist);

    int counter = 0;

    struct mystruct* structPtr = NULL;

    list_for_each_entry(structPtr, &mylinkedlist, mylist)
    {
        CHECK(structPtr->data == DATA_VALUE);
        counter++;
    }

    CHECK(counter == NUMBER_OF_LINKED_LIST_ELEMENTS);
}


TEST_CASE("list_add_tail - many elements", "[linked_list, basic]")
{
    LIST_HEAD(mylinkedlist);

    constexpr int DATA_VALUE = 10;
    constexpr int NUMBER_OF_LINKED_LIST_ELEMENTS = 100;

    std::vector<struct mystruct*> structPointers = {};

    // Fill the linked list with values
    for(int i=0; i<NUMBER_OF_LINKED_LIST_ELEMENTS; i++)
    {
        struct mystruct* element = (mystruct*)malloc(sizeof(mystruct));

        REQUIRE(element != NULL);

        element->data = i;
        INIT_LIST_HEAD(&element->mylist);
        list_add_tail(&element->mylist, &mylinkedlist);

        structPointers.push_back(element);
    }

    int elements_counter = 0;

    struct mystruct  *datastructureptr = NULL;

    // Iterate over the linked list. Count elements and check data.
    list_for_each_entry(datastructureptr, &mylinkedlist, mylist)
    {
        CHECK(datastructureptr->data == elements_counter);
        elements_counter++;
    }

    CHECK(elements_counter == NUMBER_OF_LINKED_LIST_ELEMENTS);

    // Clean data
    for(auto structPointer : structPointers)
    {
        free(structPointer);
    }
}