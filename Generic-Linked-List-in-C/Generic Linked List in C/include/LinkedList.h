#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

#include "stdbool.h"

struct LINKEDLIST{

    Node head;
    int size;
    size_t dataSize;

    void(*printFunc)(const void*);

    bool (*isEmpty)(struct LINKEDLIST*);
    int (*count)(struct LINKEDLIST*);
    const void *(*first)(struct LINKEDLIST*);
    const void *(*last)(struct LINKEDLIST*);
    void (*add)(void *data, struct LINKEDLIST*);
    void (*insert)(int index, const void *data, struct LINKEDLIST*);
    void (*removeAtByData)(const void *data, struct LINKEDLIST*);
    void (*removeAt)(int index, struct LINKEDLIST*);
    int (*indexOf)(const void *data, struct LINKEDLIST*);
    bool (*find)(const void *data, struct LINKEDLIST*);
    void (*reverse)(struct LINKEDLIST*);
    void (*clear)(struct LINKEDLIST*);
    void (*delete_LinkedList)(struct LINKEDLIST*);
};
typedef struct LINKEDLIST* LinkedList;

LinkedList new_LinkedList(size_t dataSize,void(*printFunc)(const void*));
bool isEmpty(LinkedList);
int count(LinkedList);
const void *first(LinkedList);
const void *last(LinkedList);
void add(void *data, LinkedList);
void insert(int index, const void *data, LinkedList);
void removeAtByData(const void *data, LinkedList);
void removeAt(int index, LinkedList);
int indexOf(const void *data, LinkedList);
bool find(const void *data, LinkedList);
void reverse(LinkedList);
void clear(LinkedList);
void delete_LinkedList(LinkedList);

#endif