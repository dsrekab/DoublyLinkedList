#include "include/LinkedList.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList()
{
    Node* current = head;

    while (current != nullptr)
    {
        Node* next =current->next;
        delete current;
        current = next;
    }
}

void LinkedList::addNodeAtHead(Employee employee)
{
    Node* newNode = new Node(employee);
    
    if (head!=nullptr)
    {
        newNode->next = head;
        head->previous = newNode;
    }

    head=newNode;

    if (tail==nullptr)
    {
        //tail hasn't been set, this must be the first node in the list
        tail=newNode;
    }
}

void LinkedList::addNodeAtTail(Employee employee)
{
    Node* newNode = new Node(employee);
    
    if (tail!=nullptr)
    {
        tail->next = newNode;
        newNode->previous = tail;
    }

    tail=newNode;

    if (head==nullptr)
    {
        //head hasn't been set, this must be the first node in the list
        head=newNode;
    }
}

void LinkedList::addAfterNode(Node* addAfterNode, Employee employee)
{
    Node* newNode = new Node(employee);
    Node* orgNext = addAfterNode->next;

    newNode->next = orgNext;
    newNode->previous = addAfterNode;
    addAfterNode->next = newNode;

    if (orgNext == nullptr)
    {
        //the afterNode was the tail
        tail = newNode;
    }
    else
    {
        orgNext->previous = newNode;
    }
}

void LinkedList::deleteNode(Node* nodeToDelete)
{

    Node* toDeleteNext = nodeToDelete->next;
    Node* toDeletePrevious = nodeToDelete->previous;

    if (toDeleteNext == nullptr)
    {
        //nodeToDelete was the tail
        tail = toDeletePrevious;
    }
    else
    {
        toDeleteNext->previous = toDeletePrevious;
    }
    
    if (toDeletePrevious == nullptr)
    {
        //nodeToDelete was the head
        head = toDeleteNext;
    }
    else
    {
        toDeletePrevious->next = toDeleteNext;
    }
    
    delete nodeToDelete;
}

Node* LinkedList::getNodeAtOrdinalPosition(int ordinalPosition)
{
    int count=0;

    Node* current=head;
    Node* returnNode=nullptr;

    while (current != nullptr)
    {
        if (count==ordinalPosition)
        {
            returnNode=current;
            break;
        }
        current=current->next;
        count++;
    }

    if (returnNode == nullptr && ordinalPosition >= count)
    {
        throw out_of_range("Ordinal position is out of range.");
    }

    return returnNode;
}

void LinkedList::traverseForward()
{
    Node* current = head;

    cout << "H -> ";
    while (current != nullptr)
    {
        cout << current->data.toString();
        
        if (current->next != nullptr) { cout << " <-> ";}
        
        current = current->next;
    }
    cout << " -> T" << endl;
}

void LinkedList::traverseBackward()
{
    Node* current = tail;
    
    cout << "T -> ";

    while (current != nullptr)
    {
        cout << current->data.toString();

        if (current->previous != nullptr) { cout << " <-> ";}

        current = current->previous;
    }

    cout << " -> H" << endl;
}