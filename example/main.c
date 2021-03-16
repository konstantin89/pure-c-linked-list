#include "linked_list.h"


// https://medium.com/@414apache/kernel-data-structures-linkedlist-b13e4f8de4bf


// https://www.tutorialspoint.com/c_standard_library/c_macro_offsetof.htm



#define FOO(RESULT) (RESULT = 2)

#include <stddef.h>

#include <stdio.h>


//gcc 7.4.0



#include  <stdio.h>
#include <stddef.h>

#define container_of(ptr, type, member) ({ \
         const typeof(((type *)0)->member) *__mptr = (ptr);    \
         (type *)((char *)__mptr - offsetof(type,member)); })

struct s
{
    int x;
    int y;
    int z;
};


int main(void)
{
    struct s str;
    str.x = 1;
    str.y = 2;
    str.z = 3;

    int *ptr = &str.x;

    struct s* ptr2 = container_of(ptr, struct s, x);

    printf("Hello, world! %d \n", ptr2->z);
    return 0;
}