#pragma once

#include "Event.h"
#include "FoodOrder.h"

/*
 * CLASS: Node.h
 *
 * Author: Michelle Li
 *
 * REMARKS: Header file for Node.cpp.
 *
 * ---------------------------------------------------------------------------------------
 */

class Node{
private:
    Event* content;
    Node* next;

public:

    Node(Node*, Event*);
    Node* getNext();
    void setNext(Node*);
    Event* getItem();

};
