#ifndef NODE_H
#define NODE_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct NODE{
    void *data;
    struct NODE* next;
    size_t dataSize;
    void (*delete_Node)(struct NODE*);
};
typedef struct NODE* Node;

Node new_Node(size_t dataSize,void* data,Node next);
void delete_Node(Node);

#endif