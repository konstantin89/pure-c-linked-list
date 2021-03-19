# pure-c-linked-list

## Brief
Pure C linked list implimentation.  
The implementation method is the same as in Linux kernel.

## Example App

Example usage app is available in [example/main.c](example/main.c).  


## Unit Tests

Unit tests are implemented in [tests/main.cpp](tests/main.cpp).  
[Catch2](https://github.com/catchorg/Catch2) C++ unit tests framework is used to test the linked list in this repo.  
Catch2 is single header framework that is located in [tests/ext/catch.hpp](tests/ext/catch.hpp).  


## Build Commands

The following commands should be used to compile tests and example binaries:
``` bash
git clone https://github.com/konstantin89/pure-c-linked-list
cd pure-c-linked-list
mkdir build
cd build
cmake ..
make
```

Output artifacts will be located under `pure-c-linked-list/output`



## Build notes
This code can be compiled only with GCC. It will not work on Visual Studio compiler.  
The reason for this is that the [statement expressions](https://gcc.gnu.org/onlinedocs/gcc/Statement-Exprs.html) feature is specific to GCC.


## Links
[Tutorial about linux kernel linked lists](https://medium.com/@414apache/kernel-data-structures-linkedlist-b13e4f8de4bf)


[C offsetof() macro description](https://www.tutorialspoint.com/c_standard_library/c_macro_offsetof.htm)
