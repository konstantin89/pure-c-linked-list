#ifndef __PURE_C_LINKED_LIST_H
#define __PURE_C_LINKED_LIST_H

#include <stdlib.h>

struct list_head 
{
    struct list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) { &(name), &(name) } 

#define LIST_HEAD(name) \
         struct list_head name = LIST_HEAD_INIT(name)

#define container_of(ptr, type, member) ({ \
         const typeof(((type *)0)->member) *__mptr = (ptr);    \
         (type *)((char *)__mptr - offsetof(type,member)); })

#define list_entry(ptr, type, member) \
         container_of(ptr, type, member)

#define list_for_each(pos, head) \
        for (pos = (head)->next; pos != (head); pos = pos->next)

#define list_for_each_entry(pos, head, member)                           \
         for (pos = list_entry((head)->next, typeof(*pos), member);      \
              &pos->member != (head);                                     \
              pos = list_entry(pos->member.next, typeof(*pos), member))


static inline void INIT_LIST_HEAD(struct list_head *list)
{
    list->next = list;
    list->prev = list;
}

static inline void __list_add(
    struct list_head *new_node,
    struct list_head *prev,
    struct list_head *next)
{
    next->prev = new_node;
    new_node->next = next;
    new_node->prev = prev;
    prev->next = new_node;
}

static inline void  list_add_front(struct list_head *new_node, struct list_head *head)
{
    __list_add(new_node, head, head->next);
}

static inline void list_add_tail(struct list_head *new_node, struct list_head *head)
{
	__list_add(new_node, head->prev, head);
}

#endif