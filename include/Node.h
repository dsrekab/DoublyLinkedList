#ifndef NODE_H
#define NODE_H

#include "Employee.h"

struct Node
{
    Employee data;
    Node* next;
    Node* previous;

    Node(Employee employee);
};

#endif