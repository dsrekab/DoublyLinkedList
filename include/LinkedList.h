#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "Employee.h"

class LinkedList
{
    private:
    Node* head;
    Node* tail;

    public:
    LinkedList();
    ~LinkedList();

    void addNodeAtHead(Employee employee);
    void addNodeAtTail(Employee employee);
    void addAfterNode(Node* addAfterNode, Employee employee);

    Node* getNodeAtOrdinalPosition(int position);

    void deleteNode(Node* nodeToDelete);
    void traverseForward();
    void traverseBackward();
};

#endif