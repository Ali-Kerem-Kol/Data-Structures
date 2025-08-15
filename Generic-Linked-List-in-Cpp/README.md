# Linked List in C++

This is a simple implementation of a linked list in C++. This list allows you to manage collections of any data type, including your own custom data structures. It provides basic operations for manipulating and querying the list.

## Features and Examples

  * Create an empty List.

  ```cpp
  // Example: Create an empty List of strings with the name "names"
  LinkedList<string> *names = new LinkedList<string>();
  ```

  
  * Get the current List state: empty or not empty.

  ```cpp
  bool isEmpty = names->isEmpty();
  ```


  * Get the current size of the List.

  ```cpp
  int size = names->count();
  ```


  * Get the first data in the list.

  ```cpp
  string firstName = names->first();
  ```


  * Get the last data in the list.

  ```cpp
  string lastName = names->last();
  ```


  * Add a New Value to the End of the List.

  ```cpp
  names->add(value);
  ```


  * Inserts a value at the specified index. If the list is empty, the value will be added to the beginning.

  ```cpp
  names->insert(index, value);
  ```


  * Remove a specific element from the List by its data.

  ```cpp
  names->remove(data);
  ```


  * Remove a specific element from the List by its index.

  ```cpp
  names->removeAt(2);
  ```


  * Get the index of the element from the List by its data.

  ```cpp
  int index = names->indexOf(data);
  ```


  * Check if the List Contains a Specific data,returns true if the data is present in the list, otherwise false.

  ```cpp
  bool contains = names->find(data);
  ```


  * Reverse the direction of the list.

  ```cpp
  names->reverse();
  ```


  * Clear the List.Removes all elements from the list.

  ```cpp
  names->clear();
  ```


  * Output the List to Standard Output.

  ```cpp
  #include <iostream>
  std::cout << *names << std::endl; // Will output the list elements separated by spaces
  ```
