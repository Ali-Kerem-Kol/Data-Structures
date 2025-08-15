#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

template <typename Object>
struct Node {
    Object data;
    Node<Object> *next;

    Node(const Object& data,Node<Object> *next = NULL) {
        this->data = data;
        this->next = next;
    }
};

template <typename Object>
class LinkedList
{
private:
    Node<Object> *head;
    int size;
    Node<Object>* FindPrevByPosition(int position){
        if(position < 0 || position > size) throw "Index out of range";
        int index = 1;
        for(Node<Object>* itr = head;itr != NULL;itr = itr->next,index++){
            if(position == index) return itr;
        }
        return NULL;
    }
public:
    LinkedList() {
        head = NULL;
        size = 0;
    }
    bool isEmpty()const{
        return size == 0;
    }
    int count(){
        return size;
    }
    const Object& first(){
        if(isEmpty()) throw "Empty List";
        return head->data;
    }
    const Object& last(){
        if(isEmpty()) throw "Empty List";
        return FindPrevByPosition(size)->data;
    }
    void add(const Object& data){
        insert(size,data);
    }
    void insert(int index,const Object& data){
        if(index < 0 || index > size){ 
            throw "Index out of Range";
        }
        if(index == 0){
            head = new Node<Object>(data,head);
        }
        else{
            Node<Object> *prev = FindPrevByPosition(index);
            prev->next = new Node<Object>(data,prev->next);
        }
        size++;
    }
    void remove(const Object& data){
        int index = indexOf(data);
        removeAt(index);
    }
    void removeAt(int index){
        if(size == 0 ) {
           throw "Empty list"; 
        }

        if(index < 0 || index >= size){
            throw "Index out of Range";
        }
        
        Node<Object> *del;
        if(index == 0){
            del = head;
            head = head->next;
        }
        else {
            Node<Object> *prev = FindPrevByPosition(index);
            del = prev->next;
            prev->next = prev->next->next;
        }
        delete del;
        size--;
    }
    int indexOf(const Object& data){
        int index = 0;
        for(Node<Object> *itr = head;itr != NULL;itr = itr->next,index++){
            if(itr->data == data) return index;
        }
        throw "Index out of range";
    }
    bool find(const Object& data){
        for(Node<Object> *itr = head;itr != NULL;itr = itr->next){
            if(itr->data == data) return true;
        }
        return false;
    }
    void reverse(){
        Node<Object> *prev = NULL;
        Node<Object> *current = head;
        Node<Object> *next = NULL;
        while(current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    friend ostream& operator<<(ostream& screen,LinkedList<Object>& right) {
        if(right.isEmpty()){
            screen << "Empty list" << endl;
        }
        else{
            for(Node<Object> *itr = right.head;itr != NULL;itr = itr->next){
                screen << itr->data << " ";
            }
        }
        return screen;
    }
    void clear(){
        while(!isEmpty()) {
            removeAt(0);
        }
    }
    ~LinkedList() {
        clear();
    }
};
#endif
