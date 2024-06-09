#include "include/LinkedList.h"
#include "include/Employee.h"
#include <iostream>

int main()
{
    LinkedList list;

    list.traverseForward(); //empty

    list.addNodeAtHead(Employee(8888,"Test Employee8"));
    list.addNodeAtHead(Employee(7777,"Test Employee7"));
    list.addNodeAtHead(Employee(5555,"Test Employee5"));
    list.traverseForward(); //emp5, emp7, emp8

    list.addNodeAtTail(Employee(9999,"Test Employee9"));
    list.traverseForward(); //emp5, emp7, emp8, emp9

    Node* emp5 = list.getNodeAtOrdinalPosition(0);
    list.addAfterNode(emp5, Employee(6666, "Test Employee6"));
    list.traverseForward(); //emp5, emp6, emp7, emp8, emp9

    Node* emp8 = list.getNodeAtOrdinalPosition(3);
    list.deleteNode(emp8);
    list.traverseForward(); //emp5, emp6, emp7, emp9

    Node* emp9 = list.getNodeAtOrdinalPosition(3);
    list.deleteNode(emp9);
    list.traverseForward(); //emp5, emp6, emp7
    
    list.deleteNode(emp5);
    list.traverseForward(); //emp6, emp7
    
    list.addNodeAtTail(Employee(8888,"Test Employee18"));
    list.addNodeAtTail(Employee(9999,"Test Employee19"));

    list.traverseForward(); //emp6, emp7, emp18, emp19
    list.traverseBackward(); //emp19, emp18, emp7, emp6
    return 0;
}