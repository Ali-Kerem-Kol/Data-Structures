#include "Node.h"

Node new_Node(size_t dataSize,void* data,Node next){
    Node this;
    this = (Node)malloc(sizeof(struct NODE));

    if (this == NULL){
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    this->dataSize = dataSize;
    this->data = malloc(dataSize);

    if (this->data == NULL){
        perror("Failed to allocate memory");
        free(this);
        exit(EXIT_FAILURE);
    }

    memcpy(this->data,data,dataSize);
    this->next = next;

    this->delete_Node = &delete_Node;

    return this;
}

void delete_Node(Node this){
    if(this == NULL) return;
    free(this->data);
    free(this);
}