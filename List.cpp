#include "List.h"

/*
 * CLASS: List.cpp
 *
 * Author: Michelle Li
 *
 * REMARKS: Implementation file for List class. Contains fields such as top and tail for all Linked List implementations of Queue, Stack,
 * and PriorityLists that are subclasses of List. Also contains the insert method as all insertions for these implementations are the same.
 *
 * ---------------------------------------------------------------------------------------
 */

List::List(){
    top = nullptr;
    tail = nullptr;
} //constructor for all lists and it's subclasses all do superclass constructor calls

/* ---------------------------------------------------------------------------------------
 *  Insert(Event*)
 *
 *  PURPOSE: Insert a new Node holding an Event in it into the List (Used for All subclasses except priority queues)
 *  PARAMETERS:
 *  Event * order - The event that is the order of food that will be added into the List

 *  ---------------------------------------------------------------------------------------
 */

void List::insert(Event * order){
    Node *newNode = new Node(nullptr, order);

    if(top == nullptr){ //first item
        top = newNode;
        tail = top;

    } else {
        newNode->setNext(tail);
        tail = newNode;

    }

}

//peek at Node at the top of the List without discarding top
Node* List::peek(){
    return top;
}

//print method for list used to test implementations (not used in the final submission of assignment)
void List::print(){
    Node *curr = tail;

    while(curr != nullptr){
        cout << curr->getItem() << endl;
        curr = curr->getNext();
    }
}
