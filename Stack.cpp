#include "Stack.h"
#include "Node.h"

/*
 * CLASS: Stack.cpp
 *
 * Author: Michelle Li
 *
 * REMARKS: Implementation for Stack class, implemented with a linked list. Removes by popping the most recent entry of stack.
 * Is a subclass of List.
 *
 * ---------------------------------------------------------------------------------------
 */


Stack::Stack() : List(){
}//constructor

/* ---------------------------------------------------------------------------------------
 *  pop()
 *
 *  PURPOSE: Removes the latest entry (Node) of the list and returns it

 *  RETURNS: The Node that was removed from the List from pop()
 *
 *  ---------------------------------------------------------------------------------------
 */

Node* Stack::pop(){
    Node* out;

    if(top == nullptr) {
        //no items in list
        out = nullptr;
    } else if (top == tail) {
        //one item
        out = tail;
        tail = nullptr;
        top = nullptr;
    } else {
        out = tail;
        tail = tail->getNext();
    }

    return out;
}

Node* Stack::peek() {
    return tail;
} //return most recent insertion
