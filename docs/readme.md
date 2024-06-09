# Doubly LinkedList Implementation in C++

This C++ project provides an implementation of a doubly linked list data structure. The LinkedList class allows users to perform basic operations on a linked list of Employees, such as insertion, deletion, traversal, and retrieval of nodes.

## Features

- **Addition**: Add a node at the head or tail of the list, or after a Retrieved node.
    - addNodeAtHead(Employee employee);
    - addNodeAtTail(Employee employee);
    - addAfterNode(Node* addAfterNode, Employee employee);
- **Deletion**: Remove a node from the list.
    - deleteNode(Node* nodeToDelete);
- **Traversal**: Traverse the list in both forward and backward directions.
    - traverseForward();
    - traverseBackward();
- **Retrieval**: Get a node from the list by ordinal position.
    - getNodeAtOrdinalPosition(int position);

## Usage

```cpp
#include "LinkedList.h"
#include <iostream>

int main() {
    LinkedList list;

    // Add nodes
    list.addNodeAtHead(Employee(1, "John Doe"));
    list.addNodeAtTail(Employee(2, "Jane Smith"));
    list.addAfterNode(list.getNodeAtOrdinalPosition(0), Employee(3, "Alice Johnson"));

    // Traverse the list
    list.traverseForward();
    list.traverseBackward();

    // Delete a node
    list.deleteNode(list.getNodeAtOrdinalPosition(1));

    // Traverse the modified list
    list.traverseForward();
    list.traverseBackward();

    return 0;
}
```

