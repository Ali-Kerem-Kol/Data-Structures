# Array List in C++

This is a simple implementation of an array list in C++. This list allows you to manage collections of any data type, including your own custom data structures. It provides basic operations for manipulating and querying the list.

## Features and Examples

  * Test Code

  ```cpp
#include <iostream>
#include "ArrayList.hpp" // Include your ArrayList library

using namespace std;

int main() {
    // Create an ArrayList instance
    ArrayList<int> list;

    // 1. Element addition tests
    cout << "Element addition tests:\n";
    list.add(10);
    list.add(20);
    list.add(30);
    cout << "List after adding elements: " << list << endl; // Expected output: 10 20 30

    cout << endl;

    // 2. Size tests
    cout << "Size: " << list.size() << endl; // Expected output: 3
    cout << "Capacity: " << list.getCapacity() << endl; // Expected output: 4 (initial capacity is 2, will increase as elements are added)

    cout << endl;

    // 3. First and last element tests
    cout << "First element: " << list.first() << endl; // Expected output: 10
    cout << "Last element: " << list.last() << endl; // Expected output: 30

    cout << endl;

    // 4. Element access test
    cout << "Second element: " << list.elementAt(1) << endl; // Expected output: 20

    cout << endl;

    // 5. Element removal tests
    cout << "Element removal tests:\n";
    list.removeAt(1); // Remove 20
    cout << "List after removing element at index 1: " << list << endl; // Expected output: 10 30

    cout << endl;

    // 6. Element finding test
    cout << "Can we find the number 20? " << (list.find(20) ? "Yes" : "No") << endl; // Expected output: No
    cout << "Can we find the number 10? " << (list.find(10) ? "Yes" : "No") << endl; // Expected output: Yes

    cout << endl;

    // 7. Remove all copies test
    list.add(10); // Add 10 again
    list.add(10); // Add 10 again
    cout << "List before removing all 10s: " << list << endl; // Expected output: 10 30 10 10
    list.removeAll(10); // Remove all 10s
    cout << "List after removing all 10s: " << list << endl; // Expected output: 30

    cout << endl;

    // 8. Clear test
    list.clear();
    cout << "List after clearing: " << list << endl; // Expected output: (empty)

    cout << endl;

    // 9. Iterator test
    cout << "Iterator test:\n";
    list.add(1);
    list.add(2);
    list.add(3);

    cout << "List elements with iterator: ";
    for (ArrayList<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        cout << *it << " "; // Expected output: 1 2 3
    }
    cout << endl;

    cout << endl;

    // 10. Copying and assignment test
    ArrayList<int> list2 = list; // Copying
    cout << "List2 (copied list): " << list2 << endl; // Expected output: 1 2 3

    ArrayList<int> list3;
    list3.add(100);
    cout << "List3 (before assignment): " << list3 << endl; // Expected output: 100
    list3 = list; // Assignment
    cout << "List3 (after assignment): " << list3 << endl; // Expected output: 1 2 3

    cout << endl;

    return 0; // Program finished successfully
}
  ```
