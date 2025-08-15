#include "LinkedList.h"
#include <stdio.h>
#include <string.h>

typedef struct{
    char name[50];
    int age;
} Person;

void printPerson(const void* data){
    Person* person = (Person*)data;
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

int main(){

    // Create a new linked list for Person structs
    LinkedList list = new_LinkedList(sizeof(Person), printPerson);

    // Create some Person instances
    Person person1 = {"Alice", 30};
    Person person2 = {"Bob", 25};
    Person person3 = {"Charlie", 35};
    Person person4 = {"Daisy", 28};
    Person person5 = {"Eve", 22};

    // Test add function
    list->add(&person1, list);
    list->add(&person2, list);
    list->add(&person3, list);

    // Test isEmpty function
    printf("List is empty: %d\n", list->isEmpty(list));

    // Test count function
    printf("List count: %d\n", list->count(list));

    // Test first function
    printf("First element: ");
    list->printFunc(list->first(list));

    // Test last function
    printf("Last element: ");
    list->printFunc(list->last(list));

    // Test insert function
    list->insert(1, &person4, list);
    printf("List after inserting at index 1:\n");
    for (Node itr = list->head; itr != NULL; itr = itr->next){
        list->printFunc(itr->data);
    }

    // Test indexOf function
    int index = list->indexOf(&person3, list);
    printf("Index of Charlie: %d\n", index);

    // Test find function
    printf("Find Charlie: %d\n", list->find(&person3, list));
    printf("Find Eve: %d\n", list->find(&person5, list));

    // Test removeAt function
    list->removeAt(1, list);
    printf("List after removing at index 1:\n");
    for (Node itr = list->head; itr != NULL; itr = itr->next){
        list->printFunc(itr->data);
    }

    // Test removeAtByData function
    list->removeAtByData(&person3, list);
    printf("List after removing Charlie:\n");
    for (Node itr = list->head; itr != NULL; itr = itr->next){
        list->printFunc(itr->data);
    }

    // Test reverse function
    list->reverse(list);
    printf("List after reversing:\n");
    for (Node itr = list->head; itr != NULL; itr = itr->next){
        list->printFunc(itr->data);
    }

    // Test clear function
    list->clear(list);
    printf("List after clearing, is empty: %d\n", list->isEmpty(list));

    // Test delete_LinkedList function
    list->delete_LinkedList(list);
    printf("List deleted\n");

    return 0;
}