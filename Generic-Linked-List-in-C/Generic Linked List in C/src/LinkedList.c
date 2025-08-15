#include "LinkedList.h"

Node FindPrevByPosition(int position, LinkedList this){
    if (position < 0 || position > this->size){
        printf("%s", "Index out of range");
        return NULL;
    }
    int index = 1;
    for (Node itr = this->head; itr != NULL; itr = itr->next, index++){
        if (position == index){
            return itr;
        }
    }
    return NULL;
}

LinkedList new_LinkedList(size_t dataSize, void (*printFunction)(const void *)){
    LinkedList this;
    this = (LinkedList)malloc(sizeof(struct LINKEDLIST));

    if (this == NULL){
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    this->head = NULL;
    this->size = 0;

    this->dataSize = dataSize;

    this->printFunc = printFunction;

    this->isEmpty = &isEmpty;
    this->count = &count;
    this->first = &first;
    this->last = &last;
    this->add = &add;
    this->insert = &insert;
    this->removeAtByData = &removeAtByData;
    this->removeAt = &removeAt;
    this->indexOf = &indexOf;
    this->find = &find;
    this->reverse = &reverse;
    this->clear = &clear;
    this->delete_LinkedList = &delete_LinkedList;

    return this;
}
bool isEmpty(LinkedList this){
    return this->size == 0;
}
int count(LinkedList this){
    return this->size;
}
const void *first(LinkedList this){
    if (this->isEmpty(this)){
        printf("%s", "Empty List");
        return NULL;
    }

    return this->head->data;
}
const void *last(LinkedList this){
    if (this->isEmpty(this)){
        printf("%s", "Empty List");
        return NULL;
    }

    return FindPrevByPosition(this->size, this)->data;
}
void add(void *data, LinkedList this){
    insert(this->size, data, this);
}
void insert(int index, const void *data, LinkedList this){
    if (index < 0 || index > this->size){
        printf("%s", "Index out of range");
        return;
    }
    if (index == 0){
        this->head = new_Node(this->dataSize, (void *)data, this->head);
    }
    else{
        Node prev = FindPrevByPosition(index, this);
        prev->next = new_Node(this->dataSize, (void *)data, prev->next);
    }
    this->size++;
}
void removeAtByData(const void *data, LinkedList this){
    int index = indexOf(data, this);
    removeAt(index, this);
}
void removeAt(int index, LinkedList this){
    if (this->size == 0){
        printf("%s", "Empty List");
        return;
    }
    
    if (index < 0 || index >= this->size){
        printf("%s", "Index out of range");
        return;
    }
    
    Node del;
    if (index == 0){
        del = this->head;
        this->head = this->head->next;
    }
    else{
        Node prev = FindPrevByPosition(index, this);
        del = prev->next;
        prev->next = prev->next->next;
    }
    del->delete_Node(del);
    this->size--;
}
int indexOf(const void *data, LinkedList this){
    int index = 0;
    for (Node itr = this->head; itr != NULL; itr = itr->next, index++){
        if (memcmp(itr->data, data, this->dataSize) == 0)
            return index;
    }
    printf("Data not found\n");
    return -1;
}

bool find(const void *data, LinkedList this){
    for (Node itr = this->head; itr != NULL; itr = itr->next){
        if (memcmp(itr->data, data, this->dataSize) == 0)
            return true;
    }
    return false;
}
void reverse(LinkedList this){
    Node prev = NULL;
    Node current = this->head;
    Node next = NULL;
    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    this->head = prev;
}
void clear(LinkedList this){
    while (!isEmpty(this)){
        this->removeAt(0, this);
    }
}
void delete_LinkedList(LinkedList this){
    if (this == NULL)
        return;

    this->clear(this);

    free(this);

}
