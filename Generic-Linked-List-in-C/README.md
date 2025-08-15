# Linked List in C

This is a simple implementation of a linked list in C. This list allows you to manage collections of any data type, including your own custom data structures. It provides basic operations for manipulating and querying the list.

## Installation

To use this project, include the 'Node.h', 'Node.c', 'LinkedList.h', and 'LinkedList.c' files in your project. Then, you can run the 'Test.c' file to test the library.

## Features and Examples

  * Create an empty List.

  ```c
  // Example: Create an empty List of Person structures
  LinkedList list = new_LinkedList(sizeof(Person), printPerson);
  ```

  
  * Get the current List state: empty or not empty.

  ```c
  bool isEmpty = list->isEmpty(list);
  ```


  * Get the current size of the List.

  ```cpp
  int size = list->count(list);
  ```


  * Get the first data in the list.

  ```c
  const void* firstData = list->first(list);
  ```


  * Get the last data in the list.

  ```c
  const void* lastData = list->last(list);
  ```


  * Add a New Value to the End of the List.

  ```c
  list->add(&person1, list);
  ```


  * Inserts a value at the specified index. If the list is empty, the value will be added to the beginning.

  ```c
  list->insert(index, &person2, list);
  ```


  * Remove a specific element from the List by its data.

  ```c
  list->removeAtByData(&person3, list);
  ```


  * Remove a specific element from the List by its index.

  ```c
  list->removeAt(2, list);
  ```


  * Get the index of the element from the List by its data.

  ```c
  int index = list->indexOf(&person4, list);
  ```


  * Check if the List Contains a Specific data,returns true if the data is present in the list, otherwise false.

  ```c
  bool contains = list->find(&person5, list);
  ```


  * Reverse the direction of the list.

  ```c
  list->reverse(list);
  ```


  * Clear the List.Removes all elements from the list.

  ```c
  list->clear(list);
  ```


  * Delete the List and free all memory.

  ```c
  list->delete_LinkedList(list);
  ```

## Important Note:

You must implement your own print function for your custom data types. The print function is passed to the "new_LinkedList" function and will be used to display the elements of the list.
